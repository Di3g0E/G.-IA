

def busquedaBinaria(lista, ini, fin, elem, cont):
    if ini <= fin:
        medio = (ini + fin) // 2
        if lista[medio] == elem:
            cont += 1
            return cont
        elif lista[medio] < elem:
            return busquedaBinaria(lista, ini, medio-1, elem, cont+1)
        else:
            return busquedaBinaria(lista, medio+1, fin, elem, cont+1)
    return -1

num_fam = int(input())
arbol = []
for i in range(num_fam):
    elem = list(map(int, input().strip().split()))
    arbol.append(elem)
cons_fam = int(input())
nivel_miembros = []
for i in range(cons_fam):
    miembro = int(input())
    cont = 0
    sol = busquedaBinaria(arbol)