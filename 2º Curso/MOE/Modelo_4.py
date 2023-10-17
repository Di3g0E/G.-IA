from scipy.optimize import linprog

obj = [-4, -7, -6, -5, -4]
lhs_ineq = [[5, 8, 3, 2, 7], [1, 8, 6, 5, 4]]
rhs_ineq = [112, 109]
bnd = [(0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf'))]

opt = linprog(c = obj, A_ub = lhs_ineq, b_ub = rhs_ineq, bounds = bnd)

print(opt.fun)          # -153.60869564716793
print(opt.success)      # True
print(opt.x)            # [1.48695652e+01 1.80664878e-11 5.28678205e-10 1.88260870e+01 1.21334591e-12]