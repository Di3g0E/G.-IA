

def solIni(num_obj, cap_max, obj):
    obj.sort()
    capacidad, i = 0, 0
    while num_obj > 0 and capacidad <= cap_max:
        capacidad += obj[i][0]
        num_obj += 1
        i += 1




def ordenacion_y_poda(k, capacidad_restante, beneficio_acumulado, objetos, beneficio_maximo, seleccionados):
    if k == len(objetos) or capacidad_restante == 0:
        if beneficio_acumulado > beneficio_maximo[0]:
            beneficio_maximo[0] = beneficio_acumulado
            seleccionados.clear()
            seleccionados.extend(objeto[0] for objeto in objetos if objeto[3])
        return

    nombre, peso, beneficio, ratio = objetos[k]

    if peso <= capacidad_restante:
        objetos[k][3] = 1
        ordenacion_y_poda(k + 1, capacidad_restante - peso, beneficio_acumulado + beneficio, objetos[:], beneficio_maximo, seleccionados)
        objetos[k][3] = 0

    ordenacion_y_poda(k + 1, capacidad_restante, beneficio_acumulado, objetos[:], beneficio_maximo, seleccionados)

def caja_del_futuro(n, capacidad, objetos, sol):
    beneficio_maximo = [0]
    seleccionados = []

    for i in range(n):
        objetos[i] = list(objetos[i])
        objetos[i].append(objetos[i][2] / objetos[i][1])

    objetos.sort(key=lambda x: x[4], reverse=True)

    ordenacion_y_poda(0, capacidad, 0, objetos, beneficio_maximo, seleccionados)

    return beneficio_maximo[0], capacidad, seleccionados



# INPUT
n, capacidad = map(int, input().split())
objetos = []
for _ in range(n):
    nombre, peso, beneficio = input().split()
    objetos.append((int(peso), int(beneficio), nombre))

# OUTPUT
b, p, o = caja_del_futuro(n, capacidad, objetos, solIni())
print(f"{b} {p}")
for objeto in sorted(o):
    print(objeto)
