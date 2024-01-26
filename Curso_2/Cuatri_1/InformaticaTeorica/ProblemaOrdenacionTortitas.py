import random

def lista_desordenada(n):   # Crea una lista con los números enteros desde 0 hasta n-1
    numeros = list(range(1, n+1))
    random.shuffle(numeros) # Desordena la lista aleatoriamente
    return numeros

#######################################################################################################################

def voltear(lista, i):                        # Voltea la lista desde un valor concreto
    return lista[:i][::-1] + lista[i:]

def posicMax(lista, valMax):                  # Devuelve la posicion del valor mas alto
    for i in range(len(lista)):
        if lista[i] == valMax:
            posicion = i
            break
    return posicion

def postVolteo(lista, listaVal, valMax, N):   # Actualiza los valores para seguir ordenando la lista
    posic_Max = posicMax(lista, valMax)
    if posicion_Max == N - 1:
        listaVal.remove(valMax)
        N = len(listaVal)
        valMax = max(listaVal)
        posic_Max = posicMax(lista, valMax)
    return listaVal, valMax, N, posic_Max

def ordenarPila(lista):                       # Algoritmo que ordena las tortitas por tamaño
    listaVal = lista[:]
    valMax = max(listaVal)
    N = len(listaVal)

    posic_Max = posicMax(listaVal, valMax)

    while lista != sorted(lista):
        for i in range(N):
            if posic_Max == 0 and N > 1:
                lista = voltear(lista, N)
                posic_Max = posicMax(lista, valMax)
                if posic_Max == N - 1:
                    listaVal.remove(valMax)
                    N = len(listaVal)
                    valMax = max(listaVal)
                    posic_Max = posicMax(lista, valMax)
                    print(lista)
                    break

            if i < i+1 and N > 2 :
                lista = voltear(lista, i+2)
                posic_Max = posicMax(lista, valMax)
                if posic_Max == N - 1:
                    listaVal.remove(valMax)
                    N = len(listaVal)
                    valMax = max(listaVal)
                    posic_Max = posicMax(lista, valMax)
                print(lista)
    return lista

n = random.randint(1, 15)         # Genera un número aleatorio entre 1 y 15
lista = lista_desordenada(n)      # Crea una lista de tamaño n de núm. desordenados de 1 hasta n.
print(lista, "\n")                # Imprime la lista inicial dejando un espacio con el resto de cambios de la lista
ordenarPila(lista)
