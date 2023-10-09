N = 5       # Num valores
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

print(valMochila)