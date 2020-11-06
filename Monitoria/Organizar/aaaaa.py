from math import sqrt
solucao = 0
n = int(input())
if(n < 0):
    #modulo
    n = int(sqrt(pow(n,2)))
for i in range(0,n):
    #serie
    solucao+=(i+1)/(n-i)
print('%.5f'%solucao)