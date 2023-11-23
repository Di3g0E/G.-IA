from scipy.optimize import linprog

obj = [2, -1]
lhs_ineq = [[-1, 1], [1, 1], [5, 3]]
rhs_ineq = [2, 4, 15]
bnd = [(0, float('inf')), (0, float('inf'))]

opt = linprog(c = obj, A_ub = lhs_ineq, b_ub = rhs_ineq, bounds = bnd)

print(opt.fun)          # -1.999999996838361
print(opt.success)      # True
print(opt.x)            # [2.17313214e-09 2.00000000e+00]