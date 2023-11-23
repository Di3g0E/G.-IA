import copy


def esSol(lab, f, c):
    return f == len(lab)-1 and c == len(lab)-1


def esMej(lab, mejSol):
    i = len(lab)-1
    return lab[i][i] < mejSol[i][i]


def esFactible(lab, f, c):
    return 0 <= f < len(lab) and 0 <= c < len(lab)

def laberintoVA(lab, mejSol, f, c, cont):
    if not esSol(lab, f, c):
        if esMej(lab, mejSol):
            mejSol = copy.deepcopy(lab)
        else:
            desp = [[1, 0], [1, 1], [0,1], [0, 0]]
            for d in desp:
                newF = f + d[0]
                newC = c + d[1]
                if esFactible(lab, newF, newC):
                    lab[newF][newC] = cont
                    mejSol = laberintoVA(lab, mejSol, f, c, cont)
                    lab[newF][newC] = 0
    return cont


n, m, p = map(int, input().strip().split())
lab = [0] * m

for i in range(n):
    lab[i] = list(map(int, input().strip().split()))

sol = laberintoVA(lab, [[0] * m for i in range(n)], 0, 0, 0)
print(sol)