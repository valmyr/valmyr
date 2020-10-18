'''ENUNCIADO
 

Escreva um programa que calcule o valor da série S definida abaixo, com base no número de termos n:

S = 

 

ENTRADAS

O valor de n. Atenção: n deve ser inteiro e maior ou igual a zero. Caso o usuário digite um valor negativo para n, seu programa deve multiplicar n por (-1) antes de realizar o cálculo necessário para S.

 

SAÍDAS

O valor de S com 5 casas decimais.'''

from math import sqrt
solucao = 0
n = int(input())
if(n < 0):
    #modulo
    n = int(sqrt(pow(n,2)))
for i in range(0,n):
    #serie
    solucao+=(i+1)/(n-i)
print('%.5f'%solucao)