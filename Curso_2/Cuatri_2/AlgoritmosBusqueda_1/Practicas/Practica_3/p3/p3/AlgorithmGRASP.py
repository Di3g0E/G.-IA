import Constructive
import Improvement
import Instance
import Solution
from Algorithm import Algorithm


class AlgorithmGRASP(Algorithm):
    def __init__(self, constructive: Constructive, improvement: Improvement):
        self.constructive: Constructive = constructive
        self.improvement: Improvement = improvement
        self.best_solution: Solution = None # noqa # Quita el warning de estar igualando con el none.

    def execute(self, instance: Instance):  # Lo heredas y lo sobrescribes.
        for i in range(10):
            solution: Solution = self.constructive.construct(instance)
            self.improvement.improve(solution)
            self.compare(solution)

    def compare(self, solution: Solution):
        if self.best_solution is None:
            self.best_solution = solution
        elif self.best_solution.compare(solution) == -1:
            self.best_solution = solution
