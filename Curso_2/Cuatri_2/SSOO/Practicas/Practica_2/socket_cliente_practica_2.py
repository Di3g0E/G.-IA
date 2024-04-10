# El programa cliente que se comunica con el Servidor Software que está escuchando en el Servidor Físico
import socket

# El host remoto. Sería "localhost" si el cliente está en la misma máquina que el servidor
HOST = "13.53.94.147"

# El puerto en el que está escuchando nuestro servidor
PORT = 50000


if __name__ == "__main__":
	print('[Cliente 1] Iniciando socket con el host "{}" al puerto {}'.format(HOST, PORT))
	with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as mi_socket:
		tupla_para_el_enlace = (HOST, PORT)

		print('[Cliente 2] Conectando a: {}'.format(tupla_para_el_enlace))
		mi_socket.connect(tupla_para_el_enlace)

		mantener_el_socket_abierto = True
		while mantener_el_socket_abierto:
			dato_para_enviar_str = input("[Cliente 3] Escribe el dato a enviar al servidor: ")

			if dato_para_enviar_str == "cerrar":
				print("[Cliente 6] Cerrando socket desde cliente")
				break

			mi_socket.sendall(bytes(dato_para_enviar_str, encoding='utf8'))

			print('[Cliente 4] Datos enviados, esperando respuesta del servidor ...')
			dato_recibido_en_bytes = mi_socket.recv(1024).strip()

			dato_recibido_en_str = dato_recibido_en_bytes.decode("utf-8")
			print("[Cliente 5] Respuesta recibida desde el servidor: {}".format(dato_recibido_en_str))

		print("[Cliente 7] Socket cerrado desde cliente")