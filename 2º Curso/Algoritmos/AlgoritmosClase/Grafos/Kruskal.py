# Buscar el conjunto de caminos más corto que conecte todos los nodos
def update_components(components, old_id, new_id):  # actualiza el id de los componentes para saber por cuáles has pasado
    for i in range(len(components)):                # el bucle busca el compomente con el mismo valor
        if components[i] == old_id:
            components[i] = new_id                  # cuando lo encuentra le da el nuevo valor para conectar los dos nodos
    return components

def kruskal (n, edges):             # número de nodos y aristas del grafo
    components = list(range(n))     # la lista indica el índice que tiene cada nodo
    count = n                       # hay n componentes
    mst = 0                         # arbol de recubrimiento mínimo con siglas en inglés (coste)
    edges.sort()                    # Ordenar los elementos de la lista de menor a mayor para ordenar los elementos por el conjunto de caminos de menor valor

    i = 0
    while count > 1 and len(edges) > i:             # Mientras el contador de componentes sea mayor que 1 e "i" valga menos que la cantidad de aristas que tenga el arbol se hará lo siguiente
        w, u, v = edges[i]                          # peso, origen y destino de los valores de edges[i]
        if components[u] != components[v]:          # si los id de origen y destino no es el mismo es que no están conectados y hay que conectarlos
            count -= 1                              # Se resta 1 a los componentes que no están conectados
            mst += w                                # Se suma el peso de unión de los nodos a la suma de pesos total
            update_components(components, components[u], components[v]) # Se actualiza el Id de los nodos para saber que ya están conectados
        i += 1                                      # Se avanza una posición en la lista de valores que está ordenada de menor a mayor

    return mst                                      # Devuelve la suma mínima de todos los pesos que conectan los nodos


n, m = map(int, input().strip().split())
edges = []
for _ in range(m):
    w, u, v = map(int, input().strip().split())
    edges.append((w, u, v))

mst = kruskal(n, edges)
print(mst)
