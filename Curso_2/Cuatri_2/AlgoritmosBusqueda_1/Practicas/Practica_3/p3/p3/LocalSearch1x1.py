from Improvement import Improvement
from Solution import Solution
import copy


class LocalSearch1x1(Improvement):
    def improve(self, solution: Solution) -> Solution:
        best_solution: Solution = copy.deepcopy(solution)
        for i in range(len(solution.node_list)):
            for j in range(len(solution.node_list)):
                # Los intercambio
                temporal_position = solution.node_list[i]
                solution.node_list[i] = solution.node_list[j]
                solution.node_list[j] = temporal_position

                if solution.compare(best_solution) == -1:
                    best_solution = copy.deepcopy(solution)
        return best_solution
