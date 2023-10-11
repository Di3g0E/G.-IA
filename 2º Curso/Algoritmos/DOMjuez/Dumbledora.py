import copy

"""def coste_habitacion(cost_hab, c, orig, dest):
    cost_hab[orig] += c
    cost_hab[dest] += c"""

def cambioId(components, old_id, new_id):
    for i in range(len(components)):
        if components[i] == old_id:
            components[i] = new_id
    return components

def kruskal(nodos, edges):
    components = list(range(nodos))
    count = nodos
    mst = 0
""" cost_hab = [] * nodos       # creamos una lista para llevar el conteo de los costes de los nodos"""
    edges.sort()
    i = 0
    while count > 1 and len(edges) > i:
        c, o, d, cost_hab = edges[i]
        if components[o] != components[d]:
            count -= 1
            mst += c
"""         coste_habitacion(cost_hab, c, o, d)   # Sumamos los costes a los respectivos nodos"""
            cambioId(components, components[o], components[d])
        i += 1

    return mst, cost_hab


# Programa principal:
numHabitaciones, numPasillos = map(int, input().strip().split())
mapa = []
for _ in range(numPasillos):
    origen, destino, coste = map(int, input().strip().split())
    mapa.append((coste, origen, destino, 0))

mst, coste_habitacion = kruskal(numHabitaciones, mapa)
print(f"Coste total: {mst}")
for i in range(len(coste_habitacion)):
    print(f"H{i}: {coste_habitacion[i][3]}")