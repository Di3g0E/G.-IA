

def esFactible(cell, lab):
    return 0 <= cell[0] < len(lab) and 0 <= cell[1] < len(lab) and lab[cell[0]][cell[1]] == 0

def bt(ab, cell, cells_to_visit, cells_visited):
    esSol = False
    if cells_visited == cells_to_visit and cell[0] == len(lab)-1 == cell[1]:
        esSol = True
    else:
        desp = [[1, 0], [1, 1], [0, 1], [0, 0]]
        for d in desp:
            nextF = cell[0] + d[0]
            nextC = cell[1] + d[1]
            if esFactible((nextF, nextC), lab):
                lab[nextF][nextC] = cells_visited
                esSol = bt(lab, (nextF, nextC), cells_to_visit, cells_visited + 1)
                if esSol:
                    return True
                lab[nextF][nextC] = 0
    return esSol



n = int(input())
lab = []
cells_to_visit = 0
for _ in range(n):
    row = list(map(int, input().strip().split()))
    cells_to_visit += (n + sum(row))    # Cuenta cuantas casillas con valor 0 hay en el lab. sumando las que valen -1 y restándoselas a 'n'
    lab.append(row)

ini, fin = ((0, 0), (n-1, n-1))
if bt(lab, ini, cells_to_visit, 0):
    print('SI')
else:
    print('NO')