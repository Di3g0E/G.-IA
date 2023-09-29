# El programa devuelve el resultado de si con las horas disponibles se aprueban o no las asignaturas

dicc = {}

# Pedir los datos: ·num de asiganturas y num de pruebas ·asignaturas y horas de estudio ·horas disponibles
N, M = map(int, input().split())
horDisp = [0] * M
for i in range(N):
    id, horas = map(int, input().split())
    dicc[id] = horas
for i in range(M):
    horDisp[i] = int(input())

# Sumar horas de estudio de asignaturas y compararlas con las disponibles
suma = 0
for key in dicc:
    suma += dicc[key]
for i in range(M):
    if horDisp[i] >= suma:
        print("APROBADO")
    else:
        print("SUSPENSO")