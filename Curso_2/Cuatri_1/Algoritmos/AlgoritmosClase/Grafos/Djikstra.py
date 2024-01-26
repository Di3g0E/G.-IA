# Conecta todos los nodos desde un nodo inicial por el camino más rápido

def update_distancia(graph, dicc, new_dist):                    # Actualiza las distancias a los vecinos
        for vecino, weight in graph[new_dist].items():          # Recorre cada conexión con nodos vecinos (si los hay)
            distancia = dicc[new_dist] + weight                 # Calcula la distancia desde ese nodo hasta los vecinos
            if distancia < dicc[vecino]:                        # Si la distancia a sus nodos vecinos hasta A desde su posición es menor a la que tienen actualmente actualiza la distancia
                dicc[vecino] = distancia

def dijkstra(graph, start):
    dist = {node: float('inf') for node in graph}               # Crea un diccionario con los valores de cada nodo igual a infinito, se hace de esta forma porque permite guardar distancias diferentes para direcciones diferentes ((B,D) no tiene por qué ser igual a (D,B))
    dist[start] = 0                                             # Indica que el valor del primer nodo visitado es 0
    visited = []                                                # Crea una lista con los nodos visitados

    while len(visited) < len(graph):                            # Mientras los nodos visitados sean menores que los nodos del grafo
        # Encuentra el nodo no visitado con la distancia mínima
        prox_nodo = None                                        # El próximo nodo a visitar no está definido todavía
        for node in graph:
            if node not in visited:                             # Por cada nodo en el grafo, si el nodo no se ha visitado [...]
                if prox_nodo is None:                           # [...] y el valor de "nodo" es None le damos el valor del nodo que no se ha visitado
                    prox_nodo = node
                elif dist[node] < dist[prox_nodo]:              # Verifica si la distancia calculada para un nodo vecino es menor que la distancia actual almacenada para ese nodo en el diccionario 'dist'.
                    prox_nodo = node                            # Esto es esencial para garantizar que estemos siguiendo la ruta más corta hacia ese nodo.

        visited.append(prox_nodo)                               # Se añade el nuevo nodo a la lista de visitados
        update_distancia(graph, dist, prox_nodo)                # Actualiza las distancias a los vecinos

    return dist


###############################################   Programa Principal    ################################################
graph = {
    'A': {'B': 1, 'C': 3},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}
graph2 = {
    'A': {'B': 1},
    'B': {'A': 1},
    'C': {'D': 1},
    'D': {'C': 1}
}
graph1 = {
    'A': {'B': 1, 'C': 2},
    'B': {'A': 1},
    'C': {'A': 2},
    'D': {'E': 1},
    'E': {'D': 1}
}

nodo_inicial = 'A'
result = dijkstra(graph, nodo_inicial)

for node, distance in result.items():
    if node != nodo_inicial:
        print(f'Distancia desde {nodo_inicial} hasta {node}: {distance}')