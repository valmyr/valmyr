peso = float(input("Informe seu peso"))
altura  =float(input("Informe sua altura"))
imc = peso / pow(altura,2)
if(imc < 18.5):
    print("Abaixo de 18.5: Abaixo do peso")
elif(imc < 25):
    print("Entre 18.5 e 25: Peso ideal")
elif(imc < 30):
    print("25 até 30: Sobrepeso")
elif(imc < 40):
    print("30 até  40:obesidade")
else:
    print("Obesidade mórbida")
