numAlim, tamCesta = map(int, input().strip().split())               # Indicar el núm. de alimentos que hay en el supermercado y el tamaño de la cesta
super = []                                                          # Lista en la que estarán los alimentos disponibles en el supermercado

for i in range(numAlim):
    alim, tam, val = map(str, input().strip().split())              # Pedir el nombre del alimento, su tamaño y el valor nutricional
    super.append((int(val) / int(tam), int(val), int(tam), alim))   # Añadirlo a la lista del super calculando la relación valor nutricional por el peso del elem.

super.sort(reverse=True)                                            # Ordenar la lista de mayor a menor
freeSpace = tamCesta                                                # Guarda para el bucle while, cuando el tamaño libre de la cesta sea 0 sale del bucle
i, val = 0, 0
while freeSpace != 0 and i < len(super):
    if super[i][2] > freeSpace:
        val += super[i][1] * (freeSpace / super[i][2])
        freeSpace = 0
    else:
        val += super[i][1]
        freeSpace -= super[i][2]
        i += 1

print(f"{val:.6f}")                                                 # Imprimimos por pantalla el valor de nuestra cesta con 6 dígitos


