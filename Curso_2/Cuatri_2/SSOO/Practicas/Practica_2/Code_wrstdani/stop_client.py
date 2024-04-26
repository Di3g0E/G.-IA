import socket
import json
import time

def mostrar_tablero(tablero: dict) -> None:
    print("<<=== Tablero ===>>")
    for idx, tupla_tab in enumerate(tablero.items()):
        if not tupla_tab[1]["locked"]:
            print(f"{idx}.) {tupla_tab[0]} => {tupla_tab[1]['word']}" if tupla_tab[1]['word'] else f"{idx}.) {tupla_tab[0]} => Vacía")
        else:
            print(f"{idx}.) {tupla_tab[0]} (bloqueada) => {tupla_tab[1]['word']}")
    print('\n\n')

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(("13.53.94.147", 2255))

    # Introducir nombre del jugador
    nom_jugador = input('<<=== Introduce tu nombre: ')
    s.sendall(bytes(nom_jugador, "utf-8"))
    print(s.recv(1024).decode("utf-8"))

    # Mostrar partidas disponibles
    print('<<=== Partidas disponibles ===>>')
    reg_partidas = s.recv(1024).decode("utf-8")
    if reg_partidas == 'empty':
        print("NO HAY PARTIDAS DISPONIBLES\n\n")
    else:
        print(json.loads(reg_partidas))
        print('\n\n')

    # ID de la partida
    id_partida = input('<<=== Introduce el identificador de la partida (dejar en blanco para crear una nueva): ')
    if id_partida:
        s.sendall(bytes(id_partida, "utf-8"))
    else:
        s.sendall(bytes("new", "utf-8"))

    while True:
        # Recibir tablero
        tablero = json.loads(s.recv(1024).decode("utf-8"))
        mostrar_tablero(tablero)

        # Elegir categoría
        categ = input('<<=== Elige una categoría (0-3): ')
        while int(categ) not in range(4):
            categ = input('<<=== La categoría es un entero entre 0 y 3: ')
        s.sendall(bytes(categ, "utf-8"))

        # Recibir si la categoría está disponible o no
        flag_categ_bloq = s.recv(1024).decode("utf-8")
        if flag_categ_bloq == '0':
            print('<<=== La categoría está desbloqueada ===>>')
            word = input('<<=== Introduce la palabra: ')
            s.sendall(bytes(word, "utf-8"))