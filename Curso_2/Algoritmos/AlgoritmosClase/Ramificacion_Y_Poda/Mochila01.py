'''from collections import deque

def initSol(cost_matrix):

def cost(sol, cost_matrix):

def isSol(sol, n):

def bound(u, n, W, arr):
    if u[3] >= W:
        return 0
    profitBound = u[1]
    j = u[0] + 1
    totWeight = int(u[3])
    while j < n and totWeight + int(arr[j][1]) <= W:
        totWeight += int(arr[j][1])
        profitBound += arr[j][2]
        j += 1

    if j < n:
        profitBound += int((W - totWeight) * arr[j][2] / arr[j][1])

    return profitBound

def complete(sol, n):

def knapsack_sol(W, arr, n):
    arr.sort(reverse=True)
    q = deque()
    node_u = (-1, 0, 0, 0)  # nivel de exploración, beneficio, lím para el nodo, coste
    q.append(node_u)
    max = 0

    while q:
        node_u = q.pop()
        if node_u[0] == n - 1:
            continue
            
        new_node_wheight = node_u[3] + arr[node_u[0] + 1][1]  # 'node_u[0] + 1' avanza al siguiente nivel de exploración
        new_node_profit = node_u[1] + arr[node_u[0] + 1][2]
        new_node_level = node_u[0] + 1
        node_v = (new_node_level, new_node_profit, bound((new_node_level, new_node_profit, 0, new_node_wheight), n, W, arr),new_node_wheight)
        
        if node_v[3] <= W and node_v[1] > max:
            max = node_v[1]

        if node_v[2] < max:
            q.append(node_v)

        aux_level = node_u[0] + 1
        aux_profit = node_u[1]
        aux_wheight = node_u[3]
        aux_node = (aux_level, aux_profit, 0, aux_wheight)
        node_v = (node_u[0] + 1, node_u[1], bound(aux_node, n, W, arr), node_u[3])

        if node_v[2] > max:
            q.append(node_v)

    pass


if __name__ == '__main__':
    W = 15
    arr = [(10 / 2, 2, 10), (10 / 4, 4, 10), (12 / 6, 6, 12), (18 / 9, 9, 18)]
    n = len(arr)
    print(knapsack_sol(W, arr, n))

'''
from collections import deque

def bound(u, n, W, arr):
    if u[3] >= W:
        return 0

    profitBound = u[1]
    j = u[0] + 1
    totWeight = int(u[3])
    while j < n and totWeight + int(arr[j][1]) <= W:
        totWeight += int(arr[j][1])
        profitBound += arr[j][2]
        j+= 1

    if j < n:
        profitBound += int((W - totWeight) * arr[j][2] / arr[j][1])
        return profitBound

def knapsnack_solution(W, arr, n):
    arr.sort(reverse = True) #orden descendente
    q = deque()
    node_u = (-1, 0, 0,0) #nivel de exploracion, beneficio, bound, cost
    q.append(node_u)
    max_profit = 0

    while q:
        node_u = q.pop()
        if node_u[0] == n - 1:
            continue
        new_node_weight = node_u[3] + arr[node_u[0] + 1][1]
        new_node_profit = node_u[1] + arr[node_u[0] + 1][2]
        new_node_level = node_u[0] + 1
        node_v = (new_node_level, new_node_profit, bound((new_node_level, new_node_profit, 0, new_node_weight), n, W, arr), new_node_weight)

        if node_v[3] <= W and node_v[1] > max_profit:
            max_profit = node_v[1]

        if node_v[2] > max_profit:
            q.append(node_v)

        aux_level = node_u[0] + 1
        aux_profit = node_u[1]
        aux_weight = node_u[3]
        aux_node = (aux_level, aux_profit, 0, aux_weight)
        node_v = (node_u[0] + 1, node_u[1], bound(aux_node, n, W, arr), node_u[3])

        if node_v[1] > aux_profit:
            q.append(node_v)

    return max_profit

    pass


if __name__ == '__main__':
    W = 15
    arr = [(10/2, 2, 10), (10/4, 4, 10), (12/6, 6, 12),(18/9, 9, 18)] #ratio, peso, beneficio (en cada tupla)
    n = len(arr)
    sol = knapsnack_solution(W, arr, n)
print(sol)
