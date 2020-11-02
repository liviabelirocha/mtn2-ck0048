import math

valoresDeltaT = [0.1, 0.01, 0.001, 0.0001]

v = 5
m = 2
k = 0.25
g = 10
y = 200

numIteracoes = 0

novosV = []
novosY = []
alturasMaximas = []
tempoAteAlturaMax = []
tempoTotalAteQueda = []
velocidadeNoImpacto = []

for i in range(0, 4):
    numIteracoes = 0
    v = 5
    y = 200
    
    while (v > 0):
        vPassado = v
        numIteracoes += 1
        v = (m / ( m + (k * valoresDeltaT[i]) ) )*( vPassado - (g*valoresDeltaT[i] ))
        y = y + ( ( m * valoresDeltaT[i] ) / (m + k * (valoresDeltaT[i]) ) ) * (vPassado - g * ( valoresDeltaT[i] ) )
        
    alturasMaximas.append(y)
    tempoAteAlturaMax.append(numIteracoes*valoresDeltaT[i])
    
    numIteracoes = 0
    v = 5
    y = 200
    
    while (y > 0):
        vPassado = v
        numIteracoes += 1
        v = (m / ( m + (k * valoresDeltaT[i]) ) )*( vPassado - (g*valoresDeltaT[i] ))
        y = y + ( ( m * valoresDeltaT[i] ) / (m + k * (valoresDeltaT[i]) ) ) * (vPassado - g * ( valoresDeltaT[i] ) )
        
    velocidadeNoImpacto.append(v)
    tempoTotalAteQueda.append(numIteracoes*valoresDeltaT[i])

for index, altura in enumerate(alturasMaximas):
    print(f"Para o valor de delta T igual a {valoresDeltaT[index]} temos:")
    tempo = tempoAteAlturaMax[index]
    
    velocidadeImpacto = velocidadeNoImpacto[index]
    tempoQueda = tempoTotalAteQueda[index]
    
    print(f'Altura máxima: {altura}')
    print(f'Tempo decorrido até altura máxima: {tempo}')
    print(f'Velocidade no momento do impacto: {velocidadeImpacto}')
    print(f'Tempo total até impacto: {tempoQueda}')
    
    print("")