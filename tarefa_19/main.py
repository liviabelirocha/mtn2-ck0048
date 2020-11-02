import math
import numpy as np
import sys

arrayMatriz = []

# --- Aplicação da Filosofia Central ---

# Definição dos valores para as células

celEsq = 64
celDir = celEsq
celCen = -256
celCima = 64
celBaixo = celCima

# Construção de um template padrão para o 'core' da linha (será mudado posteriormente)

construcaoMatriz = [celBaixo, 0, 0, 0, 0, 0, celEsq, celCen, celDir, 0, 0, 0, 0, 0, celCima]

# Separação dos pontos em setores para contrução da matriz de coeficientes

# Pontos do meio (os valores serão aumentados dinamicamente)
numInnerBoxInicio = 8
numInnerBoxFim = 12

# Pontos da coluna mais à esquerda
colunaEsquerda = [7, 14, 21, 28, 35]

# Pontos da coluna mais à direita
colunaDireita = [13, 20, 27, 34, 41]

# Pontos da linha mais em cima
linhaCima = [43, 47]

# Pontos da linha mais em baixo
linhaBaixo = [1, 5]

# Pontos do canto (não pertencem às colunas e linhas previamente definidas)
cantos = [0, 6, 42, 48]

# Variável para controle de quantidade de iterações para gerar todos os pontos do meio
iteracoes = 0

### O 'core' da linha se refere aos possíveis pontos que serão utilizados para a filosofia central

for i in range(0,49):
    construcaoMatriz = []

    # --- Checagem de qual setor e definição de construção do 'core' da linha ---
    
    # Pontos do meio
    if ((i >= numInnerBoxInicio) and (i <= numInnerBoxFim)):
        construcaoMatriz = [celBaixo, 0, 0, 0, 0, 0, celEsq, celCen, celDir, 0, 0, 0, 0, 0, celCima]
        iteracoes += 1
        if (iteracoes == 5) and (numInnerBoxInicio <= 29):
            numInnerBoxInicio += 7
            numInnerBoxFim += 7
            iteracoes = 0
            
    # Pontos da coluna mais à esquerda
    elif (i in colunaEsquerda):
        construcaoMatriz = [celBaixo, 0, 0, 0, 0, 0, 0, celCen, celDir, 0, 0, 0, 0, 0, celCima]
    
    # Pontos da coluna mais à direita
    elif (i in colunaDireita):
        construcaoMatriz = [celBaixo, 0, 0, 0, 0, 0, celEsq, celCen, 0, 0, 0, 0, 0, 0, celCima]
        
    # Pontos da linha mais em cima
    elif ((i >= linhaCima[0]) and (i <= linhaCima[1])):
        construcaoMatriz = [celBaixo, 0, 0, 0, 0, 0, celEsq, celCen, celDir]
    
    # Pontos da linha mais em baixo
    elif ((i >= linhaBaixo[0]) and (i <= linhaBaixo[1])):
        construcaoMatriz = [celEsq, celCen, celDir, 0, 0, 0, 0, 0, celCima]
    
    # Pontos do canto
    elif (i in cantos):
        if (i == cantos[0]):
            construcaoMatriz = [celCen, celDir, 0, 0, 0, 0, 0, celCima]
        if (i == cantos[1]):
            construcaoMatriz = [celEsq, celCen, 0, 0, 0, 0, 0, 0, celCima]
        if (i == cantos[2]):
            construcaoMatriz = [celBaixo, 0, 0, 0, 0, 0, 0, celCen, celDir]
        if (i == cantos[3]):
            construcaoMatriz = [celBaixo, 0, 0, 0, 0, 0, celEsq, celCen]

    # --- Inserir quantidade apropriada de 0's no começo e no fim da linha ---
    if (i < 7):
        for j in range(0,i-1):
            construcaoMatriz.insert(0,0)
    else:
        for j in range(0,i-7):
            construcaoMatriz.insert(0,0)
            
    tamanho = len(construcaoMatriz)

    for k in range(0,49-tamanho):
        construcaoMatriz.append(0)
    
    arrayMatriz.append(construcaoMatriz)
 
    
# Lista com os valores exatos tirados da aula 27 para comparação de precisão

arrayExato = [-0.171875, -0.21875, -0.171875, -0.21875, -0.28125, -0.21875, -0.171875, -0.21875, -0.171875]

# Preencher um vetor para representar o vetor de 'resultados'
arrayB = []

for i in range(0,49):
    arrayB.append(4)

# Solução do sistema

A = np.array(arrayMatriz)
b = np.array(arrayB)
x = np.linalg.solve(A, b)

# Seleção dos valores obtidos do sistema para comparação de precisão

arrayObtido = [x[8],x[10],x[12],x[22],x[24],x[26],x[36],x[38],x[40]]

# --- Mostrar dados obtidos sobre os valores e erros ---

for exato, obtido in zip(arrayExato, arrayObtido):
    erroRelativoObtido = (exato - obtido)/obtido
    
    print("Valor exato: ", exato, "| Valor obtido: ", obtido, "| Erro relativo: ", erroRelativoObtido)