n1 = float(input("Informe a primeira nota: "))
n2 = float(input("Informe a segunda nota: "))
n1+=n2
n1/=2
if(n1 < 5):
    print("Média abaixo de 5.0: REPROVADO")
elif(n1 < 7):
    print("Média entre 5. e 6.9: RECUPERAÇÂO")
else:
    print("Média 7.0 ou superior: APROVADO")
    
