# stop_server4.py

import socket
import json
import time
import random
import string
import threading

class Stop:
    def __init__(self) -> None:
        self.tablero = {
            "Marca" : {"word" : "", "locked" : False},
            "Comida" : {"word" : "", "locked" : False},
            "Lugar" : {"word" : "", "locked" : False},
            "Animal" : {"word" : "", "locked" : False}
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

def jugador(clientsocket: socket, partida_id: int) -> None:
    global reg_partidas
    partida = reg_partidas[partida_id]

    while not partida.juego.tablero_completo:
        clientsocket.send(bytes(json.dumps(partida.juego.tablero), "utf-8"))
        categoria = clientsocket.recv(1024).decode("utf-8")

        if not partida.juego.tablero[categoria]["locked"]:
            partida.juego.tablero[categoria]["locked"] = True
            word = clientsocket.recv(1024).decode("utf-8")
            partida.juego.tablero[categoria]["word"] = word

            for sock in partida.jugadores.values():
                sock.send(bytes(json.dumps(partida.juego.tablero), "utf-8"))
            time.sleep(5)  # Bloquear la categoría durante 5 segundos
            partida.juego.tablero[categoria]["locked"] = False

    print("Fin de la partida")
    clientsocket.close()

def crear_partida() -> None:
    global reg_partidas
    partida_id = random.randint(1000, 9999)
    reg_partidas[partida_id] = Partida()
    return partida_id

if __name__ == '__main__':
    reg_partidas = {}

    print("Servidor conectado")

    while True:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((socket.gethostname(), 9090))
        s.listen()

        clientsocket, address = s.accept()
        nom_jugador = clientsocket.recv(10).decode("utf-8")

        clientsocket.send(bytes(f"Te conectaste a STOP! con el usuario {nom_jugador}", "utf-8"))

        if len(reg_partidas) != 0:
            clientsocket.send(bytes(json.dumps(list(reg_partidas.keys())), "utf-8"))
        else:
            clientsocket.send(bytes("empty", "utf-8"))

        partida_id = clientsocket.recv(1024).decode("utf-8")

        if partida_id.isdigit():
            partida_id = int(partida_id)
            if partida_id not in reg_partidas:
                print("Partida no encontrada")
                clientsocket.close()
                continue
        else:
            partida_id = crear_partida()

        reg_partidas[partida_id].jugadores[nom_jugador] = clientsocket
        clientsocket.send(bytes("Esperando a otros jugadores...", "utf-8"))
        j = threading.Thread(target=jugador, args=[clientsocket, partida_id]).start()