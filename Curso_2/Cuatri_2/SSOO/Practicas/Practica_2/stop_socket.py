import socket

def send_data(data):
    TCP_IP = '13.53.94.147'
    TCP_PORT = 8080
    BUFFER_SIZE = 1024
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((TCP_IP, TCP_PORT))
        s.sendall(data.encode())
        print('Datos enviados:', data)

if __name__ == '__main__':
    animal = input('Animal: ')
    comida = input('Comida: ')
    marca = input('Marca: ')
    lugar = input('Lugar: ')
    
    data = f'{animal},{comida},{marca},{lugar}'
    send_data(data)
