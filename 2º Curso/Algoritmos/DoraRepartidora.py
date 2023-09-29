# El programa calcula el tiempo más corto que tienen que esperar los consumidores hasta que les llega su pedido


# Recibir el número de clientes y el id de cada cliente y su distancia
N = int(input())
id = [0] * N; dist = [0] * N
for i in range(N):
    id[i], dist[i] = map(int, input().split())

# Ordenar los clientes de menor a mayor y sumar los tiempos teniendo en cuenta que tiene que pasar por todas las ubicaciones anteriores
dicc = {}
dist_copy = dist[:]
for i in range(N):
    valMin = min(dist_copy)
    dicc[valMin] = dist.index(valMin)
    dist_copy.remove(valMin)
listOrd = list(dicc.keys())     # Creo una lista con las claves

# Contar el tiempo multiplicando la cantidad de veces que aparece cada distancia según su posición en la lista
suma = 0
for i in range(N):
    suma += listOrd[i] * (N-i)
print(suma)