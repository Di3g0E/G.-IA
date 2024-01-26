


def busquedaBinaria(lista, inicio, final, elem):
    if inicio <= final:
        medio = (inicio + final) // 2
        if lista[medio] == elem:
            return medio
        elif lista[medio] < elem:
            return busquedaBinaria(lista, medio+1, final, elem)
        else:
            return busquedaBinaria(lista, inicio, medio-1, elem)
    return -1


lista_universos = list(map(str, input().strip().split()))
num_universos_busqueda = int(input())
lista_doctorStrange = []
for i in range(num_universos_busqueda):
    elem = input()
    lista_doctorStrange.append(elem)
lista_universos.sort()

for elem in lista_doctorStrange:
    anterior = busquedaBinaria(lista_universos, 0, len(lista_universos)-1, elem)-1
    posterior = busquedaBinaria(lista_universos, 0, len(lista_universos)-1, elem)+1

    print(lista_universos[anterior], end = ' ') if anterior >= 0 else print('VACIO', end = ' ')
    print(lista_universos[posterior]) if posterior < len(lista_universos) else print('VACIO')