import heapq

def initSol(cost_matrix):
    initial_sol = []
    cost = 0
    for i in range(len(cost_matrix)):
        initial_sol.append(i)
        cost += cost_matrix[i][i]
    return cost, initial_sol


def cost(sol, cost_matrix):
    cost = 0
    for i in range(len(sol)):
        cost += cost_matrix[i][sol[i]]
    return cost


def isSol(sol, n):
    return len(sol[1]) == n


def lowerBound(sol, cost_matrix):
    assignedTasks = sol.copy()
    bound = cost(sol, cost_matrix)
    for e in range(len(cost_matrix)):
        min_cost = float('inf')
        if e not in assignedTasks:
            for i in range(len(cost_matrix)):
                if cost_matrix[i][e] < min_cost:
                    min_cost = cost_matrix[i][e]
            assignedTasks.append(e)
            bound += min_cost
    return  bound


def complete(sol, n):
    childs = []
    for i in range(n):
        act_sol = sol[1].copy()
        if i not in act_sol:
            act_sol.append(i)
            lower_bound = lowerBound(act_sol, cost_matrix)
            partial_tuple = (lower_bound, act_sol)
            childs.append(partial_tuple)
    return childs



def job_assigment_BaB(cost_matrix):
    n = len(cost_matrix)
    finalSol = initSol(cost_matrix)
    upperBound = cost(finalSol[1], cost_matrix)
    q = []
    sol = (0, [])
    heapq.heappush(q, sol)
    while q:
        sol = heapq.heappop(q)
        if isSol(sol, n):
            actCost = cost(sol[1], cost_matrix)
            if actCost < upperBound:
                finalSol = sol
                upperBound = actCost
        else:
            lower_bound = lowerBound(sol[1], cost_matrix)
            if lower_bound < upperBound:
                childs = complete(sol, n)
                for child in childs:
                    heapq.heappush(q, child)
    return finalSol


if __name__ == '__main__':
    n = int(input().strip())
    dict_task = []
    for _ in range(n):
        dict_task.append(input().strip())
    dict_programmers = []
    cost_matrix = [[] for _ in range(n)]
    for i in range(n):
        line = input().strip().split()
        dict_programmers.append(line[0])
        for j in range(1, n+1):
            cost_matrix[i].append(-int(line[j]))
    sol = job_assigment_BaB(cost_matrix)
    print(-sol[0])
    for task in range(len(dict_task)):
        programmer = sol[1].index(task)
        print(dict_task[task], dict_programmers[programmer], -(cost_matrix[programmer][task]))