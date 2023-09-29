# Hacer un programa que reciba números por la entrada, cuente la cantidad de veces que se repiten y muestre por pantalla los que se repitan tres o más veces

# Recibir números
empleados = list(map(int, input().strip().split()))
empleados = [num for num in empleados if num != -1]

# Contar cuantas veces se repiten los números
dicc = {}
for i in empleados:
    dicc[i] = 0
for i in empleados:
    dicc[i] += 1

# Imprimir los núm. con tres o más rep.
for key in reversed(dicc):
    if dicc[key] >= 3:
        print(key, end = " ")