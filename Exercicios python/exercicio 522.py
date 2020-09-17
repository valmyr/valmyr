n = int(input("Informe um número"))
cont = 0
for i in range (1,n+1):
    if(not(n % i)):
        cont+=1
if(cont == 2):
    print("É primo")
else:
    print("Não é primo")
