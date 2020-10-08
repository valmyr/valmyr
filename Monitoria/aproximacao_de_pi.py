'''ENUNCIADO
Escreva um programa em Python que calcule a aproximação do valor de π através da fórmula abaixo, considerando os n primeiros termos:

π/2=2/1×2/3×4/3×4/5×6/5×6/7×8/7×8/9...

ENTRADA

O valor de n: quantidade de termos

SAÍDA

O valor aproximado de π com 5 casas decimais.'''
n = int(input())
num = 2
den = 1
pi = 1
i = 0
while(i < n):
    j = 0
    while(j < 2):
        pi *= float(num/(den))
        i+=1
        if(j == 0):
            den+=2
        else:
            num+=2
        j+=1
print("{:.5f}".format(2*pi))
