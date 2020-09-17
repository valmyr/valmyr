from math import sqrt, pow
cop = float(input("Informe o valor do cateto oposto"))
cad = float(input("Informe o valor do cateto adjacente"))
print("Hipotenusa = ",f'{sqrt(pow(cop,2)+pow(cad,2)):2}')
