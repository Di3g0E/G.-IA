# Calcula el tiempo de espera mínimo que va a estar trabajando una recepcionista para atender a todos los clientes

def tiemposEsperaMin(tiempoClientes):                       # Algoritmo que calcula el tiempo mínimo
    tiempoClientes.sort()                                   # Ordena la lista de menor a mayor tiempo
    suma = 0                                                # Inicializa la variable que va a guardar el tiempo min. total
    for i in range(numClientes):
        suma += tiempoClientes[i][0] * (numClientes - (i))  # Suma el tiempo de cada cliente teniendo en cuenta que se acumula para los siguientes clientes


# Inputs
numClientes = int(input())                                  # Indicar el número de clientes que están a la espera

tiempoClientes = []                                         # Lista en la que se guardarán la info. de cada cliente
for i in range(numClientes):
    cliente, tiempo = map(int, input().strip().split())     # Indicar el cliente y el tiempo de que tarda
    tiempoClientes.append((tiempo, cliente))                # Guarda la info. de cada cliente en tuplas dentro de la lista

time = tiemposEsperaMin(tiempoClientes)
print(time / numClientes)                                   # Imprime por pantalla el tiempo medio tardado por cliente


"""
Input:
3
1 5
2 10
3 3

Output:
9.67
"""
