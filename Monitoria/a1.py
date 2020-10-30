n = int(input())
p = int(input())
cont = i = 0 
while(i < n):
    x = int(input())
    y = int(input())
    if(x + y >= p):
        cont+=1
    i+=1
print(cont)