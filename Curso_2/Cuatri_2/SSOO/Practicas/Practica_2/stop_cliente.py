import threading    # Importar el módulo threading para manejar múltiples hilos de ejecución
import socket       # Importar el módulo socket para la comunicación de red
import requests     # Importar el módulo requests para realizar solicitudes HTTP
import json
import time
from collections import Counter     # Importar la clase Counter para contar elementos


def mostrar_tablero(table: dict) -> None:
    print('\n')  # Salto de línea para separar el tablero
    for categ, word in table.items():
        w = word['word']        # Palabra de la categoría
        b = word['locked']      # Estado de bloqueo de la categoría
        f = word['filled_by']   # Quién llenó la categoría
        if b:
            print(f'·{categ} => *{f}* (BLOQUEADA)')             # Si la categoría está bloqueada
        else:
            print(f'·{categ} => *{f}* (DESBLOQUEADA) {w} ')     # Si la categoría no está bloqueada


def tablero_completo(table: dict) -> bool:
    for _, w in table.items():  # Iterar sobre cada categoría en el tablero
        if not w['word']:         # Si la palabra asociada a una categoría está vacía
            return False          # Entonces el tablero no está completo
    return True                   # Si todas las palabras están llenas, el tablero está completo


def mostrar_resultados(table: dict) -> None:
    r = []                          # Lista para almacenar quién llenó cada categoría
    for _, w in table.items():    # Iterar sobre cada categoría en el tablero
        r.append(w['filled_by'])        # Agregar quién llenó la categoría a la lista
    conteo = Counter(r)             # Contar cuántas veces aparece cada jugador en la lista
    print('\n\n')                   # Salto de línea para separar los resultados
    for j, n in conteo.items():     # Iterar sobre los resultados del conteo
        if j == '':                     # Si no hay jugador asociado
            print(f'Hay {n} palabras que nadie ha logrado.')    # Mostrar el número de palabras sin jugador asociado
        else:
            print(f'{j} ha logrado {n} palabras.')              # Mostrar el número de palabras logrado por el jugador


def leer() -> None:
    # Declarar variables globales
    global s
    global tablero
    global letra
    global endgame

    endgame = False                                     # Inicializar la variable de fin de juego como False
    while not endgame:                                  # Bucle para leer continuamente datos hasta que el juego termine
        tablero, letra, msg = json.loads(s.recv(1024).decode())     # Leer datos recibidos y decodificar JSON
        if tablero_completo(tablero):                               # Verificar si el tablero está completo
            print('\n\nPARTIDA FINALIZADA, TABLERO COMPLETO')
            endgame = True                                          # Establecer el fin del juego como True
            mostrar_resultados(tablero)                             # Mostrar resultados finales del juego
        else:
            if not msg:                                             # Si no hay mensaje adicional
                mostrar_tablero(tablero)                                # Mostrar el tablero actual
                print(f'Letra aleatoria: {letra}')                      
            elif msg == 'tiempo_agotado':                       # Si el mensaje indica que el tiempo se ha agotado
                print('\n\nPARTIDA FINALIZADA, TIEMPO AGOTADO')     # Mostrar mensaje de finalización por tiempo agotado
                endgame = True                                      # Establecer el fin del juego como True
                mostrar_resultados(tablero)                         # Mostrar resultados finales del juego


def escribir(name: str) -> None:
    # Declarar variables globales
    global s
    global tablero
    global letra
    global endgame

    while not endgame:      # Bucle para esperar las respuestas del jugador hasta que el juego termine
        time.sleep(.5)          # Esperar medio segundo antes de solicitar la entrada del jugador
        categ = input('Introduce el nombre de una categoría: ')     # Solicitar al jugador el nombre de una categoría
        if endgame:                                                 # Si el juego ha terminado
            break
        while tablero[categ]['locked']:                         # Si la categoría está bloqueada en el tablero
            categ = input('Esa categoría está bloqueada, escoge otra: ')    # Solicitar al jugador otra categoría
            if endgame:                                                     # Si el juego ha terminado
                break
        if endgame:                                             # Si el juego ha terminado
            break

        s.send(categ.encode())  # Enviar el nombre de la categoría al servidor

        palabra = input('Introduce la palabra: ')   # Solicitar al jugador que introduzca una palabra
        if endgame:                                 # Si el juego ha terminado
            break
        while palabra[0] != letra:                  # Si la palabra no comienza con la letra correcta
            palabra = input(f'La palabra debe comenzar por {letra}: ')  # Solicitar al jugador otra palabra
            if endgame:                                                 # Si el juego ha terminado
                break
        if endgame:     # Si el juego ha terminado
            break
        s.send(json.dumps((palabra, name)).encode())    # Enviar la palabra y el nombre del jugador al servidor


if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   # Crear un objeto de socket TCP/IP
    s.connect(("13.53.94.147", 9090))                       # Conectar el socket al servidor y puerto especificados

    nom = input('Introduce tu nombre: ')  # Solicitar al jugador que introduzca su nombre

    s.send(nom.encode())  # Enviar el nombre del jugador al servidor

    id_partida = input('Introduce el ID de la partida o deja en blanco para crear una nueva: ')  # Solicitar al jugador que introduzca el ID de la partida

    if not id_partida:  # Si no se proporciona un ID de partida
        id_partida = requests.get('http://13.53.94.147:8080/stop/new').text  # Obtener nuevo ID de partida del servidor
    else:
        id_partida = requests.get(
            f'http://13.53.94.147:8080/stop/{id_partida}').text     # Obtener ID de partida del servidor con el ID dado

    s.send(id_partida.encode())  # Enviar el ID de partida al servidor

    print(f'Te conectaste a la partida {id_partida}!')

    # Iniciar hilos para la lectura y escritura de datos en paralelo
    hilo_r = threading.Thread(target=leer).start()  
    hilo_w = threading.Thread(target=escribir, args=(nom,)).start()
