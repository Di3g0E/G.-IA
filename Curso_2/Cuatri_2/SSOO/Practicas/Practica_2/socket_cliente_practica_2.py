import socket
import threading

# El host remoto. Sería "localhost" si el cliente está en la misma máquina que el servidor
HOST = "13.53.94.147"

# El puerto en el que está escuchando nuestro servidor
PORT = 50000

def handle_server_response(s):
    while True:
        # Recibir datos del servidor
        data = s.recv(1024)
        if not data:
            print("[Cliente] El servidor ha cerrado la conexión")
            break
        print("[Cliente] Respuesta recibida desde el servidor: {}".format(data.decode('utf-8')))

def start_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((HOST, PORT))

    print('[Cliente] Iniciando socket con el host "{}" al puerto {}'.format(HOST, PORT))

    # Crear un hilo para manejar la respuesta del servidor
    t = threading.Thread(target=handle_server_response, args=(client,))
    t.start()

    while True:
        dato_para_enviar_str = input("[Cliente] Escribe el dato a enviar al servidor: ")

        if dato_para_enviar_str == "cerrar":
            print("[Cliente] Cerrando socket desde cliente")
            client.close()
            break

        client.send(bytes(dato_para_enviar_str, encoding='utf8'))

if __name__ == "__main__":
    start_client()
