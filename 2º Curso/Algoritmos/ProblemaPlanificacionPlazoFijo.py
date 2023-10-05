

def inicializar(beneficio, plazo, id):                  # Unifica las 3 listas en una sola con tuplas
    tareas = []
    for i in range(len(id)):
        tareas.append((beneficio[i], plazo[i], id[i]))
    return tareas

def valorMayor(tareas, elem, plazo):                    # Calcula los valores máximos tando de plazos como de beneficios
    valor = 0
    id = 'x'
    for i in range(len(tareas)):

        if tareas[i][elem] > valor and plazo == 'n':
            valor = tareas[i][elem]
        elif tareas[i][elem] > valor and plazo + 1 == tareas[i][1]:
            valor = tareas[i][elem]
            id = tareas[i][2]
    return valor, id

def planificacionPlazoFijoVoraz(tareas):
    beneficioTotal = 0
    idPlazos = []
    plazoMax, null = valorMayor(tareas, 1, 'n')             # Calcula el plazo más alto, 'n' indica que no hay plazo
    for i in range(plazoMax):
        beneficioMax, id = valorMayor(tareas, 0, i)         # Calcula el beneficio mayor y su id, 'i' hace referencia al plazo en el que buscar el mayor beneficio
        beneficioTotal += beneficioMax
        idPlazos.append(id)

    print(beneficioTotal, idPlazos)


# Programa Principal
beneficio = [50, 10, 15, 30]
plazo = [1, 3, 2, 2]
id = [1, 2, 3, 4]

planificacionPlazoFijoVoraz(inicializar(beneficio, plazo, id))