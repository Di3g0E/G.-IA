

def busquedaBinaria(lista, ini, fin, elem):
    if ini <= fin:
        medio = (ini + fin) // 2
        if lista[medio] == elem:
            return medio
        elif lista[medio] > elem:
            return busquedaBinaria(lista, ini, medio-1, elem)
        else:
            return busquedaBinaria(lista, medio+1, fin, elem)
    return -1


num_grup1 = int(input())
id_grup1 = list(map(int, input().strip().split()))
num_grup2 = int(input())
id_grup2 = list(map(int, input().strip().split()))
num_par_conect = int(input())
par_conect = []
for i in range(num_par_conect):
    a, b = map(int, input().strip().split())
    v = busquedaBinaria(id_grup1, 0, num_grup1-1, a)
    w = busquedaBinaria(id_grup2, 0, num_grup2 - 1, b)
    print(f'{v} {w}') if v >= 0 and w >= 0 else print('SIN DESTINO')
