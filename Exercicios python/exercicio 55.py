boolean = 1
for i in range(0, 5):
    print("Informe o peso da","{}ª pessoa: ".format(i+1), end ='')
    x = float(input())
    if(boolean):
        maior = x
        menor = x
        boolean = 0
    else:
        if(x > maior):
            maior = x          
        if(x < menor):
            menor = x
print('A pessoa mais pesada tem ',maior,'kg\n','A pessoa mais leve tem',menor,'kg')
