from scipy.optimize import linprog

obj = [.6, 1]
lhs_ineq = [[-10, -4], [-5, -5], [-2, -6]]
rhs_ineq = [20, 20, 12]

bnd = [(0, float('inf')), (0, float('inf'))]
opt = linprog(c = obj, A_ub=lhs_ineq, b_ub=rhs_ineq, bounds=bnd)

print(opt.fun)          # 1.6285424449258078e-07
print(opt.success)      # True
print(opt.x)            # [2.70137849e-07 7.71535102e-10]
