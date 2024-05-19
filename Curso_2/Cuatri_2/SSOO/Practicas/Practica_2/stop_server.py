import threading
import socket
import json
import random
import string
import time


class Partida:
    def __init__(self) -> None:
        # Inicialización del tablero con palabras vacías y categorías desbloqueadas
        self.tablero = {
            'Marca': {'word': '', 'locked': False, 'filled_by': ''},
            'Lugar': {'word': '', 'locked': False, 'filled_by': ''},
            'Comida': {'word': '', 'locked': False, 'filled_by': ''},
            'Animal': {'word': '', 'locked': False, 'filled_by': ''}
        }

        # Elección aleatoria de una letra del alfabeto mayúscula
        self.letra = random.choice(string.ascii_uppercase)
            
        # Inicialización de los mutex para cada categoría del tablero
        self.mutex = {
                'Marca': threading.Lock(),
                'Lugar': threading.Lock(),
                'Comida': threading.Lock(),
                'Animal': threading.Lock()
        }

        # Inicialización del diccionario de jugadores vacío
        self.jugadores = {}

        # Inicialización del temporizador para el juego con una duración de 300 segundos (5 minutos)
        self.temporizador = threading.Timer(300, self.temporizador_expirado)

        # Bandera que indica si el juego ha terminado
        self.endgame = False

    def tablero_completo(self) -> bool:
        # Itera sobre cada categoría del tablero
        for _, word in self.tablero.items():
            w = word['word']                    # Obtiene la palabra de la categoría
            if w == '':                         # Si la palabra está vacía
                return False                    # El tablero no está completo
        return True                             # Si todas las palabras están llenas, el tablero está completo

    def enviar_cambio(self, msg: str = '') -> None:
        # Envía los datos actualizados del tablero y la letra a todos los jugadores
        for _, conn_socket in self.jugadores.items():
            conn_socket.send(json.dumps((self.tablero, self.letra, msg)).encode())
        
        # Verifica si el tablero está completo
        if self.tablero_completo():
            self.endgame = True  # Si el tablero está completo, establece la bandera de fin de juego

    def bloq_categ(self, categ: str) -> None:
        self.mutex[categ].acquire()             # Adquiere el cierre para la categoría especificada
        self.tablero[categ]['locked'] = True    # Establece el estado de bloqueo de la categoría en True
        self.enviar_cambio()                    # Envía una actualización a todos los jugadores
        time.sleep(8)                           # Espera 8 segundos durante el tiempo de bloqueo
        self.mutex[categ].release()             # Libera el cierre de la categoría
        self.tablero[categ]['locked'] = False   # Restablece el estado de bloqueo de la categoría en False
        self.enviar_cambio()                    # Envía una actualización a todos los jugadores

    def iniciar_temporizador(self) -> None:
        # Verifica si el temporizador está inactivo
        if not self.temporizador.is_alive():
            self.temporizador.start()   # Inicia el temporizador

    def temporizador_expirado(self) -> None:
        self.enviar_cambio(msg='tiempo_agotado')    # Envia un mensaje de tiempo agotado a todos los jugadores
        self.endgame = True                         # Establece la bandera de fin de juego en True


reg_partidas = {}


def escuchar(connex: socket, partida: Partida, reg_partida: dict, id_partida: str) -> None:
    partida.iniciar_temporizador()      # Comienza el temporizador de la partida
    connex.send(json.dumps((partida.tablero, partida.letra, '')).encode())    # Envía los datos iniciales del tablero y la letra al jugador recién conectado

    while not partida.endgame:          # Mientras el juego no haya terminado
        categ = connex.recv(1024).decode()    # Recibe la categoría seleccionada por el jugador
        if partida.endgame:                 # Si el juego ha terminado, rompe el bucle
            break
        
        threading.Thread(target=partida.bloq_categ, args=(categ,)).start()  # Inicia un hilo para bloquear la categoría seleccionada por el jugador
        p_n = connex.recv(1024).decode()                                      # Recibe la palabra y el nombre del jugador que la eligió

        if partida.endgame:  # Si el juego ha terminado, rompe el bucle
            break

        palabra, name = json.loads(p_n)
        partida.tablero[categ]['word'] = palabra    # Actualiza el tablero con la palabra
        partida.tablero[categ]['filled_by'] = name   # Actualiza el tablero con el nombre del jugador
        partida.enviar_cambio()                     # Envía una actualización del tablero a todos los jugadores

    if id_partida in reg_partida.keys():   # Si la partida está registrada, elimina la partida del registro al finalizar
        del(reg_partida[id_partida])
        print(f"Se elimina la partida {id_partida}\n{reg_partida}")


if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   # Creación de un socket TCP/IP
    s.bind(('0.0.0.0', 9090))                               # Vinculación del socket a la dirección y puerto deseados
    s.listen()                                              # Escucha de conexiones entrantes

    while True:
        conn, addr = s.accept()         # Aceptación de una nueva conexión
        print(f'Conexión de {addr}.')

        nom = conn.recv(10).decode()    # Recepción del nombre del jugador

        id_partidas = conn.recv(4).decode()  # Recepción del identificador de la partida

        if id_partidas not in reg_partidas.keys():   # Verificación y gestión de la partida en el registro de partidas
            reg_partidas[id_partidas] = Partida()

        p = reg_partidas[id_partidas]    # Obtención de la partida correspondiente
        p.jugadores[nom] = conn         # Asignación del socket del jugador a la partida
        print(p.jugadores)

        threading.Thread(target=escuchar, args=(conn, p, reg_partidas, id_partidas,)).start()    # Inicio de un hilo para escuchar los movimientos del jugador en la partida
