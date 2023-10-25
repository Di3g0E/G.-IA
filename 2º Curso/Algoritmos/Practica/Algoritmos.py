

def mochila():
# Descripción: Este programa guarda los valores que nos interesan maximizando o minimizando el valor de la lista en función del peso de cada elem. añadido hasta un máximo dado

# Input:
    num_elem, peso_max = map(int, input().strip().split())      # Recibe el num de elem. que hay y el peso máx. que puede soportar la mochila
    general = []                                                # Crea la lista en la que se van a guardar toda la info. de los elementos
    for i in range(num_elem):
        elem, p, v = map(str, input().strip().split())          # Recibe cada elem. con su peso y valor asociados
        general.append((int(v)/int(p), int(p), int(v), elem))   # Guarda en una lista una tupla con el primer valor = a la relación entre valor-peso y el resto de info. relevante

# Programa Principal:
    bag = []                                                    # Crea una lista mochila para guardar nuestros elem.
    peso_bag, valor_bag, i = 0, 0, 0                            # Inicializa a '0' el peso de la mochila, el valor de la mochila y el índice que se va a mover por la lista general de elem.

    general.sort(reverse=True)                                  # Ordena la lista general de mayor a menor para guardar los elem. con mayor relación valor-peso en nuestra mochila
    while peso_bag < peso_max:                                  # Mientras el peso de la mochila no supere el peso máx.

        if (peso_bag + general[i][1]) < peso_max:               # Si el siguiente elem. entra entero en la mochila
            bag.append(general[i][3])                           # Se añade a la mochila el nombre del elem.
            valor_bag += general[i][2]                          # Se suma su valor al valor de la mochila
            peso_bag += general[i][1]                           # Se suma su peso a la mochila
            i += 1                                              # El índice avanza una posición

        else:                                                   # Si el siguiente elem. no entra entero en la mochila
            particion = (peso_max - peso_bag) / general[i][1]   # Se calcula la parte del elem. que sí entra
            bag.append(general[i][3])                           # Se añade el elem. a la mochila
            valor_bag += general[i][2] * particion              # Se suma la parte del valor del elem. que sí entra en la mochila
            peso_bag = peso_max                                 # El peso de la mochila se iguala al peso máx.

# Output:
    return bag, valor_bag                                       # Devuelve la mochila y su valor


def plazo_fijo():
# Descripción: Este programa clacula el beneficio máximo de una lista de tareas con un plazo fijo, si dos tareas tienen el mismo plazo prioriza realizar la tarea con mayor beneficio

# Input:
    num_tareas = int(input())                                   # Recibe el núm. de tareas
    tareas = []                                                 # Crea la lista de tareas
    for i in range(num_tareas):
        b, p = map(int, input().strip().split())                # Recibe el beneficio de cada tarea y su plazo para llevarla a cabo
        tareas.append((b, p))                                   # Guarda en la lista una tupla con el beneficio de cada tarea y el plazo para realizarla

# Programa Principal:
    completadas = []                                            # Crea una lista con las tareas que se han completado
    beneficio_total = 0                                         # Inicializa a '0' el beneficio total

    tareas.sort(reverse=True)                                   # Ordena la lista por el beneficio de mayor a menor
    for i in range(num_tareas):
        if tareas[i][1] not in completadas:                     # Si el plazo de la tarea no está en la lista de tareas completadas
            completadas.append(tareas[i][1])                    # Añade el plazo a la lista de tareas completadas
            beneficio_total += tareas[i][0]                     # Suma su beneficio al beneficio total

# Output:
    return beneficio_total                                      # Devuelve el veneficio total alcanzado


def tiepos_espera():
# Descripción: Este programa calcula el tiempo mínimo que deben esperar los clientes reordenándolos por el tiempo que le llevará atender a cada cliente teniendo en cuenta que cada cliente tiene que esperar su tiempo de espera más los tiempos de los clientes que tenga delante

# Input:
    num_clientes = int(input())                                 # Recibe el núm. de clientes
    clientes = []                                               # Crea la lista de clientes
    for i in range(num_clientes):
        c, e = map(int, input().strip().split())                # Recibe el cliente y el tiempo de espera
        clientes.append((e, c))                                 # Guarda las tuplas del tiempo de espera de cada cliente y el nombre del cliente

# Programa Principal:
    espera = 0                                                  # Inicializa a '0' el tiempo de espera total
    orden_clientes = []                                         # Crea una lista con el orden de los clientes

    clientes.sort()                                             # Ordena los tiempos de espera de menor a mayor
    for i in range(num_clientes):
        espera += clientes[i][0] * (num_clientes - i)           # Suma el tiempo de espera y lo multiplica por la cantidad de clientes que quedan
        orden_clientes.append(clientes[i][1])                   # Guarda en la lista la posición de cada cliente
    espera /= num_clientes                                      # Calcula la espera media de los clientes

