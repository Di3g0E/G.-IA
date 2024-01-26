
def inicializar(n):
    return ['o'] * n


def coinciden(sol, fila, col, compara):
    coinciden = False
    i = 0
    while not coinciden and i < fila:
        if compara == 'columna':
            coinciden = sol[i] == col		# Verifica si coinciden damas en alguna columna de las filas modificadas
        elif compara == 'diagonal_1':
            coinciden = sol[i] + i == col + fila
        elif compara == 'diagonal_2':
            coinciden = sol[i] - i == col - fila
        i += 1
    return coinciden


def esFactible(sol, fila, col):
    return not  (coinciden(sol, fila, col, 'columna') or coinciden(sol, fila, col, 'diagonal_1') or coinciden(sol, fila, col, 'diagonal_2'))


def nDamas(sol, fila): 							# metemos la solución y la fila en la que nos encontramos buscando (Hay que inicializar la solución para la primera llamada)
    N = len(sol)

    esSol = False
    if fila == N:								# Si es igual al tamaño de la fila indica que ya la hemos recorrido entera
        esSol = True

    col = 0
    while not esSol and col < N:				# Mientras no se haya recorrido toda la fila ni todas las columnas
        if esFactible(sol, fila, col):			# Si esFactible entonces se coloca una dama en esa posición
            sol[fila] = col						# Guarda el valor de la columna en la que se encuentra la dama en la fila en la que se coloca
            sol, esSol = nDamas(sol, fila + 1)	# Se reitera el código hasta que fila == N
        col += 1

    if not esSol:
        sol[fila] = -1							# Si esSol == False el valor pasa a valer -1. Es un valor representativo, ya que al no ser solución y devolver el resultado a la llamada anterior se sigue sumando una columna hasta que se encuentra una solución

    return sol, esSol

'''def inicializar(n):
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

    return sol, esSol'''


def imprimir(tablero):
    for i in range(len(tablero)):
        for j in range(len(tablero)):
            if tablero[i] == j:
                print("\u2655\t", end ='')
            else:
                print('o\t', end ='')
        print()


# Programa Principal:
N = 6   # Tamaño tablero
sol = inicializar(N)
fila = 0
sol, esSol = nDamas(sol, fila)

if esSol: imprimir(sol)
else: print('No se ha encontrado solucion.\n')