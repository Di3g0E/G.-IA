import Instance
import Solution
import random


class ConstructiveRANDOM:
    def construct(self, instance: Instance) -> Solution:
        # Crear una copia de la lista de nodos
        nodes = instance.copy()

        # Mezclar la lista de nodos para obtener una solución aleatoria
        random.shuffle(nodes)

        return nodes
