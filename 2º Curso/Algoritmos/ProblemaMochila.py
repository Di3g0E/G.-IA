# Problema de la mochila

N = 5       # Cantidad de elementos
W = 100     # Peso soportable dentro de la mochila
w = [10, 20, 30, 40, 50]; v = [20, 30, 66, 40, 60]  # Peso y valor de cada elemento

# Calcular la relación valor-peso de cada elemento
vw = [vi / wi for vi, wi in zip(v, w)]

# Meter los elementos de mayor valor en la mochila y dividir el que no quepa (para que entre al menos una fracción de su valor)
vw_copy = vw[:]
mochila = []
sumaPesos = 0
while W != sumaPesos:
    elem = max(vw_copy)
    if W > sumaPesos + w[vw.index(elem)]:
        mochila.append(v[vw.index(elem)])
        sumaPesos += w[vw.index(elem)]
        vw_copy.remove(elem)
    else:
        frac = (W-sumaPesos) / w[vw.index(elem)]
        mochila.append(v[vw.index(elem)] * frac)
        sumaPesos = W

# Indicar el valor final de la mochila
valMochila = 0
for elem in mochila:
    valMochila += elem
print(valMochila)