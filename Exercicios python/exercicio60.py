i = int(input("informe o número para o calculo do fatorial: "))
k = 1
fat = 1
while(k <= i):
    fat*=k
    k+=1
print("O fatorial de {}! é {}".format(i,fat))
