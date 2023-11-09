'''
Dual
min Z = 700y1 + 612y2 + 80y3 + 120y4
subject to: 16y1 + 6y2 + 3y3 >= 40
             2y1 + 3y2 + 4y4 >= 18
            y1, y4 >= 0
'''


from scipy.optimize import linprog
import numpy as np

obj = [40, 18]
lhs_ineq = [[16, 6, 3, 0], [2, 3, 0, 4]]
rhs_ineq = [700, 612, 80, 120]
bnd = [(0,float('inf')), (0,float('inf'))]

lhs_ineq_tr = np.negative(np.transpose(lhs_ineq))

opt = linprog(c = obj, A_ub = lhs_ineq_tr, b_ub = rhs_ineq, bounds=bnd)

print(opt.fun)          # 6.877616333539029e-10
print(opt.success)      # True
print(opt.x,)           # [1.69280237e-11 5.91149123e-13]