import Constructive
import Improvement
import Instance
import Solution
from Algorithm import Algorithm


class AlgorithmGRASP(Algorithm):
    def __init__(self, constructive: Constructive, improvement: Improvement):
        self.constructive: Constructive = constructive
        self.improvement: Improvement = improvement
        self.best_solution: Solution = None # noqa

    def execute(self, instance: Instance):
        for _ in range(10):
            solution: Solution = self.constructive.construct(instance)
            self.improvement.improve(Solution)
            self.compare(solution)

    def compare(self, solution: Solution):
        if self.best_solution is None:
            self.best_solution = solution
        elif self.best_solution.compare(solution) == -1:
            self.best_solution = solution
