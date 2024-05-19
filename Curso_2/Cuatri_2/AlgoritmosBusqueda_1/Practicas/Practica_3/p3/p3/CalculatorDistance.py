from math import sqrt


class CalculatorDistance:
    @staticmethod
    def calculate_euclidean_distance_matrix(latitudes: list[float], longitudes: list[float]) -> list[list[float]]:
        distance_matrix: list[list[float]] = []
        x: int = 0
        for latitude1, longitude1 in zip(latitudes, longitudes):
            distance_matrix.append([])
            for latitude2, longitude2 in zip(latitudes, longitudes):
                distance_matrix[x].append(
                    CalculatorDistance.calculate_euclidean_distance(latitude1, latitude2, longitude1, longitude2))
            x += 1
        return distance_matrix

    @staticmethod
    def calculate_euclidean_distance(lat_node_1: float, lat_node_2: float,
                                     long_node_1: float, long_node_2: float) -> int:
        return int(sqrt((lat_node_2 - lat_node_1)**2 + (long_node_2 - long_node_1)**2))