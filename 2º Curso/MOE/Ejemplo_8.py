from scipy.optimize import linprog

obj = [350, 470, 610]
lhs_ineq = [[1, 1, 0], [0, 0, 1], [10, 15, 20]]
rhs_ineq = [120, 48, 2000]

bnd = [(0, float('inf')), (0, float('inf')), (0, float('inf'))]
opt = linprog(c = obj, A_ub= lhs_ineq, b_ub= rhs_ineq, bounds= bnd)

print(opt.fun)          # 4.1425610735294707e-11
print(opt.success)      # True
print(opt.x)            # [3.25262405e-14 3.98524229e-14 1.85422751e-14]
