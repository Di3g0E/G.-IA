# Realizar el maximo de tareas que reporten el beneficio maximo según el plazo

def plazoFijo(beneficio, plazo, num):
    # Buscar el plazo máximo del que disponemos en nuestra lista de tareas
    plazoMax = max(plazo)
    # Buscar el beneficio máximo con cada plazo que tengamos
    listaTareas = []
    listaPlazos = set()     # Lista con plazos sin repetir
    for elem in plazo:
        listaPlazos.add(elem)

    valMax = 0  # Valor maximo de cada plazo
    for elem in listaPlazos:
        for j in range(N):
            if elem == plazo[j]:
                if valMax < ben[j]:
                    valMax = ben[j]
        listaTareas.append(valMax)

    beneficio = sum(listaTareas)
    return beneficio, listaPlazos


# Programa Principal
N = 4   # Numero de tareas
ben = [50, 10, 15, 30]  # Beneficio de cada tarea
plazo = [2, 1, 2, 1]    # Plazo de cada tarea
print(plazoFijo(ben, plazo, N))