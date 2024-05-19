from CalculatorDistance import CalculatorDistance


class Instance:
    def __init__(self, node_list: list[float], latitude: list[float], longitude: list[float]):
        self.node_list: list[float] = node_list
        self.latitude: list[float] = latitude
        self.longitude: list[float] = longitude
        self.distance_matrix: list[list[float]] = CalculatorDistance.calculate_euclidean_distance_matrix(self.latitude,
                                                                                                         self.longitude)

    @staticmethod
    def read_instance(file_path: str):
        node_list = []
        latitude = []
        longitude = []

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
                node_list.append(node)
                latitude.append(lat)
                longitude.append(lon)

            # crear un objeto instancia y pasarle los 3 del return
            instancia = Instance(node_list, latitude, longitude)

        return instancia
