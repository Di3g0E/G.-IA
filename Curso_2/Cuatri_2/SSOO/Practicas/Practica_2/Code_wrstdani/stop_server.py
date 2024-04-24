import socket
import json
import time
import random
import string
import threading

class Stop:
    def __init__(self) -> None:
        self.tablero = {
            "Marca" : {
                "word" : "",
                "locked" : False
            },
            "Comida" : {
                "word" : "",
                "locked" : False
            },
            "Lugar" : {
                "word" : "",
                "locked" : False
            },
            "Animal" : {
                "word" : "",
                "locked" : False
            }
        }

        self.letra = random.choice(string.ascii_uppercase)

        self.tablero_completo = False

        

    def fin_partida(self) -> None:
        self.tablero_completo = True
        print("Fin de la partida")

class Partida:
    def __init__(self, duracion=60) -> None:
        self.juego = Stop()
        self.duracion_partida = duracion
        self.jugadores = {}
        self.lider = None

def mostrar_partidas() -> None:
    global reg_partidas
    for id in reg_partidas.keys():
        print(id)



def jugador(clientsocket: socket) -> None:
    global reg_partidas
    # Recibir ID de la partida
    id_partida = clientsocket.recv(1024).decode("utf-8")

    if id_partida == "new":
            id_partida = random.randint(1000, 9999)
            reg_partidas[id_partida] = Partida()
    else:
        id_partida = int(id_partida)

    if id_partida in reg_partidas.keys():
        partida = reg_partidas[id_partida] # Seleccionamos la partida dentro del registro
    else:
        print("LA PARTIDA NO EXISTE")
        return
    print(f"El jugador {nom_jugador} se conecto a la partida {id_partida}")
    mostrar_partidas()

    while True:
        clientsocket.send(bytes(json.dumps(partida.juego.tablero), "utf-8"))
        
        

if __name__ == '__main__':
    reg_partidas = {}

    while True:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((socket.gethostname(), 1234))
        s.listen()

        clientsocket, address = s.accept()
        nom_jugador = clientsocket.recv(10).decode("utf-8")

        clientsocket.send(bytes(f"Te conectaste a STOP! con el usuario {nom_jugador}", "utf-8"))
        if len(reg_partidas) != 0:
            clientsocket.send(bytes(json.dumps(list(reg_partidas.keys())), "utf-8"))
        else:
            clientsocket.send(bytes("empty", "utf-8"))
        j = threading.Thread(target=jugador, args=[clientsocket,]).start()