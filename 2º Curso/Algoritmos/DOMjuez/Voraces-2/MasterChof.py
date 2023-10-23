
numAlim, tamCesta = map(int, input().strip().split())               # Indicar el núm. de alimentos que hay en el supermercado y el tamaño de la cesta
super = []                                                          # Lista en la que estarán los alimentos disponibles en el supermercado

for i in range(numAlim):
    alim, tam, val = map(str, input().strip().split())              # Pedir el nombre del alimento, su tamaño y el valor nutricional
    super.append((int(val) / int(tam), int(val), int(tam), alim))   # Añadirlo a la lista del super calculando la relación valor nutricional por el peso del elem.

super.sort(reverse=True)                                            # Ordenar la lista de mayor a menor
freeSpace = tamCesta                                                # Guarda para el bucle while, cuando el tamaño libre de la cesta sea 0 sale del bucle
cesta = []                                                          # Lista en la que meteremos los alimentos con mayor relación valor-peso
i, val = 0, 0
while freeSpace != 0 or i < numAlim:
    if super[i][2] < freeSpace:
        val += super[i][1]                                          # Interesa únicamente saber el valor total de los alimentos de nuestra cesta por lo que los sumamos
        freeSpace -= super[i][2]                                    # Restamos el tamaño de los alimentos que metemos en nuestra cesta al espacio sobrante
    else:
        frac = freeSpace / super[i][2]                              # Como no nos cabe un alimento completo calculamos la fracción del alimento y lo partimos para meterlo
        val += super[i][1] * frac
        freeSpace = 0
    i += 1

print('%.6f' % val)                                                 # Imprimimos por pantalla el valor de nuestra cesta con 6 dígitos


