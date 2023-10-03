cartas = []

numCartas, maxRiesgo = map(int, input().strip().split())
for i in range(numCartas):
    nombre, riesgo, beneficio = map(str, input().strip().split())
    riesgo = int(riesgo); beneficio = int(beneficio)
    cartas.append((beneficio/riesgo, nombre, beneficio, riesgo))

cartas.sort(reverse=True)
riesgoAcum = 0; i = 0
while maxRiesgo != riesgoAcum:
    if maxRiesgo >= riesgoAcum + cartas[i][3]:
        print(cartas[i][1], end = " ")
        riesgoAcum += cartas[i][3]
        i += 1
    else:
        print(cartas[i][1])
        riesgoAcum = maxRiesgo