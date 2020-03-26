import sys
import cv2 as cv
import numpy as np

def is_edge(i, j, dimention):
    if (j == 0) or (j+1 >= dimention) or (i == 0) or (i+1 >= dimention):
        return True
    return False

def which_edge(i, j, dimention, img):
    v = []
    #Checando os cantos
    if j == 0 and i == 0:
        v = [0, img[i][j+1], 0, img[i+1][j]]
    elif i == 0 and j+1 >= dimention:
        v = [img[j-1][i], 0, 0, img[i+1][j]]
    elif i+1 >= dimention and j == 0:
        v = [0, img[i][j+1], img[i-1][j], 0]
    elif i+1 >= dimention and j+1 >= dimention:
        v = [img[j-1][i], 0, img[i-1][j], 0]
    #Checando as outras bordas
    elif j == 0:
        v = [0, img[i][j+1], img[i-1][j], img[i+1][j]]
    elif j+1 >= dimention:
        v = [img[i][j-1], 0, img[i-1][j], img[i+1][j]]
    elif i == 0:
        v = [img[i][j-1], img[i][j+1], 0, img[i+1][j]]
    elif i+1 >= dimention:
        v = [img[i][j-1], img[i][j+1], img[i-1][j], 0]
    return v

def derivative(behind, front):
    return (float(front)-float(behind))/2

def main(argv):

    if len(argv) < 1:
        print ('(ERRO) Passe a imagem como parâmetro!')
        return -1

    #Leitura da imagem
    src = cv.imread(argv[0], cv.IMREAD_COLOR)
    if src is None:
        print ('(ERRO) Erro ao abrir imagem: ' + argv[0])
        return -1

    dimention = src.shape[0]
    
    #Borrando a imagem
    #src = cv.GaussianBlur(src, (5, 5), 0)
    #Colocando em escala de cinza
    gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
    
    grad_x = np.zeros(shape=gray.shape, dtype=np.uint8)
    grad_y = np.zeros(shape=gray.shape, dtype=np.uint8)

    for i in range(0, dimention):
        for j in range(0, dimention):
            if is_edge(i, j, dimention) is True:
                v = which_edge(i, j, dimention, gray)
                grad_x[i, j] = derivative(v[0], v[1])
                grad_y[i, j] = derivative(v[2], v[3])
            else:
                grad_x[i, j] = derivative(gray[i][j-1], gray[i][j+1])
                grad_y[i, j] = derivative(gray[i-1][j], gray[i+1][j])

    grad_x = cv.convertScaleAbs(grad_x)
    grad_y = cv.convertScaleAbs(grad_y)
    grad = cv.addWeighted(grad_x, 0.5, grad_y, 0.5, 0)
    
    # ----------------------------------- #
    # CÓDIGO PRONTO, APENAS PARA COMPARAÇÃO
    scale = 1
    delta = 0
    ddepth = cv.CV_16S

    sobel_x = cv.Sobel(gray, ddepth, 1, 0, ksize=3, scale=scale, delta=delta, borderType=cv.BORDER_DEFAULT)
    sobel_y = cv.Sobel(gray, ddepth, 0, 1, ksize=3, scale=scale, delta=delta, borderType=cv.BORDER_DEFAULT)
    abs_sobel_x = cv.convertScaleAbs(sobel_x)
    abs_sobel_y = cv.convertScaleAbs(sobel_y)
    sobel = cv.addWeighted(abs_sobel_x, 0.5, abs_sobel_y, 0.5, 0)
    # ----------------------------------- #
    
    cv.imshow("Original", src)
    cv.imshow("Escala de Cinza", gray)
    cv.imshow("Comparação - Sobel", sobel)
    cv.imshow("Detecção de Bordas", grad)
    cv.waitKey(0)
    
    return 0

if __name__ == "__main__":
    main(sys.argv[1:])
