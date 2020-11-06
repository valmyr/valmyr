n = int(input())
m= int(input())
maior = m
menor = m
for i in range(1,n):
    m = int(input())
    if(maior > m):
        maior = m
    if(menor < m):
        menor = m
print(maior,menor)
