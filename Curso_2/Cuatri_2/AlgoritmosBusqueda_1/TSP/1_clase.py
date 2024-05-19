import random

class CalcularMatrices:
    def __init__(self):
        pass

    def calcularMatriz(self, lista_ordenada):
        n = len(lista_ordenada)
        matriz = [[0] * n for _ in range(n)]

        # Llenar la matriz con valores arbitrarios
        for i in range(n):
            for j in range(n):
                matriz[i][j] = lista_ordenada[i] * lista_ordenada[j]

        return matriz


class Instancia:
    def __init__(self, lista_nodos, matriz):
        self.lista_nodos = lista_nodos
        self.matriz = matriz

    def construirMatriz(self, lista_nodos, matriz):
        # Verificar si la lista de nodos coincide con las dimensiones de la matriz
        n = len(matriz)
        if len(lista_nodos) != n:
            raise ValueError("La longitud de la lista de nodos no coincide con las dimensiones de la matriz")

        # Construir la matriz a partir de la lista de nodos y la matriz precalculada
        nueva_matriz = [[matriz[i][j] for j in lista_nodos] for i in lista_nodos]

        return nueva_matriz

    def calcular_distancia(self, lista_nodos):
        distancia = 0
        for i in range(len(lista_nodos)):
            # Calcular el índice del siguiente nodo en la lista, asegurándonos de que sea cíclica
            siguiente_nodo = (i + 1) % len(lista_nodos)
            # Acceder a la matriz utilizando los nodos actuales y siguientes
            if (siguiente_nodo <= len(lista_nodos)):
                distancia += self.matriz[lista_nodos[i]][lista_nodos[siguiente_nodo]]
        return distancia


class Solucion:
    def __init__(self, lista_nodos, distancia, instancia):
        self.lista_nodos = lista_nodos
        self.distancia = distancia
        self.instancia = instancia

    def __str__(self):
        return f"Lista de Nodos: {self.lista_nodos}, Distancia: {self.distancia}"


class BusquedaLocal:
    def __init__(self):
        pass

    def mejorar(self, solucion, instancia):
        # Implementación del método mejorar con el uso de instancia si es necesario
        lista_nodos = solucion.lista_nodos
        distancia_actual = solucion.distancia
        mejor_solucion = solucion

        for i in range(len(lista_nodos)):
            for j in range(i + 1, len(lista_nodos)):
                nueva_lista_nodos = lista_nodos[:]
                nueva_lista_nodos[i], nueva_lista_nodos[j] = nueva_lista_nodos[j], nueva_lista_nodos[i]
                nueva_distancia = instancia.calcular_distancia(nueva_lista_nodos)

                if nueva_distancia < distancia_actual:
                    mejor_solucion = Solucion(nueva_lista_nodos, nueva_distancia, solucion.instancia)
                    distancia_actual = nueva_distancia

        return mejor_solucion


class AlgoritmoGRASP:
    def __init__(self, construccion_random, busqueda_local):
        self.construccion_random = construccion_random
        self.busqueda_local = busqueda_local

    def ejecutar(self, instancia, iteraciones=10):
        mejor_solucion = None
        mejor_distancia = float('inf')

        for _ in range(iteraciones):
            solucion_inicial = self.construccion_random.construir(instancia)
            solucion_mejorada = self.busqueda_local.mejorar(solucion_inicial, instancia)

            if solucion_mejorada.distancia < mejor_distancia:
                mejor_solucion = solucion_mejorada
                mejor_distancia = solucion_mejorada.distancia

        return mejor_solucion


class ConstruccionRANDOM:
    def __init__(self, calcular_matrices):
        self.calcular_matrices = calcular_matrices

    def construir(self, instancia):
        lista_nodos = instancia.lista_nodos
        random.shuffle(lista_nodos)  # Mezcla aleatoriamente la lista de nodos
        distancia = instancia.calcular_distancia(lista_nodos)
        return Solucion(lista_nodos, distancia, instancia)


class Main:
    def __init__(self):
        pass

    def main(self):
        calcular_matrices = CalcularMatrices()
        instancia = Instancia([1, 2, 3, 4], calcular_matrices.calcularMatriz([1, 2, 3, 4]))
        busqueda_local = BusquedaLocal()
        construccion_random = ConstruccionRANDOM(calcular_matrices)

        algoritmo_grasp = AlgoritmoGRASP(construccion_random, busqueda_local)
        mejor_solucion = algoritmo_grasp.ejecutar(instancia)

        print("Mejor solución encontrada:")
        print(mejor_solucion)

# Aquí puedes crear una instancia de Main y llamar a la función main
if __name__ == "__main__":
    main = Main()
    main.main()
