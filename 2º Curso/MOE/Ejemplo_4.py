from scipy.optimize import linprog

obj = [24, 18]
lhs_ineq = [[3, 4], [3, 3], [4, 2]]
rhs_ineq = [12, 10, 8]
bnd = [(0, float('inf'))]

opt = linprog(c = obj, A_ub = lhs_ineq, b_ub = rhs_ineq, bounds = bnd)

print(opt.fun)          # 1.1608878899858428e-11
print(opt.success)      # True
print(opt.x, '\n')      # [3.19862648e-13 2.18454186e-13]


# Problema dual
obj = [12, 10, 8]
lhs_ineq = [[3, 3, 4], [4, 3, 2]]
rhs_ineq = [24, 18]
bnd = [(0, float('inf'))]

opt = linprog(c = obj, A_ub = lhs_ineq, b_ub = rhs_ineq, bounds = bnd)

print(opt.fun)          # 1.9878751884296933e-11
print(opt.success)      # True
print(opt.x)            # [2.86789645e-13 1.90749136e-13 1.81622310e-12]
