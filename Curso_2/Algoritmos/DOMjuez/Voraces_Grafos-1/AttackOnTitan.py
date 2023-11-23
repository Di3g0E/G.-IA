def actualizarId(components, old_id, new_id):
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
        distancia, origen, destino = aristas[i]
        if components[origen] != components[destino]:
            count -= 1
            components = actualizarId(components, components[origen], components[destino])
            mst += distancia
        i += 1

    return mst


# Programa principal:
numPuestos, conexionesPuestos = map(int, input().strip().split())       # Numero de puestos y conexiones entre ellos
puestos = []
for _ in range(conexionesPuestos):                                      # Guardar en la lista de puestos tuplas con la distancia, el origen y el destino de cada conexión por cable
    origen, destino, distancia = map(int, input().strip().split())
    puestos.append((distancia, origen, destino))

mst = kruskal(numPuestos, puestos)                                      # Cálculo de la distancia

if mst % 5 > 0:                                                         # Cálculo del precio total
    mst = (mst // 5) + 1
else: mst = mst // 5
print(mst)
