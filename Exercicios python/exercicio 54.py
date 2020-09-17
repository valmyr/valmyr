boolean = 1
for i in range(0, 3):
    print("Informe o ",i+1,"número: ", end ='')
    x = int(input())
    if(boolean):
        temp = x
        boolean = 0
    else:
        if(x > temp):
            temp = x
        else:
            temp2 = x

print(temp, temp2)
