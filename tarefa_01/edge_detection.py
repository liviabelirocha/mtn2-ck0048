import cv2

def derivative(back, front):
    value = (float(front) - float(back))/2
    return value

def doResize(src):
    percentage = 55
    newWidth = int(src.shape[1] * percentage / 100)
    newHeight = int(src.shape[0] * percentage / 100)
    newDimensions = (newWidth, newHeight)
    
    src = cv2.resize(src, newDimensions)
    return src

def convertToGrayScale(src):
    src = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
    return src

def createEdgeDetection(src, srcWithBorder, dimensions):
    for i in range(1, dimensions[0]): # Começando com 1 para evitar a bora criada. Lembrando que 'dimensions[0] = height' e 'dimensions[1] = width'
        for j in range(1, dimensions[1]):
            finalValue = derivative(srcWithBorder[i-1][j], srcWithBorder[i+1][j]) - derivative(srcWithBorder[i][j-1], srcWithBorder[i][j+1])
            src[i][j] = finalValue
    return

def applyBlur(src):
    src = cv2.GaussianBlur(src, (5,5), 0)
    return src



# Ler imagem para 'img'
original = cv2.imread('tree.png')

# Redimensionar
resized = doResize(original)

# Borrar imagem
blurred = applyBlur(resized)

# Converter imagem para escala de cinza
modified = convertToGrayScale(blurred)

# Colocar informações da imagem em um vetor; dimensions[0] = height, dimensions[1] = width, dimensions[2] = channels
dimensions = modified.shape

# Colocando tiras de pixels com valor '0' em escala de cinza nas bordas
modifiedWithBorder = cv2.copyMakeBorder(modified,1, 1, 1, 1, cv2.BORDER_CONSTANT, value=[0,0,0]) # argumentos (src, tam_top, tam_bot, tam_left, tam_right, type of border, value_of_pixel)


# Cria imagem com detecção de bordas
createEdgeDetection(modified, modifiedWithBorder, dimensions)

'''
    original = imagem original
    resized = original redimensionada
    blurred = resized borrada
    modified = blurred convertida para escala de cinza

    dimensions = dimensões de 'modified'
'''

# Mostrar imagens
cv2.imshow('Original', resized)
cv2.imshow('Detecção de Bordas', modified)

cv2.waitKey(0)
cv2.destroyAllWindows()
