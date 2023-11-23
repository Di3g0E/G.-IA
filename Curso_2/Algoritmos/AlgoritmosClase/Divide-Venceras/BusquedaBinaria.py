def busquedaBinaria(lista, inicio, final, elem):
    if inicio <= final:
        medio = (inicio + final) // 2
        if lista[medio] == elem:
            return medio
        elif lista[medio] > elem:
            return busquedaBinaria(lista, inicio, medio-1, elem)
        else:
            return busquedaBinaria(lista, medio+1, final, elem)

    return -1


l = list(range(1, 19))
e = 8
print(busquedaBinaria(l, 0, len(l), e))