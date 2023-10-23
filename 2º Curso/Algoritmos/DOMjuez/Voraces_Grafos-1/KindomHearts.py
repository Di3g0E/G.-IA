def mundosVisitados(components, oldId, newId):
    for i in range(len(components)):
        if components[i] == oldId:
            components[i] = newId
    return components

def kruskal(numMundos, edges):
    components = list(range(numMundos))
    cont = numMundos
    enemTotal = 0
    edges.sort()

    i = 0
    while cont > 1 and len(edges) > i:
        numEnem, m1, m2 = edges[i]
        if components[m1] != components[m2]:
            cont -= 1
            enemTotal += numEnem
            mundosVisitados(components, components[m1], components[m2])
        i += 1
    return enemTotal

# Programa Principal:
numMundos, numCarreteras = map(int, input().strip().split())
edges = []
for i in range(numCarreteras):
    m1, m2, numEnem = map(int, input().strip().split())
    edges.append((numEnem, m1, m2))

msk = kruskal(numMundos, edges)
print(msk)