import Instance
import Solution
import matplotlib.pyplot as plt


class Solution:
    def _init_(self, node_list: list[float], distance: float, instance: Instance):
        self.node_list: list[float] = node_list
        self.distance: float = distance
        self.instance: Instance = instance

    def compare(self, solution: Solution):
        if self.distance < solution.distance:
            return -1
        elif self.distance == solution.distance:
            return 0
        else:
            return 1

    def evaluate(self):
        for pos_node in range(len(self.node_list) - 2):
            self.distance += self.instance.distance_matrix[self.node_list[pos_node]][self.node_list[pos_node + 1]]
        primer_nodo = self.node_list[0]
        ultimo_nodo = self.node_list[len(self.node_list) - 1]
        self.distance += self.instance.distance_matrix[ultimo_nodo][primer_nodo]     # Último a primero

    def print_solution(self):
        distance: float = 0.0
        for node in self.node_list:
            print(node)
            distance += self.distance
        print(distance)

    def dibujar_mapa(latitud, longitud, solucion):
        # Crear una figura y un conjunto de ejes
        fig, ax = plt.subplots()

        # Dibujar puntos de coordenadas (latitud, longitud)
        ax.plot(longitud, latitud, 'bo', label='Coordenadas')

        # Unir los puntos de acuerdo a la solución
        for i in range(len(solucion) - 1):
            idx1 = solucion[i]
            idx2 = solucion[i + 1]
            ax.plot([longitud[idx1], longitud[idx2]], [latitud[idx1], latitud[idx2]], 'r-')

        # Etiquetas y título
        ax.set_xlabel('Longitud')
        ax.set_ylabel('Latitud')
        ax.set_title('Mapa con Solución')

        # Mostrar la leyenda
        ax.legend()

        # Mostrar el gráfico
        plt.show()