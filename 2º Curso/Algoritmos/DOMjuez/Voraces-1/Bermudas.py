# El programa idica si los tres grados recibidos en el imput son mayor que 0, y si la suma de los grados es mayor o menor e igual a 180

a, b, c = map(int, input().strip().split())     # Angulos de las tres islas
suma = a + b + c                                # Suma de los angulos

if a < 0 or b < 0 or c < 0: print("ERROR")      # Algún valor menor que 0
elif suma == 180: print("SI")                   # Suma diferente de 180
else:print("NO")     
