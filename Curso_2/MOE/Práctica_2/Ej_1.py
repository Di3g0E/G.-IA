'''
Primal
P: min 7x1 + x2 + 5x3
subject to:  x1 -  x2 + 3x3 >= 10  <=>  -x1 +  x2 - 3x3 <= -10
            5x1 + 2x2 - x3 >= 6  <=>  -5x1 - 2x2 + x3 <= -6
             x1,   x2,  x3 >= 0
'''

'''
Dual
P: max 10y1 + 6y2
subject to:  y1 + 5y2 >= 7
            -y1 + 2y2 >= 1
            3y1 -  y2 >= 5
            y1, y2 <= 0
'''


from scipy.optimize import linprog
import numpy as np

# Primal
obj_p = [7, 1, 5]
lhs_ineq_p = [[-1, 1, -3], [-5, -2, 1]]
rhs_ineq_p = [-10, -6]
bnd_p = [(0,float('inf')), (0,float('inf')), (0,float('inf'))]

opt = linprog(c=obj_p, A_ub=lhs_ineq_p, b_ub=rhs_ineq_p, bounds=bnd_p)

print(opt.fun)          # 25.999999903497027
print(opt.success)      # True
print(opt.x, '\n')      # [1.74999999e+00 1.85667727e-08 2.74999999e+00]


# Dual
obj_d = rhs_ineq_p
lhs_ineq_d = np.transpose(lhs_ineq_p)
lhs_ineq_d_n = np.negative(lhs_ineq_d)
rhs_ineq_d = obj_p
bnd_d = [(0,float('inf')), (0,float('inf'))]

opt = linprog(c = obj_d, A_ub = lhs_ineq_d_n, b_ub = rhs_ineq_d, bounds=bnd_d)

print(opt.fun)          # -25.9999999215443
print(opt.success)      # True
print(opt.x)            # [1.99999999 1.        ]