n = int(input())
num = 2
den = 1
pi = 1
i = 0
while(i < n):
    j = 0
    while(j < 2):
        result *= (num/(den))
        i+=1
        if(j == 0):
            den+=2
        else:
            num+=2
        j+=1
print("{:f} {:.5f}".format(pi))
