import socket
import json
import time

def mostrar_tablero(tablero: dict) -> None:
    for categ, word in tablero.items():
        print(f"{categ} => {word}" if word['word'] else f"{categ} => Vacía")

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((socket.gethostname(), 1234))

    # Introducir nombre del jugador
    nom_jugador = input('Introduce tu nombre: ')
    s.send(bytes(nom_jugador, "utf-8"))
    print(s.recv(1024).decode("utf-8"))

    # Mostrar partidas disponibles
    print('Partidas disponibles:')
    reg_partidas = s.recv(1024).decode("utf-8")
    if reg_partidas == 'empty':
        print("No hay partidas disponibles")
    else:
        print(json.loads(reg_partidas))

    # ID de la partida
    id_partida = input('Introduce el identificador de la partida (dejar en blanco para crear una nueva): ')
    if id_partida:
        s.send(bytes(id_partida, "utf-8"))
    else:
        s.send(bytes("new", "utf-8"))

    # Recibir tablero
    tablero = json.loads(s.recv(1024).decode("utf-8"))
    mostrar_tablero(tablero)
    time.sleep(3600)