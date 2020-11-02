import math

valoresDeltaT = [0.1, 0.01, 0.001, 0.0001]

v = 5       #vS0
m = 2
k = 0.25
g = 10
y = 200     #yS0

numIteracoes = 0

v_def = v
y_def = y

alturasMaximas = []
tempoAteAlturaMax = []

velocidadesNoImpacto = []
ultimosY = []
tempoAteImpacto = []

SiV = []
SiY = []

# Iterar entre os valores de deltaT
for i in range(0, 4):
    numIteracoes = 3
    v = 5
    y = 200
    
    pontosV = []
    pontosY = []
    
    for j in range(0,3):
        f_v_1 = -g - ((k/m)*v)
        f_y_1 = v
        
        vS2 = v + (valoresDeltaT[i]/2)*(f_v_1)
        yS2 = y + (valoresDeltaT[i]/2)*(f_y_1)
        
        f_v_2 = -g - ((k/m)*vS2)
        f_y_2 = vS2
        
        vS3 = v + (valoresDeltaT[i]/2)*(f_v_2)
        yS3 = y + (valoresDeltaT[i]/2)*(f_y_2)
        
        f_v_3 = -g - ((k/m)*vS3)
        f_y_3 = vS3
        
        vS4 = v + (valoresDeltaT[i])*(f_v_3)
        yS4 = y + (valoresDeltaT[i])*(f_y_3)
        
        f_v_4 = -g - ((k/m)*vS4)
        f_y_4 = vS4
        
        # Na primeira iteração f_v_1 é a condição inicial, f_v_2 é S_{i+1/2}, f_v_3 é S_{i+1/2}, f_v_4 é S_{i}
        # Aqui iremos gerar o próximo número utilizando F(S_{0}, t_{0}, F(S_{1/2}, t_{1/2}, F(S_{1/2}, t_{1/2}, F(S_{1}, t_{1})
        v = v + (valoresDeltaT[i]) * ((1/6)*f_v_1 + (2/6)*f_v_2 + (2/6)*f_v_3 + (1/6)*f_v_4)
        y = y + (valoresDeltaT[i]) * ((1/6)*f_y_1 + (2/6)*f_y_2 + (2/6)*f_y_3 + (1/6)*f_y_4)
                
        pontosV.append(v)
        pontosY.append(y)
    
    print("pontosY: ", pontosV,"| pontosY: ", pontosY)
    
    
    # Definições dos F(S_{i}, t_{i})

    f_v_1 = -g - ((k/m)*v_def)
    f_y_1 = v_def

    f_v_2 = -g - ((k/m)*pontosV[0])
    f_y_2 = pontosV[0]
    
    f_v_3 = -g - ((k/m*pontosV[1]))
    f_y_3 = pontosV[1]
    
    f_v_4 = -g - ((k/m)*pontosV[2])
    f_y_4 = pontosV[2]
    
    
    vS4 = pontosV[2]
    
    v = vS4

    while y > 0:
        vPassado = v
        
        numIteracoes += 1
        
        # Predição -----------------------------
        vS5 = vS4 + (valoresDeltaT[i]/24) * (-9*f_v_1 + 37*f_v_2 - 59 *f_v_3 + 55*f_v_4)
        
        yS5 = y + (valoresDeltaT[i]/24) * (-9*f_y_1 + 37*f_y_2 - 59 *f_y_3 + 55*f_y_4)
        
        f_v_5 = -g - ((k/m)*vS5)
        f_y_5 = vS5
        
        # Correção -----------------------------
        v = vS4 + (valoresDeltaT[i]/24) * (f_v_2 - 5*f_v_3 + 19 *f_v_4 + 9*f_v_5)
        
        y = y + (valoresDeltaT[i]/24) * (f_y_2 - 5*f_y_3 + 19 *f_y_4 + 9*f_y_5)
        

        if (v < 0 and vPassado >= 0) or (v > 0 and vPassado <= 0):
            alturasMaximas.append(y)
            tempoAteAlturaMax.append(numIteracoes*valoresDeltaT[i])
            
       
        f_v_1 = f_v_2
        f_v_2 = f_v_3
        f_v_3 = f_v_4
        f_v_4 = f_v_5
        
        f_y_1 = f_y_2
        f_y_2 = f_y_3
        f_y_3 = f_y_4
        f_y_4 = f_y_5
        
        vS4 = vS5

        yS4 = yS5

    
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
    