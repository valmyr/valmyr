n1 = int(input("Primeiro >>"))
n2 = int(input("Segundo >>"))
n3 = int(input("Terceiro >>"))
# 3 6 2
if(n1 > n2):
    n2 = n1
if(n3 > n2):
    n2 = n3
print(n2)
