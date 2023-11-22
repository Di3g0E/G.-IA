

def inicializarGrafo():
    return [[1, 1, 1, 1], [1, 1, 0, 0], [1, 0, 1, 1], [1, 0, 1, 1]]



def inicializarSol(grafo):
    return [0] * len(grafo)


def esSol(sol, nodo):
    return nodo == len(sol)


def esFactible(grafo, sol, nodo, color):
    i, factible = 0, True
    while i < nodo and factible:
        if grafo[nodo][i] == 1:         # Son adyacentes
            factible = color != sol[i]  # deben tener colores distintos
        i += 1
    return factible


def colorearGrafoVA(grafo, sol, nodo, m):
    if esSol(sol, nodo):
        print(sol)
    else:
        color = 1
        while color <= m:
            if esFactible(grafo, sol, nodo, color):
                sol[nodo] = color
                colorearGrafoVA(grafo, sol, nodo + 1, m)  # Incrementar el índice del nodo
            color += 1

grafo = inicializarGrafo()
m = 3                           # num de colores disponibles
sol = inicializarSol(grafo)
colorearGrafoVA(grafo, sol, 0, m)
