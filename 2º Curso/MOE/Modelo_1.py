from scipy.optimize import linprog

obj = [3, -5, 1]
lhs_eq = [[1, 0, -1], [3, 2, -7]]
rhs_eq = [[1], [5]]
bnd = [(0, float('inf')), (0, float('inf')), (0, float('inf'))]

opt = linprog(c= obj, A_eq= lhs_eq, b_eq= rhs_eq, bounds= bnd)

print(opt.fun)          # -660190811162.1064
print(opt.success)      # False ........................................ Que salga False significa que no hay un caso óptimo pero está bien planteado
print(opt.x)            # [1.10031802e+11 2.20063604e+11 1.10031802e+11]