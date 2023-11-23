
numPart, numGrup = map(int, input().strip().split())        # Indicar el núm. de participantes y miembros que entran en un grupo
participantes = []                                          # Lista con la info. de los participantes

for i in range(numPart):
    nombre, edad = map(str, input().strip().split())
    participantes.append((int(edad), nombre))               # Guardar las tuplas con la edad y el nombre en la lista

participantes.sort()                                        # Ordenar la lista de menor a mayor
y1, v1, = participantes[:numGrup], participantes[numGrup:]  # Crear dos listas con el grupo de jóvenes de tamaño numGrup
participantes.sort(reverse=True)                            # Ordenar la lista de mayor a menor
y2, v2 = participantes[numGrup:], participantes[:numGrup]   # Crear dos listas con el grupo de mayores de tamaño numGrup
sumaY1, sumaV2, sumaV1, sumaY2, i = 0, 0, 0, 0, 0
while i < numPart-numGrup:                                  # Sumar las edades de cada grupo para comparar
    if i < numGrup:
        sumaV1 += v1[i][0]
        sumaY2 += y2[i][0]
        sumaY1 += y1[i][0]
        sumaV2 += v2[i][0]
    else:
        sumaY2 += y2[i][0]
        sumaV1 += v1[i][0]
    i += 1

if sumaV1-sumaY1 > sumaV2-sumaY2:                           # Si las edades de las listas de jóvenes de tamaño numGrup y mayores
    for i in range(len(y1)):                                # tienen mayor diferencia que las segundas imprimir estas
        print(y1[i][1], end=" ")
    print()
    for i in range(len(v1)):
        print(v1[i][1], end=" ")
else:                                                       # Si las segundas listas tienen mayor diferencia de edad que las primeras
    y2.reverse(), v2.reverse()                              # revertir el orden de los elementos de las listas e imprimirlos
    for i in range(len(y2),):
        print(y2[i][1], end=" ")
    print()
    for i in range(len(v2),):
        print(v2[i][1], end=" ")