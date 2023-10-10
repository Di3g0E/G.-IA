def cambioId(components, old_id, new_id):
    for i in range(len(components)):
        if components[i] == old_id:
            components[i] = new_id
    return components

def kruskal(nodos, aristas):
    components = list(range(nodos))
    count = nodos
    mst = 0
    aristas.sort()

    i = 0
    while count > 1 and len(aristas) > i:

    return mst


# Programa principal:
numHabitaciones, numPasillos = map(int, input().strip().split())
mapa = []
for _ in range(numPasillos):
    origen, destino, coste = map(int, input().strip().split())
    mapa.append((coste, origen, destino))

mst = kruskal(numHabitaciones, mapa)
print(mst)