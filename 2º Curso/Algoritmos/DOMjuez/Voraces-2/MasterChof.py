

"""cesta = []
numAlimSuper, tamCesta = map(int, input().strip().split())

for i in range(numAlimSuper):
    alimento, tamanio, valor = map(str, input().strip().split())
    tamanio = float(tamanio); valor = float(valor)
    cesta.append((valor/tamanio, alimento, tamanio, valor))

cesta.sort(reverse=True)
espacioLibre = 0
i = 0
cantAlim = 0
while espacioLibre != tamCesta:
    a = espacioLibre + cesta[i][2]
    if tamCesta >= a:
        cantAlim += cesta[i][3]
        espacioLibre += cesta[i][2]
        i += 1
    else:
        frac = cesta[i][2] / espacioLibre
        cantAlim += (cesta[i][3] + frac)
        espacioLibre = tamCesta

print("%.6f" % cantAlim)"""