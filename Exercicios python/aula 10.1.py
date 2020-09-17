n1 = float(input("Digite a primeira nota"))
n2 = float(input("Digite a segunda nota"))
print(f'{"="*7}',"INÍCIO",f'{"="*7}')
print("Sua média é ",f'{(n1+n2)/2}')
if((n1+n2)/2 >= 7):
    print("Parabéns, você foi aprovado")
else:
    print("Infelizmente você foi reprovado")
print(f'{"="*10}',"FIM",f'{"="*10}')
