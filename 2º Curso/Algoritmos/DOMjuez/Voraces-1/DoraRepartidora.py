# El programa calcula el tiempo más corto que tienen que esperar los consumidores hasta que les llega su pedido

numClientes = int(input())          # Número de clientes
distancias = [0] * numClientes      # Lista distancias clientes
tDistancia = 0                      # Distancia a recorrer
for i in range(numClientes):
    idCliente, distancias[i] = map(int, input().strip().split())
distancias.sort()                   # Ordena la lista de menor a mayor
for i in range(numClientes):
    tDistancia += distancias[i] * (numClientes - i)  # Cálculo de la distancia total a recorrer

print(tDistancia)