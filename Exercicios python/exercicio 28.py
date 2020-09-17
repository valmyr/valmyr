import random
aleatorio = random.randint(1,5)
num = int(input("Tente descobrir o numero que o computador pensou >> "))
print(f'{"="*10}',"INÍCIO",f'{"="*10}')
if(aleatorio == num):
    print("Parabéns, você venceu!!!")
else:
    print("Tente novamente")
print(f'{"="*10}',"FIM",f'{"="*10}')
