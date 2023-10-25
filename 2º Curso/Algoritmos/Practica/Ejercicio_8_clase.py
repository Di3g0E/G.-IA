# Queremos calcular x^(a), con a entero. Un cálculo iterativo supondría a-1 productos. Supongamos que, para minimizar
# el coste, queremos reducir el número requerido de productos. Idea un algoritmo basado en divide y vencerás que calcule
# x^(a) con un menor número de productos que le caso iterativo.

x = int(input('Escribe la base del exponente:'))
a = int(input('Escribe el valor del exponente:'))

def func(x, a):
    if a == 0:
        return 1
    elif a == 1:
        return x
    elif a % 2 == 0:
        aux = func(x, a//2)
        aux *= aux
        return aux
    else:
        aux = func(x, a-1) * x
        return aux

sol = func(x, a)
print(sol)