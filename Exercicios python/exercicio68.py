from random import randint
cont = 0
while(True):
    usuario = int(input("[0] Par\n[1] Ímpar"))

    if(usuario == 1):
        pc = 0
    else:
        pc = 1
    num = int(input("Digite um número:"))
    pcc =  randint(0,11)
    soma = pcc + num
    if(not(soma % 2)):
        if(not(num % 2)):
            print("Você venceu !!!")
            cont+=1
        else:
            print("Você perdeu")
            break
    else:
        if(num % 2):
            print("Você perdeu !!!")
            break
        else:
            print("Você venceu!!!")
            cont+=1
print(f'vitorias consecutivas {cont}')
