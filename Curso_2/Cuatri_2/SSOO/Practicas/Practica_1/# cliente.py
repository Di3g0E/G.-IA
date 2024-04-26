# cliente.py

import socket
import time
HOST = "13.53.94.147" # The server's hostname or IP address
PORT = 9090 # The port used by the server
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))

    i=0
    while True:
        s.sendall(str(i).encode())
        i+=1
        time.sleep(2)