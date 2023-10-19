
numPart, tamGroup = map(int, input().strip().split())       # Inicar el num. de participantes y el tamaño máximo del primer grupo
participantes = []                                          # Lista en la que meter la info. de cada participante

for i in range(numPart):
    nombre, edad = map(str, input().strip().split())        # Pedir el nombre y la edad de cada participante
    participantes.append((int(edad), nombre))               # Añadir a cada participante en la lista

participantes.sort()                                        # Ordenar la lista de menor a mayor por edades
tam = 0                                                     # Guarda para el bucle while. No puede superar el tamaño max. y nos indicará cuando cambiar de grupo
g1, g2 = [], []
while tam < numPart:
    if tam > tamGroup:
        g1.append(participantes[tam][1])
    else:
        g2.append(participantes[tam][1])
    tam += 1

print(*g1)                                                  # Imprime los nombres de cada integrante del grupo 1 sin los corchetes
print(*g2)                                                  # Imprime los nombres de cada integrante del grupo 2 sin los corchetes










'''numParticipantes, tamGrupos = map(int, input().strip().split())     # Indicar el num. de participantes y el tamaño de cada grupo
participantes = []

for i in range(numParticipantes):
    nombre, edad = map(str, input().strip().split())
    participantes.append((edad, nombre))

participantes.sort()
jovenes, noTanJovenes = [], []
for i in range(numParticipantes):
    if i < (numParticipantes//2):
        jovenes.append(participantes[i][1])
    else: noTanJovenes.append((participantes[i][1]))

print(*jovenes)
print(*noTanJovenes)'''