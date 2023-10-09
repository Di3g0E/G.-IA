# Hacer un programa que reciba números por la entrada, cuente la cantidad de veces que se repiten y muestre por pantalla los que se repitan tres o más veces

empleados = list(map(int, input().strip().split()))     # Recibe una lista de números y los mete en una lista
empleados = [num for num in empleados if num != -1]     # Corta la lista cuando encuentre -1
diccEmpleados = {i: 0 for i in empleados}               # Crea un diccionario para cada valor único de la lista
listaEmpleados = []                                     # Lista que guarda los empleados que vean redes sociales 3 o más veces

for i in empleados:
    diccEmpleados[i] += 1
    if diccEmpleados[i] == 3:
        listaEmpleados.append(i)

listaEmpleados.sort()                                   # Ordena a los empleados desde el que menos veces a entrado al que más
for i in listaEmpleados:
    print(i, end = " ")