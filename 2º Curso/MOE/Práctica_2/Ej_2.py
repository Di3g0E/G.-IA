'''
Primal
max Z = 2x1 + 4x2 + 3x3
subject to:  3x1 + 4x2 + 2x3 <= 60
             2x1 +  x2 + 2x3 <= 40
              x1 + 3x2 + 2x3 <= 80
             x1, x2, x3 >= 0
'''

'''
Dual
min Z = 60y1 + 40y2 + 80y3
subject to:  3y1 + 2y2 + y3 <= 2
            4y1 + y2 + 3y3 <= 4
            2y1 + 2y2 +2y3 <= 3
            y1, y2, y3 <= 0
'''


from scipy.optimize import linprog

obj = [60, 40, 80]
lhs_ineq = [[3, 2, 1], [4, 1, 3], [2, 2, 2]]
rhs_ineq = [2, 4, 3]
bnd = [(-float('inf'), 0), (-float('inf'), 0), (-float('inf'), 0)]

opt = linprog(c = obj, A_ub = lhs_ineq, b_ub = rhs_ineq, bounds=bnd)

print(opt.fun)          # -34259235868797.926
print(opt.success)      # False
print(opt.x,)           # [-2.64440182e+11 -4.28293014e+11 -1.57638046e+10]