import Instance
import Solution


class Solution:
    def __init__(self, node_list: list[int], distance: int, instance: Instance):
        self.node_list: list[int] = node_list
        self.distance: int = distance
        self.instance: Instance = instance

    def compare(self, solution: Solution):
        if self.distance < solution.distance:
            return -1
        elif self.distance > solution.distance:
            return 0
        else:
            return 1

    def evaluate(self):
        for pos_node in range(len(self.node_list) - 1):
            self.distance += self.instance.distance_matrix[pos_node][pos_node + 1]
        first_node = self.node_list[0]
        last_node = self.node_list[len(self.node_list) - 1]
        self.distance += self.instance.distance_matrix[last_node][first_node]
