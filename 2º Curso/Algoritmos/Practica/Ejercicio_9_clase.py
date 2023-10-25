# Dado un vector de n enteros cualesquiera (positivos y negativos) se pide encontrar el máx. valor de la sumas parciales de elem. consecutivos.
# Ej: dado el vector [-2, 11, -4, 13, -5, -2] el resultado sería 20 (suma de los elementos que van del segundo al cuarto).

l = [-2, 11, -4, 13, -5, -2]
ini = 0
fin = len(l)-1

def suma_max_central(l, ini, mitad, fin):
    suma = 0
    suma_max_der = 0
    for i in range(mitad, ini-1, -1):
        suma += l[i]
        if suma_max_der < suma:
            suma_max_der = suma
    suma = 0
    suma_max_izq = 0
    for i in range(mitad+1, fin+1):
        suma += l[i]
        if suma > suma_max_izq:
            suma_max_izq = suma
        return suma_max_der + suma_max_izq

def suma_max(l, ini, fin):
    if ini > fin:
        result = 0
    elif ini == fin:
        result = l[ini]
    else:
        mitad = (ini + fin) // 2
        suma_max_izq = suma_max(l, ini, mitad)
        suma_max_der = suma_max(l, mitad + 1, fin)
        suma_max_cen = suma_max_central(l, ini, mitad, fin)
        result = max(suma_max_izq, suma_max_der, suma_max_cen)

    return result

sol = suma_max(l, ini, fin)
print(sol)