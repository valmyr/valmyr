num1 = 0
num2 = 4
num4 = 5
num3 = 1
#definição aleatoria
maior = num1
menor = num1
#Maior
if(maior < num2):
    maior = num2
if(maior < num3):
    maior = num3
if(maior < num4):
    maior = num4
#Menor
if(menor > num2):
    menor = num2
if(menor > num3):
    menor = num3
if(menor > num4):
    menor = num4
print(maior,menor)
