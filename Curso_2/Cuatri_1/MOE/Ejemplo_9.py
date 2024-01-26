from scipy.optimize import linprog

obj = [14, 24, 21, 20, 21.5, 19, 17, 30, 24, 15, 28, 20, 18.5, 19.5, 24, 28]

lhs_ineq = [[14, 24, 21, 20, 21.5, 19, 17, 30], [24, 15, 28, 20, 18.5, 19.5, 24, 28]]
rhs_ineq = [100, 48]
lhs_eq = [[14, 24], [24, 15], [21, 28], [20, 20], [21.5, 18.5], [19, 19.5], [17, 24], [30, 28]]
rhs_eq = [[22], [14], [18], [17], [15], [13], [15], [20]]
bnd = [(0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf')), (0, float('inf'))]

opt = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq, A_eq=lhs_eq, b_eq=rhs_eq, bounds=bnd)

print(opt.fun)          # -16.81818175142894
print(opt.success)      # True
print(opt.x)            # [1.10031802e+11 2.20063604e+11 1.10031802e+11]
