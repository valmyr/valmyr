vel = float(input("Informe a velocidade de seu carro >> "))
if(vel > 80):
    print("Você foi multado em R$",f'{(vel - 80)*7:.2f}',"reais")
    
