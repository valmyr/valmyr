cont = 0
media = 0
boolean = 1
while(1):
    x = int(input("num: "))
    if(boolean):
        menor = x
        maior = x
        boolean = 0
    else:
        if(x > maior):
            maior = x
        else:
            menor = x
    media+=x
    cont+=1
    op = str(input("Continuar[S/N]")).upper().strip()
    if(op == 'N'):
        break

print("maior {} menor {} media {}".format(maior,menor,media/cont))
