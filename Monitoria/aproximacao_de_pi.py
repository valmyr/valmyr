'''ENUNCIADO
Escreva um programa em Python que calcule a aproximação do valor de π através da fórmula abaixo, considerando os n primeiros termos:

π/2=2/1×2/3×4/3×4/5×6/5×6/7×8/7×8/9...

ENTRADA

O valor de n: quantidade de termos

SAÍDA

O valor aproximado de π com 5 casas decimais.'''
n = int(input())# n = 3
num = 2
den = 1
i = 0
j = 0
pi = 1
#i = 3
while(i < n):
    pi*=num / den#1*(2/1)*(2/3)*(4/3)
    print("{:} {:} {:.3}".format(num, den, pi))
    if(j < 1):
        j+=1 # j = 1
        den+=2 #den = 5
    else:
        j = 0
        num += 2 #num = 4
    i+=1

    
print("{:.6}".format(pi*2))
