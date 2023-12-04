def es_solucion(x, y, laberinto, visitado, cells_to_visit):
    return visitado == cells_to_visit-1 and (x, y) == (len(laberinto[0])-1, len(laberinto[1])-1)

def movimiento_factible(x, y, laberinto):
    return 0 <= x < len(laberinto[0]) and 0 <= y < len(laberinto[1]) and laberinto[x][y] == 0

def resolver_laberinto(laberinto, cells_to_visit, coords, visitado):
    x, y = coords

    if es_solucion(x, y, laberinto, visitado, cells_to_visit):
        return True
    else:
        movimientos = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dx, dy in movimientos:
            nx, ny = x + dx, y + dy
            if movimiento_factible(nx, ny, laberinto):
                visitado += 1
                laberinto[nx][ny] = visitado
                if es_solucion(nx, ny, laberinto, cells_to_visit, visitado) or resolver_laberinto(laberinto, cells_to_visit, (nx, ny), visitado):
                    return True
                else:
                    laberinto[nx][ny] = 0
                    visitado -= 1
        return False

num = int(input())
laberinto = []
cells_to_visit = 0
for i in range(num):
    fila = list(map(int, input().strip().split()))
    cells_to_visit += (num + sum(fila))
    laberinto.append(fila)

tiene_solucion = resolver_laberinto(laberinto, cells_to_visit, (0, 0), 0)

if tiene_solucion:
    print("SI")
else:
    print("NO")