n = int(input())
antecessor = 0
sucessor = 1
for i in range(0,n):
    soma = antecessor + sucessor
    print(sucessor)
    antecessor = sucessor
    sucessor = soma
    
