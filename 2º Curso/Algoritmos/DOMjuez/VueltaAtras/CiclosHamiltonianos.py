def inicializarGrafo():
    return [[0, 1, 0, 1, 1],
            [1, 0, 1, 0, 0],
            [0, 1, 0, 1, 1],
            [1, 0, 1, 0, 1],
            [1, 0, 1, 1, 0]]


def esSol(sol, grafo):
    return len(sol) == len(grafo) and grafo[sol[0]][sol[-1]] == 1


def esFactible(sol, grafo, vertice):
    return (vertice not in sol) and grafo[sol[-1]][vertice] == 1


def ciclosVA(sol, grafo, nodo):
    if esSol(sol, grafo):
        print(sol)
    else:
        vertice = 0
        while vertice < len(grafo):
            if esFactible(sol, grafo, vertice):
                sol.append(vertice)
                ciclosVA(sol, grafo, nodo + 1)
                del sol[-1]
            vertice += 1


grafo = inicializarGrafo()
origen = 0
sol = [origen]
ciclosVA(sol, grafo, 1)