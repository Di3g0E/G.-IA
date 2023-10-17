
numParticipantes, tamGrupos = map(int, input().strip().split())     # Indicarnum. de participantes y el tamaño de cada grupo

participantes = []
for i in range(numParticipantes):
    nombre, edad = map(str, input().strip().split())
    participantes.append((edad, nombre))

participantes.sort()
jovenes = []
noTanJovenes = []
for i in range(numParticipantes):
    if i < (numParticipantes//2):
        jovenes.append(participantes[i][1])
    else: noTanJovenes.append((participantes[i][1]))

print(*jovenes)
print(*noTanJovenes)