# Output:
    return orden_clientes, espera                               # Devuelve el orden de los clientes y el tiempo de espera medio de los clientes


def kruskal():
# Descripción: Este programa busca el recorrido del grafo con menor o mayor valor, en este caso con menor valor. Se deben visitar todos los nodos.
# Subprogramas:
    def actualizar_indices(lista, indice_origen, indice_final): # Iguala los índices de los nodos ya conectados
        for i in range(len(lista)):
            if indice_origen == lista[i]:                       # Para todos los valores que sean iguales al valor de origen se cambian por el índice_final
                lista[i] = indice_final
        return lista                                            # Devuelve la lista actualizada

# Input:
    num_nodos, num_edges = map(int, input().strip().split())    # Recibe el núm. de nodos y aristas del grafo
    edges = []                                                  # Crea una lista que guarda la info. de cada arista
    for i in range(num_edges):
        e1, e2, v = map(int, input().strip().split())           # Recibe el nodo de origen, el final y el valor de cada arista
        edges.append((v, e1, e2))                               # Guarda las tuplas con el valor de la arista, el nodo origen y el nodo final

# Programa Principal:
    indices = list(range(num_nodos))                            # Lista que indica el índice de cada nodo
    cont = num_nodos                                            # Contador que indica cuántos nodos quedan por visitar
    coste = 0                                                   # Contador que indica el coste total del grafo visitado
    i = 0                                                       # Índice que indica el nodo por el que vamos de la lista

    edges.sort()                                                # Ordena las aristas de menor valor a mayor
    while cont > 1 and i < len(edges):                          # Mientras los nodos que quedan por visitar no sean menor que 1 y el índice no sea mayor que la cantidad de aristas
        v, o, f = edges[i]                                      # Sacamos los elementos de las tuplas en las variables valor (v), origen (o) y final (f)

        if indices[o] != indices[f]:                            # Si los índices de los nodos no coinciden es que no están unidos todavía
            coste += v                                          # Suma el valor de la arista al coste del grafo
            cont -= 1                                           # Resta 1 a la cantidad de nodos que faltan por conectar
            indices = actualizar_indices(indices, indices[o], indices[f])
        i += 1                                                  # Incrementa 1 el valor del índice 'i'

# Output:
    return coste                                                # Devuelve el coste mín. total del grafo conectado


def djikstra():
# Descripción: Este programa recorre el grafo desde un nodo inicial indicado pasando por todos los nodos que estén conectados calculando el recorrido mínimo a cada nodo desde el nodo inicial

# Input:
    nodo_inicial = str(input())                                 # Recibe el nombre del nodo inicial
    grafo = input()                                             # Recibe un diccionario de diccionarios con los nodos conectados y los valores de sus aristas

# Programa Principal:
    distancia = {node: float('inf') for node in grafo}          # Inicializa a 'infinito' un diccionario con la distancia de los nodos al nodo origen
    distancia[nodo_inicial] = 0                                 # Indica que la distancia del nodo inicial a sí mismo es 0
    visitados = [nodo_inicial]                                  # Crea una lista que guardará los nodos visitados
    flag = False                                                # Guarda para el bucle while que sale del bucle si no todos los nodos están conectados

    while len(visitados) < len(grafo):                          # Mientras la lista de nodos visitados tenga menos nodos que el grafo o ya no queden nodos conectados



# Prueba programas:

#print('Programa Mochila:')
#elem_mochila, val_mochila = mochila()
#print('\nLos elem. de la mochila son: ', *elem_mochila), print(f'El valor total de la mochila es: {val_mochila:.2f}\n')
'''
Input:
5 100
boli 10 20
vaso 20 30
luz 30 66
bote 40 40
papel 50 60

Output:
Los elem. de la mochila son:  luz boli vaso papel
El valor total de la mochila es: 164.00
'''


#print('Programa plazo_fijo:')
#beneficio = plazo_fijo()
#print(f'\nEl beneficio total es: {beneficio}\n')
'''
Input:
4
50 2
10 1
15 2
30 1

Output:
El beneficio total es: 80
'''


#print('Programa tiempos_espera:')
#orden, tiempo = tiepos_espera()
#print('El orden de los clientes es: ', *orden), print(f'El tiempo medio por cada cliente es: {tiempo:.2f}')
'''
Input:
3
1 5
2 10
3 3

Output:
El orden de los clientes es:  3 1 2
El tiempo medio por cada cliente es: 9.67
'''


#print('Programa Kruskal:')
#coste = kruskal()
#print(f'\nEl coste minimo del grafo conectado es: {coste}')
'''
Input:
10 15
0 1 67
0 4 75
1 5 48
1 6 60
2 5 38
3 7 58
3 9 34
4 5 19
4 6 137
4 7 55
4 8 76
4 9 8
5 7 111
6 8 33
6 9 4

Output:
El coste minimo del grafo conectado es: 306
'''