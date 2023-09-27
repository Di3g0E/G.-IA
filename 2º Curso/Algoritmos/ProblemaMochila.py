# Meter en la mochila la mayor cantidad de valor para el peso que puedes llevar

def suma(lista):
    valor = 0
    for i in lista:
        valor += i

    return valor

def mochilaVoraz1(peso, valor, pesoMax):
    rel_Val_Pes = []
    mochila = []
    pesoMochila = 0
    indicesUsados = []

    # Saber relacion valor-peso
    for i in range(len(peso)):
        rel_Val_Pes.append(valor[i]/peso[i])

    rel_Val_Pes_Copy = rel_Val_Pes[:]

    # Meter en la mochila por orden de relacion valor-peso
    while pesoMochila != pesoMax:
        i = rel_Val_Pes.index(max(rel_Val_Pes_Copy))
        pesoRestante = pesoMax - pesoMochila
        if i not in indicesUsados and pesoRestante > peso[i]:
            mochila.append(valor[i])
            indicesUsados.append(i)
            pesoMochila += peso[i]
            rel_Val_Pes_Copy.remove(max(rel_Val_Pes_Copy))

        elif pesoRestante < peso[i]: # Cuando no queden valores enteros que meter se calcula el espacio sobrante y se parte el objeto
            espacio = pesoRestante / peso[i]
            mochila.append(int(valor[i] * espacio))
            pesoMochila = pesoMax

    return mochila

# Programa Principal:
#PesoValor = {peso: [10, 20, 30, 40, 50], valor: [20, 30, 66, 40, 60]}
peso = [10, 20, 30, 40, 50]
valor = [20, 30, 66, 40, 60]
pesoMax = 100
print("Valor igual a: ", suma(mochilaVoraz1(peso, valor, pesoMax)), ". Los valores de la mochila son: ", mochilaVoraz1(peso, valor, pesoMax))