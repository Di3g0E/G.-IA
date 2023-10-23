def costes(costeHabitaciones, coste, h1, h2):
    costeHabitaciones[h1] += coste
    costeHabitaciones[h2] += coste
    return costeHabitaciones

def conectarHabitaciones(components, h1, h2):
    for i in range(len(components)):
        if components[i] == h1:
            components[i] = h2
    return components

def kruskalHabitaciones(n, edges):
    components = list(range(n))
    costeHabitacion = [0] * n
    cont = n
    cosTotal = 0
    edges.sort()

    i = 0
    while cont > 1 and i < len(edges):
        d, h1, h2 = edges[i]
        if components[h1] != components[h2]:
            conectarHabitaciones(components, components[h1], components[h2])
            costes(costeHabitacion, d, h1, h2)
            cont -= 1
            cosTotal += d
        i += 1
    return cosTotal, costeHabitacion

# Programa Principal:

N, M = map(int, input().strip().split())
edges = []
for i in range(M):
    h1, h2, d = map(int, input().strip().split())
    edges.append((d, h1, h2))

cosTotal, costHabitacion = kruskalHabitaciones(N, edges)
print("Coste total:",cosTotal)
for i in range(N):
    print(f"H{i}: {costHabitacion[i]}")