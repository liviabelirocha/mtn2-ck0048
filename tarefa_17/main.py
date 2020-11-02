import math

valoresDeltaT = [0.1, 0.01, 0.001, 0.0001]

v = 5
m = 2
k = 0.25
g = 10
y = 200

numIteracoes = 0

alturasMaximas = []
tempoAteAlturaMax = []

velocidadesNoImpacto = []
ultimosY = []
tempoAteImpacto = []

for i in range(0, 4):
    numIteracoes = 0
    v = 5
    y = 200
    
    while y > 0:
        vPassado = v
        
        numIteracoes += 1
        
        f_v_1 = -g - ((k/m)*v)
        f_y_1 = v
        
        vBarraMeio = v + (valoresDeltaT[i]/2)*(f_v_1)
        yBarraMeio = y + (valoresDeltaT[i]/2)*(f_y_1)
        
        f_v_2 = -g - ((k/m*vBarraMeio))
        f_y_2 = vBarraMeio
        
        vBarraUm = v + (valoresDeltaT[i])*(f_v_1)
        yBarraUm = y + (valoresDeltaT[i])*(f_v_1)
        
        f_v_3 = -g - ((k/m)*vBarraUm)
        f_y_3 = vBarraUm
        
        v = v + (valoresDeltaT[i]) * ((1/6)*f_v_1 + (4/6)*f_v_2 + (1/6)*f_v_3)
        y = y + (valoresDeltaT[i]) * ((1/6)*f_y_1 + (4/6)*f_y_2 + (1/6)*f_y_3)
        
        if (v < 0 and vPassado > 0) or (v > 0 and vPassado <= 0):
            alturasMaximas.append(y)
            tempoAteAlturaMax.append(numIteracoes*valoresDeltaT[i])
        
    
    velocidadesNoImpacto.append(v)
    ultimosY.append(y)
    tempoAteImpacto.append(numIteracoes*valoresDeltaT[i])

for index, velocidades in enumerate(velocidadesNoImpacto):
    print(f"Para o valor de delta T igual a {valoresDeltaT[index]} temos:")
    
    tempo = tempoAteImpacto[index]
    alturaMax = alturasMaximas[index]
    tempoMax = tempoAteAlturaMax[index]
    
    print(f'Altura máxima: {alturaMax}')
    print(f'Tempo decorrido até altura máxima: {tempoMax}')
    print(f'Velocidade no momento do impacto: {velocidades}')
    print(f'Tempo total até impacto: {tempo}')
    
    print("")
    