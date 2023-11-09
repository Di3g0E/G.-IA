

def inicializar(n):
    return ['o'] * n


def inicializar1(n):
    tablero = []
    for i in range(n):
        tablero.append(['o']*n)
    return tablero


def damaEnColumna(sol, fila, col): # if col in f
    encontrada = False
    f = 0
    while not encontrada and f < fila:
        encontrada = sol[f] == col
        f += 1
    return encontrada


def damaEnDiagonal1(sol, fila, col):
    encontrada = False
    f = 0
    while not encontrada and f < fila:
        encontrada = sol[f] - f == col - fila
        f += 1
    return encontrada


def damaEnDiagonal2(sol, fila, col):
    encontrada = False
    f = 0
    while not encontrada and f < fila:
        encontrada = sol[f] + f == col + fila
        f += 1
    return encontrada


def esFactible(sol, fila, col):
    return not (damaEnColumna(sol, fila, col) or damaEnDiagonal1(sol, fila, col) or damaEnDiagonal2(sol, fila, col))


def nDamas(sol, fila):
    N = len(sol)
    if fila == N:
        esSol = True
    else:
        esSol = False

    col = 0
    while not esSol and col < N:
        if esFactible(sol, fila, col):
            sol[fila] = col
            sol, esSol = nDamas(sol, fila + 1)
        col += 1
    if not esSol:
        sol[fila] = -1

    return sol, esSol


def imprimir(tablero):
    for i in range(len(tablero)):
        for j in range(len(tablero)):
            if tablero[i] == j:
                print("\u2655\t", end ='')
            else:
                print('o\t', end ='')
        print()

def imprimir1(sol):
    N = len(sol)
    tablero = inicializar1(N)
    for f in range(N):
        tablero[f][sol[f]] = "\u2655"
        print(tablero[f])


# Programa Principal:
N = 51   # Tamaño tablero
sol = inicializar(N)
fila = 0
sol, esSol = nDamas(sol, fila)

if esSol: imprimir(sol)
else: print('No se ha encontrado solucion.\n')