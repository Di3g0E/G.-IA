import heapq

'''
Generamos la solución inicial basándonos en el algoritmo voraz
de las transparencias: elegir la diagonal 
(podríamos partir también de lo que comentamos en clase: asignar la tarea de menor valor a cada agente)
'''
def initSol(cost_matrix):
	initial_sol = []
	cost = 0
	# Seleccionamos la diagonal de la matriz como primera aproximación
	for i in range(len(cost_matrix)):
		initial_sol.append(i)
		cost += cost_matrix[i][i]
	return cost, initial_sol

'''
Función que calcula el coste de la solución actual
'''
def cost(sol, cost_matrix):
	cost = 0
	for i in range(len(sol)):
		cost += cost_matrix[i][sol[i]]
	return cost

'''
Función que evalúa si ya hemos alcanzado una solución, es decir:
hemos asignado todas las tareas
'''
def isSol(sol, n):
	return len(sol[1]) == n


'''
Esta función calcula la cota inferior de la solución actual,
asignando la tarea sin asignar de menor coste a cada agente libre
'''
def lowerBound(sol, cost_matrix):
	assignedTasks = sol.copy()
	bound = cost(sol, cost_matrix)
	for e in range(len(cost_matrix)):
		min_cost = float('inf')
		if e not in assignedTasks:
			for i in range(len(cost_matrix)):
				if (cost_matrix[i][e] < min_cost):
					min_cost = cost_matrix[i][e]
			assignedTasks.append(e)
			bound += min_cost
	return bound


'''
Esta función expande todos los hijos de un nodo concreto,
siendo un nodo una solución parcial
'''
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

'''
Este método implementa el Branch and Bound completo
utilizando una cola de prioridad para explorar el nodo más
prometedor en un momento dado
'''
def ByB(cost_matrix):
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

'''
Programa ppal.
'''
if __name__ == '__main__':
	cost_matrix = [
		[11, 12, 18, 40],
		[14, 15, 13, 22],
		[11, 17, 19, 23],
		[17, 14, 20, 28],
				   ]
	print(*ByB(cost_matrix))