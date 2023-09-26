# Este programa indica la posición del aspirante más bajo, más alto y la cantidad de aspirantes que superan la altura mínima

N = int(input())                                        # Num. aspirantes
M = int(input())                                        # Altura min.
aspirantes = list(map(int, input().strip().split()))    # Lista de altura de aspirantes

mayor = aspirantes[0]                                   # Guarda la altura del primer aspirante
menor = aspirantes[0]                                   # Guarda la altura del primer aspirante
posMayor = 0                                            # Guarda la posición en la lista del primer aspirante
posMenor = 0                                            # Guarda la posición en la lista del primer aspirante

cont_aspirantes = 0                                     # Contador de aspirantes por encima del mínimo

for i in range(N):
    if aspirantes[i] < menor:       # Guarda la posición del más bajo
        menor = aspirantes[i]
        posMenor = i
    if aspirantes[i] > mayor:       # Guarda la posición del más alto
        mayor = aspirantes[i]
        posMayor = i
    if aspirantes[i] >= M:           # Cuenta los aspirantes por encima del líminte
        cont_aspirantes += 1

print(posMenor, posMayor, cont_aspirantes)
