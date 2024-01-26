from scipy.optimize import linprog

obj = [-24, -18]
lhs_ineq = [[3, 4], [3, 3], [4, 2]]
rhs_ineq = [12, 10, 8]
bnd = [(0, float('inf'))]

opt = linprog(c= obj, A_ub= lhs_ineq, b_ub= rhs_ineq, bounds= bnd)

print(opt.fun)          # -62.39999979216307
print(opt.success)      # True
print(opt.x)            # [0.8        2.39999999]