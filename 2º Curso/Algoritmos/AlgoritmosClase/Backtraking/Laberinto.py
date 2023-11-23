import copy


def esSolucion(lab, f, c):
    return f == len(lab)-1 and c == len(lab)-1


def esMejor(lab, mejorSol):
    n, m = len(lab) - 1, len(lab) - 1
    return lab[n][m] < mejorSol[n][m]


def esFactible(lab, f, c):
    return 0 <= f < len(lab) and 0 <= c <len(lab) and lab[f][c] == 0


def laberintoVA(lab, mejorSol, fil, col, cont):
    if esSolucion(lab, fil, col):
        if esMejor(lab, mejorSol):
            mejorSol = copy.deepcopy(lab)
        else:
            desp = [[0,1], [1,0], [0,-1], [-1, 0]]         # Posibles desplazamientos
            for d in desp:
                newF = fil + desp[0]
                newC = col + desp[1]
                if esFactible(lab, newF, newC):
                    lab[newF][newC] = cont
                    mejorSol = laberintoVA(lab, mejorSol, newF, newC, cont+1)
                    lab[newF][newC] = 0

        return mejorSol