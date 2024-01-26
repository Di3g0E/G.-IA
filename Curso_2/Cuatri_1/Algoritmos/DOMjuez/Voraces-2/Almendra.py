def isFeasible(almendras, nextCandId, pesoLibre):
    return pesoLibre - almendras[nextCandId][2] > 0

def greedyKnapSack(almendras, maxPeso):
    n = len(almendras)      # Num. de elementos de la lista de almendras
    pesoLibre = maxPeso     # Peso disponible que tenemos
    isSol = False           # Variable de control que me dice si tengo solución
    nextCandId = 0          # Id. del próximo candidato
    nutricion = 0           # Nutrición acumulada

    while not isSol and nextCandId < n:
        almendra = almendras[nextCandId]
        if isFeasible(almendras, nextCandId, pesoLibre):  # Indica si la almendra entra entera o no
            pesoLibre -= almendra[2]
            nutricion += almendra[1]
        else:
            valor = pesoLibre / almendra[2]     # Fracción de la última almendra que entra en la mochila
            nutricion += (valor * almendra[1])
            isSol = True
        nextCandId += 1
    return nutricion


numAlmendras, numPruebas = map(int, input().strip().split())    # Numero de almendras que se va a comer y número de pruebas que se va a realizar

almendras = []      # Lista que guarda la información de las almendras (rel. valor-peso, valor, peso, identificador)

for i in range(numAlmendras):       # Registro del valor nutricional y peso de las almendras
    valor, peso = map(int, input().strip().split())
    almendras.append((valor/peso, valor, peso, id))
almendras.sort(reverse=True)        # Ordena las tuplas de la lista de mayor a menor en relación con el primer parámetro de las tuplas

for i in range(numPruebas):         # Registro del valor nutritivo y peso máximo capaz de resistir antes de toser
    maxVal, maxPeso = map(int, input().strip().split())
    nutVal = greedyKnapSack(almendras, maxPeso)
    if nutVal >= maxVal:
        print("PUEDE")
    else:
        print("TOS")