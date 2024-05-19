import Instance
from Solution import Solution
import random


class ConstructiveRANDOM:
    @staticmethod
    def construct(instancia: Instance) -> Solution:
        node_list = instancia.node_list.copy()
        random.shuffle(node_list)
        solution = Solution(node_list, 0, instancia)
        solution.evaluate()
        return solution
