
def mochila(elem):
    elem.sort(reverse = True)


# Inputs
numElem = int(input())                              # Número de elementos que tenemos
pesoSoportable = int(input())                       # Peso capaz de llevar en la mochila

elem = []
for i in range(numElem):
    peso, valor = map(int, input().strip().split()) # Peso y valor de cada elemento
    elem.append((valor / peso, peso, valor, i))     # Guarda en la lista la relación valor-peso, el peso, el valor y el id de cada elemento



""" Ejemplo de prueba
Input:
5
100
10 20
20 30
30 66
40 40
50 60

Output:
164.0
"""
















"""N = 5       # Num valores
W = 100     # Peso max que soporta la mochila
w = [10, 20, 30, 40, 50]; v = [20, 30, 66, 40, 60]  # Peso y valores de los elementos a meter

# Calcular la relacion valor-precio
vw = [vi / wi for vi, wi in zip(v, w)]

# Meter los elem. con mayor relación en la mochila
mochila = []
pesoMochila = 0
vwCpy = vw[:]
while W != pesoMochila:
    elemMax = max(vwCpy)
    if W > pesoMochila + w[vw.index(elemMax)]:
        mochila.append(v[vw.index(elemMax)])
        pesoMochila += w[vw.index(elemMax)]
        vwCpy.remove(elemMax)
    else:
        frac = (W - pesoMochila) / w[vw.index(elemMax)]
        mochila.append(v[vw.index(elemMax)] * frac)
        pesoMochila = W

# Valor de la mochila
valMochila = 0
for elem in mochila:
    valMochila += elem

print(valMochila)"""