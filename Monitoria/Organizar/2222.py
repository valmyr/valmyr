numero = float(input())
if(numero<0):
    inteiro = ((-1 * numero)//1)*(-1)
    fracionaria = (-1 * numero)%1
    
else:
    inteiro = numero//1
    fracionaria = numero%1
print("{:d}".format(int(inteiro)))
print("{:f}".format(fracionaria%1))
