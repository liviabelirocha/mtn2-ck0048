import math
import numpy as np

arrayMatriz = [
    [16.08, -7.98, 0,0,0,0,0],
    [-7.98, 16.08, -7.98, 0,0,0,0],
    [0,-7.98, 16.08, -7.98, 0,0,0],
    [0,0,-7.98, 16.08, -7.98, 0,0],
    [0,0,0,-7.98, 16.08, -7.98, 0],
    [0,0,0,0,-7.98, 16.08, -7.98,],
    [0,0,0,0,0,-7.98, 16.08]
]

arrayB = [0, 0, 0, 0, 0, 0, 7.98]

A = np.array(arrayMatriz)
b = np.array(arrayB)
x = np.linalg.solve(A, b)

arrayExato = []

i = 0.125
while(i < 1):
    equation = (math.exp(-i) - math.exp(i))/(math.exp(-1) - math.exp(1))
    arrayExato.append(equation)
    i += 0.125

for i in range(0, len(arrayExato)):
    erroRelativoObtido = (x[i]-arrayExato[i])/x[i]
    print("Valor exato: ", arrayExato[i], "| Valor obtido: ", x[i], "| Erro relativo: ", erroRelativoObtido)