

def sort(l1, l2):                                   # Esta función ordena los elementos de dos listas dadas
    listaOrdenada = []                              # Lista en la que guardaremos los elem ordenados
    i, j = 0, 0                                     # Guardas para las diferentes listas, no tienen porqué ser del mismo tamaño

    while i < len(l1) and j < len(l2):
        if l1[i] < l2[j]:                           # Si el valor del elemento de la lista 1 es menor se guarda en la lista ordenada
            listaOrdenada.append(l1[i])
            i += 1                                  # Se suma 1 al índice de la primera lista para avanzar de elemento
        else:                                       # Si el valor del elemento de la lista 2 es menor se guarda en la lista ordenada
            listaOrdenada.append(l2[j])
            j += 1                                  # Se suma 1 al índice de la primera lista para avanzar de elemento

    listaOrdenada.extend(l1[i:])                    # Agregar los elementos restantes de l1, si los hay
    listaOrdenada.extend(l2[j:])                    # Agregar los elementos restantes de l2, si los hay

    return listaOrdenada


def mergeSort(lista, val_in, val_fin):              # Esta función dibide la lista por la mitad recursivamente hasta tener un único valor y después los va ordenando
    mitad = (val_in + val_fin) // 2                 # Cálculo de la mitad de la lista
    if val_fin <= val_in:                           # Si sólo hay un valor en la lista lo devuelve
        return [lista[val_in]]
    else:
        l1 = mergeSort(lista, val_in, mitad)        # Llamada recursiva de la lista desde el valor inicial hasta la mitad calculada
        l2 = mergeSort(lista, mitad+1, val_fin)     # Llamada recursiva de la lista desde la mitad calculada de la lista hasta el final
        sol = sort(l1, l2)                          # Llamada a la función de ordenación que ordenará las listas guardadas en l1 y l2
        return sol


###############################################   Programa Principal    ################################################
l = [1, 10, 2, 9, 3, 8, 4 , 7, 5 ,6]
l1 = [7, 6, 2, 3, 4, 65, 8, 63, 74, 5, 78]

sol = mergeSort(l, 0, len(l)-1)
sol1 = mergeSort(l1, 0, len(l1)-1)

print(f'{sol}\n{sol1}')