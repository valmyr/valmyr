from math import sqrt
def media(v):
    soma = 0
    for i in range(0,len(v)):
        soma+=v[i]
    print('Somatorio dos valores {}'.format(soma))
    print('Media {}'.format(soma/len(v)))
    return soma/len(v)
def quadrado(v):
    soma  = 0
    for i in range(0,len(v)):
        soma+=pow(v[i],2)
    print('Somatorio dos valores ao quadrado {} '.format(soma))
    return soma
def desvio(a ,b, n):
    return sqrt(float(1/(n-1)*(a - (float(1/n)*pow(b,2)))))
def main(v):
    a = media(v)
    b = quadrado(v)
    d = desvio(b ,a, len(v))
    print('desvio padrao {}'.format(d))
    print('desvio padrao medio{}'.format(d/sqrt(len(v))))
