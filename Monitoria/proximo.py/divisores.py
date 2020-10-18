'''Dado n e dois números inteiros positivos a e b, imprimir em ordem crescente os n primeiros naturais que são múltiplos de a ou de b e ou de ambos. Exemplo: Para n=6, a=2 e b=3 a saída deverá ser: 2,3,4,6,8,9.

 

ENTRADA

n: Quantidade de múltiplos a serem mostrados

a: Número 1

b: Número 2

SAÍDA

Todos os divisores de a, b ou de ambos (iniciando em 1) (cada divisor em uma linha separada, em ordem crescente)

EXEMPLO

Para n=6, a=2 e b=3 a saída deverá ser:

2

3

4

6

8

9'''
quantidadeDeMultiplos = int(input())
a = int(input())
b = int(input())
for i in range(0, (quantidadeDeMultiplos)):
    a*=a
    b*=b
    print("numero",i)
    print(a)
    print(b)