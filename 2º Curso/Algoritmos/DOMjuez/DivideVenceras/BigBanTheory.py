import sys

def busquedaBinaria(lista, inicio, final, elem, saltos):
    if inicio <= final:
        medio = (inicio + final) // 2
        if lista[medio] == elem:
            return saltos
        elif lista[medio] > elem:
            return busquedaBinaria(lista, inicio, medio-1, elem, saltos+1)
        else:
            return busquedaBinaria(lista, medio+1, final, elem, saltos+1)
    return -1

num_hab, num_intentos, id_Penny = map(int, input().strip().split())
lista = list(map(int, input().strip().split()))

sol = busquedaBinaria(lista, 0, len(lista)-1, id_Penny, 1)
if sol <= num_intentos:
    print(f'Penny esta en la habitacion {lista.index(id_Penny)}, se han requerido {sol} saltos')
else:
    sys.stdout.buffer.write("¿Donde esta Penny?".encode('utf-8'))