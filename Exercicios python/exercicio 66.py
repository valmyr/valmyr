cont = s = 0
while(True):
    num  = int(input("Digite um número:"))
    if(num == 999):
        break
    cont+=1
    s+=num
print(f'Foram digitados {cont} é a soma de todos os números é {s}')
