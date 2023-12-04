def imprimir(matriz):
    for j in range(len(matriz)):
        print(matriz[j], end=' ')
        if (j + 1) % tam_rej == 0:
            print()


def eliminarElem(jugadoresEliminados, id_jug):
    eliminados = set(jugadoresEliminados)

    for i in range(len(id_jug)):
        if id_jug[i] in eliminados:
            id_jug[i] = 'X'
        elif id_jug[i] == 'X':
            continue
        else:
            eliminados.add(id_jug[i])


tam_rej = int(input())
id_jug = []
for i in range(tam_rej):
    row = list(map(int, input().strip().split()))
    id_jug.extend(row)

jug_elim = list(map(int, input().strip().split()))
eliminarElem(jug_elim, id_jug)
imprimir(id_jug)

'''
def imprimir(matriz):
    for j in range(len(id_jug)):
        print(id_jug[j], end=' ')
        if (j + 1) % tam_rej == 0:
            print()

def eliminarElem(jugadoresEliminados, id_jug):
    for elem in jugadoresEliminados:
        if elem in id_jug:
            elim = busquedaBinaria(id_jug, 0, len(id_jug) - 1, elem)
            id_jug[elim] = 'X'
        else:
            cercano = None
            for i in range(len(id_jug)):
                if id_jug[i] != 'X':
                    if id_jug[i] > elem and (cercano is None or id_jug[i] < id_jug[cercano]):
                        cercano = i

            id_jug[cercano] = 'X'

def busquedaBinaria(lista, ini, fin, elem):
    medio = (ini + fin) // 2
    if ini <= fin:
        if lista[medio] == elem:
            return medio
        elif lista[medio] == 'X' or lista[medio] > elem:
            return busquedaBinaria(lista, ini, medio - 1, elem)
        else:
            return busquedaBinaria(lista, medio + 1, fin, elem)

    ant = (elem - lista[medio - 1]) if lista[medio - 1] != 'X' else float('inf')
    sig = (lista[medio] - elem) if lista[medio] != 'X' else float('inf')
    return min(ant, sig)

tam_rej = int(input())
id_jug = []
for i in range(tam_rej):
    row = list(map(int, input().strip().split()))
    id_jug.extend(row)

jug_elim = list(map(int, input().strip().split()))
eliminarElem(jug_elim, id_jug)
imprimir(id_jug)'''