def prim(grafo):                    # Funciona siguiendo los nodos
    num_vertices = len(grafo)
    arbol_expansion_minima = []
    costo_minimo = [float('inf')] * num_vertices
    costo_minimo[0] = 0

    for _ in range(num_vertices):
        u = min((v for v in range(num_vertices) if costo_minimo[v] != 0), key=lambda v: costo_minimo[v])
        costo_minimo[u] = 0

        for v in range(num_vertices):
            if costo_minimo[v] != 0 and grafo[u][v] < costo_minimo[v]:
                costo_minimo[v] = grafo[u][v]
                arbol_expansion_minima.append((u, v, costo_minimo[v]))

    return arbol_expansion_minima


