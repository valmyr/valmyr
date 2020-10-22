''''ENUNCIADO
 

A sequência de Fibonacci é uma das sequências de números bastante famosas. Ela inicia da seguinte forma: 

1,1,2,3,5,8,13,21,...

Sendo que: 

2 é a soma (1+1) 
3 é a soma (1+2) 
5 é a soma (2+3) 
8 é a soma (3+5)
e assim por diante...
Construa um programa que gere uma sequência de Fibonacci de uma quantidade N de elementos. 

 

Entrada 
A entrada consiste em um número inteiro N que indica quantidade de elementos da sequência.

Saída
Seu programa deve imprimir os N primeiros elementos da sequência, um em cada linha.'''
n = int(input())
antecessor = 0
sucessor = 1
for i in range(0,n):
    soma = antecessor + sucessor
    print(sucessor)
    antecessor = sucessor
    sucessor = soma
    
