numAsignaturas, numConvocatorias = map(int, input().strip().split())
tEstudio = 0                                        # Horas necesarias para aprobar
hAsignaturas = [0] * numAsignaturas                 # Lista de las horas de cada asignatura
convocatorias = [0] * numConvocatorias              # Lista con las horas de cada convocatoria
for i in range(0, numAsignaturas):                  # Guarda las horas de cada asignatura en su lista
    asignaturas, hAsignaturas[i] = map(int, input(). strip().split())
for i in range(0, numConvocatorias):                # Guarda las horas de cada convocatoria en su lista
    convocatorias[i] = int(input())

hAsignaturas.sort()                                     # Ordena de menor a mayor las horas de las asignaturas de menor a mayor
for i in range(numAsignaturas):
    tEstudio += hAsignaturas[i] * (numAsignaturas - i)  # Cálculo de las horas necesarias para aprobar

for i in convocatorias:                                 # Respuesta por pantalla
    if i >= tEstudio:
        print("APROBADO")
    else:
        print("SUSPENSO")