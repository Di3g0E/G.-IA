from AlgorithmGRASP import AlgorithmGRASP
from ConstructiveRANDOM import ConstructiveRANDOM
from Instance import Instance
from LocalSearch1x1 import LocalSearch1x1


def main():
    instance = Instance.read_instance("104_Mostoles_coordenadas.txt")
    constructive = ConstructiveRANDOM()
    improvement = LocalSearch1x1()
    AlgorithmGRASP(constructive, improvement).execute(instance)


if __name__ == "__main__":
    main()
