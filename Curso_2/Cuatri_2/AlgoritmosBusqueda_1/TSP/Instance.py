from CalculatorDistance import CalculatorDistance


class Instance:

    def __init__(self, latitude: list[int], longitude: list[int], node_list: list[int]):
        self.node_list: list[int] = node_list
        self.latitude: list[int] = latitude
        self.longitude: list[int] = longitude
        self.distance_matrix: list[list[int]] = CalculatorDistance.calculate_euclidean_distance_matrix(self.latitude,
                                                                                                       self.longitude)
    def read_instance(self, file_path: str):
        self.node_list = []
        self.latitude = []
        self.longitude = []

        with open(file_path, 'r') as file:
            lines = file.readlines()

            # Comenzar a leer desde la segunda línea para omitir la fila de cabecera
            for line in lines[1:]:
                # Eliminar espacios en blanco y dividir la línea en valores
                values = line.strip().split(';')

                # Convertir los valores a los tipos necesarios
                node = int(values[0])
                lat = float(values[1])
                lon = float(values[2])

                # Agregar los valores a las listas correspondientes
                self.node_list.append(node)
                self.latitude.append(lat)
                self.longitude.append(lon)

        return self.latitude, self.longitude, self.node_list
