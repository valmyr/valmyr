'''ENUNCIADO

Escreva um programa em Python que dado um inteiro, mostre todos os seus divisores (exceto ele mesmo), e ao final mostre se o número é ou não perfeito. Um número é dito perfeito quando é igual a soma de todos os seus divisores, exceto ele mesmo.

ENTRADA

Um inteiro n

SAÍDA

Os divisores (um por linha)

PERFEITO ou NÃO PERFEITO

EXEMPLO

Para a entrada 6

A saída deve ser:

1

2

3

PERFEITO

Para a entrada 17

A saída deve ser:

1

NÃO PERFEITO'''
numero =int(input())
verificarNumero = 0
for i in range(0,numero-1):
    if(not(numero % (i+1))):
        print(i+1)
        verificarNumero+=(i+1)
if(verificarNumero == numero):
    print("PERFEITO")
else:
    print("NÃO PERFEITO")