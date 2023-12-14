def es_sol(x, y, lab, p):
    return lab[x][y] == p

def movimiento_factible(x, y, lab, elem):
    return 0 <= x < len(lab) and 0 <= y < len(lab[0]) and (lab[x][y] == elem + 1 or lab[x][y] == 0)

def resolver_laberinto(lab, cont, coords, elem, p, pos_ant):
    x, y = coords

    if es_sol(x, y, lab, p):
        return cont[0]
    else:
        movimientos = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        for fx, fy in movimientos:
            nx, ny = x + fx, y + fy
            if movimiento_factible(nx, ny, lab, elem):
                pos_ant = lab[x][y]
                if lab[nx][ny] == elem + 1:
                    elem = lab[nx][ny]
                cont[0] = cont[0] + 1
                lab[nx][ny] = cont[0]-1
                if es_sol(nx, ny, lab, p) or resolver_laberinto(lab, cont, (nx, ny), elem, p, pos_ant):
                    return cont[0]
                else:
                    lab[nx][ny] = pos_ant
                    if lab[nx][ny] == 0:
                        elem -= 1
        return cont[0]

# INPUT
n, m, p = map(int, input().strip().split())
lab = [0] * m

for i in range(n):
    lab[i] = list(map(int, input().strip().split()))

sol = resolver_laberinto(lab, [1], (0, 0), lab[0][0], p, lab[0][0])
print(sol)