dis = float(input("Informe a distância: "))
if(dis <= 200):
    print("O preço a pagar é",f'{dis*0.5:.2f}')
else:
    print("O preço a pagar é",f'{dis*0.45:.2f}')
