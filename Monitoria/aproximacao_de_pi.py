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
i = 0
j = 0
pi = 1
while(i < n):
    pi*=num/den
    if(j < 1):
        j+=1
        d+=2
    else:
        j = 0
        n += 2
    i+=1

print(pi*2)