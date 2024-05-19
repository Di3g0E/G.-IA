'''from math import sqrt


class CalculatorDistance:
    @staticmethod
    def calculate_euclidean_distance_matrix(latitudes: list[float], longitudes: list[float]) -> list[list[float]]:
        distance_matrix: list[list[float]] = []
        x: int = 0
        for latitude1, longitude1 in latitudes, longitudes:
            distance_matrix.append([])
            for latitude2, longitude2 in latitudes, longitudes:
                distance_matrix[x].append(
                    CalculatorDistance.calculate_euclidean_distance(latitude1, latitude2, longitude1, longitude2))
                x += 1
        return distance_matrix

    @staticmethod
    def calculate_euclidean_distance(lat_node_1: float, lat_node_2: float,
                                     long_node_1: float, long_node_2: float) -> int:
        return int(sqrt((lat_node_2 - lat_node_1)**2 + (long_node_2 - long_node_1)**2))
'''

import matplotlib.pyplot as plt
import numpy as np

# Generar datos de ejemplo
num_puntos = 1000
lista_x = np.linspace(0, 10, num_puntos)
lista_y = np.sin(lista_x)  # Por ejemplo, una función seno

def dibujar_conexion_puntos(lista_x, lista_y):
    # Concatenar el primer punto al final para cerrar la conexión
    lista_x = np.concatenate((lista_x, [lista_x[0]]))
    lista_y = np.concatenate((lista_y, [lista_y[0]]))

    plt.plot(lista_x, lista_y, marker='o', linestyle='-')
    plt.xlabel('Eje X')
    plt.ylabel('Eje Y')
    plt.title('Conexión entre puntos')
    plt.grid(True)
    plt.show()

dibujar_conexion_puntos(lista_x, lista_y)
