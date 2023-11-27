def crearArbol(arbol_familia):
    nodos = {}

    for line in arbol_familia:
        v = line.split()
        padre = int(v[0])
        hijos = list(map(int, v[1:]))

        if padre not in nodos:
            nodos[padre] = {"val": padre, "hijos": []}

        for child in hijos:
            if child not in nodos:
                nodos[child] = {"val": child, "hijos": []}
            nodos[padre]["hijos"].append(nodos[child])

    return nodos[0]  # La raíz del árbol es el primer miembro de la familia


def busquedaBinaria(nodo, id, generacion):
    if nodo["val"] == id:
        return generacion

    for child in nodo["hijos"]:
        result = busquedaBinaria(child, id, generacion + 1)
        if result is not None:
            return result

    return None



n = int(input())
arbol_familia = [input() for _ in range(n)]

root = crearArbol(arbol_familia)

m = int(input())
id_familiares = [int(input()) for _ in range(m)]

for id_miembro in id_familiares:
    generacion = busquedaBinaria(root, id_miembro, 1)
    print(generacion)