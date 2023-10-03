casos = []

numCasos, maxMoney = map(int, input().strip().split())
for i in range(numCasos):       # Guarda la información de los casos en una lista de tuplas
    costeMaterial, dineroRecuperado = map(int, input().strip().split())
    casos.append((dineroRecuperado/costeMaterial, costeMaterial, dineroRecuperado, i))

casos.sort(reverse=True)
inversion = maxMoney
i = 0
ganado = 0
casosResueltos = []
while inversion != 0 and i < numCasos:
    if inversion > casos[i][1]:
        casosResueltos.insert(0, casos[i][3])
        ganado += casos[i][2]
        inversion -= casos[i][1]
        i += 1
    else:
        frac = inversion / casos[i][1]
        casosResueltos.insert(0, casos[i][3])
        ganado += casos[i][2] * frac
        inversion = 0

casosResueltos.sort()
for i in casosResueltos:
    if i != casosResueltos[-1]:
        print(i, end = " ")
    else:
        print(i)
print(round(ganado))