n = int(input("Digite um numero: "))
numerador = 1
denominador = n
S = 0
if (n<0): #se o numero for negativo * (-1)
    n = n*(-1)
for i in range(0, n, 1):
    S = S + (numerador/denominador)
    numerador += 1
    denominador -= 1
print("%.5f"%S)   
