import threading
import time

x = 0
mutex = threading.Lock()

def h():
    global x
    global mutex

    while True:
        mutex.acquire()
        x += 1
        mutex.release()
        
        print(x)
        time.sleep(.5)


def h2():
    global x
    global mutex

    while True:
        mutex.acquire()
        x += 100
        print(x)
        mutex.release()

        time.sleep(3)

        mutex.acquire()
        print("EXLUSION MUTUA")
        time.sleep(3)
        print("permitir...")
        mutex.release()

hilo1 = threading.Thread(target=h)
hilo1.start()

hilo2 = threading.Thread(target=h2)
hilo2.start()