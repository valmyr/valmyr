'''ENUNCIADO

Escreva um programa em Python que dado um inteiro, mostre todos os seus divisores positivos (exceto 1 e ele mesmo), e ao final mostrar se o número é ou não primo.

ENTRADA

Um inteiro n

SAÍDA

Os divisores positivos (um por linha, em ordem crescente)

"PRIMO" (sem aspas), se o n é um número primo. 

"NÃO PRIMO" (sem aspas), caso n não seja um número primo. 



EXEMPLOS

Para a entrada:

16

A saída deve ser:

2

4

8

NÃO PRIMO

 

Para a entrada:

17

A saída deve ser:

PRIMO



Para a entrada:

-11

A saída deve ser:

PRIMO'''
numero = int(input())
if(numero < 0):
    numero*=-1
for i in range(2, numero):
    cont = 0
    for j in range(1,numero):
        if(numero % j == 0):
            cont+=1
if(cont == 1):
    print("PRIMO")
else:
    for k in range(2, numero):
        if(not(numero %k)):
            print(k)
    print("NÃO PRIMO")