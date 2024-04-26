# stop_client4.py

import socket
import json
import time

def mostrar_tablero(tablero: dict) -> None:
    print("<<=== Tablero ===>>")
    for idx, (categoria, info) in enumerate(tablero.items()):
        if not info["locked"]:
            print(f"{idx}.) {categoria} => {info['word'] if info['word'] else 'Vacía'}")
        else:
            print(f"{idx}.) {categoria} (bloqueada) => {info['word']}")
    print('\n\n')

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(("13.53.94.147", 9090))

    nom_jugador = input('<<=== Introduce tu nombre: ')
    s.sendall(bytes(nom_jugador, "utf-8"))
    print(s.recv(1024).decode("utf-8"))

    reg_partidas = s.recv(1024).decode("utf-8")
    if reg_partidas == 'empty':
        print("NO HAY PARTIDAS DISPONIBLES\n\n")
    else:
        print("Partidas disponibles:", json.loads(reg_partidas))
        print('\n\n')

    id_partida = input('<<=== Introduce el identificador de la partida (dejar en blanco para crear una nueva): ')
    if id_partida:
        s.sendall(bytes(id_partida, "utf-8"))
    else:
        s.sendall(bytes("new", "utf-8"))

    while True:
        tablero = json.loads(s.recv(1024).decode("utf-8"))
        mostrar_tablero(tablero)

        categoria = input('<<=== Elige una categoría (0-3): ')
        while not categoria.isdigit() or int(categoria) not in range(4):
            categoria = input('<<=== La categoría es un entero entre 0 y 3: ')
        s.sendall(bytes(categoria, "utf-8"))

        mensaje = s.recv(1024).decode("utf-8")
        if mensaje == 'Esperando a otros jugadores...':
            print(mensaje)
            continue

        palabra = input('<<=== Introduce la palabra: ')
        s.sendall(bytes(palabra, "utf-8"))