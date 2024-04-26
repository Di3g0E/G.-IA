import socket
import json

def main():
    player_name = input("Ingrese su nombre de jugador: ")
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(("13.53.94.147", 9090))

    s.sendall(bytes(player_name, "utf-8"))

    print(s.recv(1024).decode("utf-8"))

    # Implementa el resto de la lógica del cliente aquí

if __name__ == '__main__':
    main()
