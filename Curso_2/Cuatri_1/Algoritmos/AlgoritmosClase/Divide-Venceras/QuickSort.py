# Ordena una lista moviendo a la izquierda los valores que son menores que el valor pivote y a la derecha los que son mayores

def intercambiar(lista, i, j):                      # Intercambia la posición del valor de la izquierda (i) y el de la derecha (j)
    aux = lista[i]                                  # Guarda la posición del valor de la izquierda ya que se va a sustituir por el de la derecha y se perdería
    lista[i] = lista[j]
    lista[j] = aux
    return lista                                    # Devuelve la lista con los valores intercambiados


def pivote(lista, ini, fin):
    valorPivote = lista[ini]                        # Cogemos como valor pivote el primero de la lista
    i = ini + 1                                     # Valor que empieza por la izquierda de la lista y va creciendo
    j = fin                                         # Valor que empieza por la derecha de la lista y va decreciendo
    flag = False
    while not flag:
        while i <= j and lista[i] <= valorPivote:   # Mientras i sea menor o igual que j y el valor del elem. de la posición 'i' sea menor o igual que el pivote se sigue a la siguiente posición porque no hace falta pasarlo al lado derecho
            i += 1
        while i <= j and lista[j] >= valorPivote:   # Mientras i sea menor o igual que j y el valor del elem. de la posición 'j' sea mayor o igual que el pivote se sigue a la posición anterior porque no hace falta pasarlo al lado izquierdo
            j -= 1

        if j < i:                                   # Si el índice de la derecha (j) es menor que el de la izquierda (i) se sale del bucle
            flag = True
        else:                                       # Si no se intercambian las posiciones 'i' y 'j'
            lista = intercambiar(lista, i, j)
    lista = intercambiar(lista, ini, j)             # Al terminar la ordenación de los elementos mayores y menores que el elem. pivote se intercambia el elem. pivote con el ultimo elem. menor
    return lista, j                                 # Devuelve la lista reordenada y la posición del elemento pivote

def quicksort(lista, ini, fin):                     # Ordena la lista a partir del elem. inicial (ini) y final (fin) indicados
    if ini < fin:                                   # Mientras el índice inicial (ini) siga siendo menor que el final (fin) se hará lo siguiente:
        [lista, p] = pivote(lista, ini, fin)        # Reordenar la lista a partir del indice 'ini' y 'fin'
        lista = quicksort(lista, ini, p-1)          # Llamada recursiva para ordenar los elem. de la lista menores que el elem. 'pivote'
        lista = quicksort(lista, p+1, fin)          # Llamada recursiva para ordenar los elem. de la lista mayores que el elem. 'pivote'
    return lista


###############################################   Programa Principal    ################################################
l = [9, 4, 17, 21, 34, 6, 0, -5, 56, 14, 8, 43]
l1 = [1, 9, 5, 7, 3, 2, 2]

sol = quicksort(l, 0, len(l)-1)
sol1 = quicksort(l1, 0, len(l1)-1)

print(f'{sol}\n{sol1}')