from scipy.optimize import linprog

obj = [1, 1, 1, 1]
lhs_ineq = [[1, 0, 0,  0], [1, 1, 0,  0], [1, 1, 1,  0], [0, 1, 1,  1]]
rhs_ineq = [2, 3, 5, 3]
lhs_eq = [[0, 0, 0, 1]]
rhs_eq = [0]

opt = linprog(c = obj, A_ub = lhs_ineq, b_ub = rhs_ineq, A_eq = lhs_eq, b_eq = rhs_eq)

print(opt.fun)          # 1.1608878899858428e-11
print(opt.success)      # True
print(opt.x, '\n')      # [3.19862648e-13 2.18454186e-13]