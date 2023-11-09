

def busquedaBinaria(lista, ini, fin, elem):
    medio = (ini + fin) // 2
    if ini <= fin:
        if lista[medio] == elem:
            return medio
        elif lista[medio] > elem:
            return busquedaBinaria(lista, ini, medio-1, elem)
        else:
            return busquedaBinaria(lista, medio+1, fin, elem)

    ant = (elem-lista[medio-1])
    sig = (lista[medio]-elem)
    return min(ant, sig)

tam_rej = int(input())
id_jug = []
for i in range(tam_rej):
    a, b, c = map(int, input().strip().split())
    id_jug.append(a)
    id_jug.append(b)
    id_jug.append(c)
jug_elim = list(map(int, input().strip().split()))

for i in range(len(id_jug)):
    if i < len(jug_elim):
        elim = busquedaBinaria(id_jug, 0, len(id_jug) - 1, jug_elim[i])
        id_jug[elim] = 'X'
    if ((i+1) % tam_rej) == 0:
        print(id_jug)
    else:
        print(id_jug[i], end=' ')