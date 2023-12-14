def imprimir(matriz, tam_rej):
    for i in range(0, len(matriz), tam_rej):
        print(*matriz[i:i+tam_rej], sep=' ')


def eliminarElem(jugElim, id_jug):
    eliminados = set(jugElim)
    return ['X' if num in eliminados or num == 'X' else num for num in id_jug]


def obtener_siguiente_mayor(matriz, elemento):
    mayores = (num for num in matriz if num != 'X' and num > elemento)
    return min(mayores)


tam_rej = int(input())
id_jug = [int(num) for _ in range(tam_rej) for num in input().strip().split()]
jug_elim = set(map(int, input().strip().split()))

for elem in jug_elim:
    if elem not in id_jug:
        siguiente_mayor = obtener_siguiente_mayor(id_jug, elem)
        if siguiente_mayor is not None:
            idx = id_jug.index(siguiente_mayor)
            id_jug[idx] = 'X'

id_jug_actualizado = eliminarElem(jug_elim, id_jug)
imprimir(id_jug_actualizado, tam_rej)