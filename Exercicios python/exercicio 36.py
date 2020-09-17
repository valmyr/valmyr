valorc = float(input("Informe o valor da casa: "))
salario = float(input("Informe seu salário: "))
tempo = float(input("Em quantos anos você pretende pagar?"))
if(valorc / (10*tempo) <= (0.30) * salario):
    print("Empréstimo aprovado!!!")
else:
    print("Empréstimo reprovado")
