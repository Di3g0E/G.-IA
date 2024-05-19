from ConstructiveRANDOM import ConstructiveRANDOM
from LocalSearch1x1 import LocalSearch1x1
from AlgorithmGRASP import AlgorithmGRASP
from Instance import Instance


if __name__ == "__main__":
    instance = Instance.read_instance("104_Mostoles_coordenadas.txt")
    constructive = ConstructiveRANDOM()
    improvement = LocalSearch1x1()
    algorithm = AlgorithmGRASP(constructive, improvement).execute(instance)
