while(True):
    n = int(input("Qual a tabuada você que consultar? "))
    if(n < 0):
        break
    i = 0
    while(i <= 10):
        print(f'{n} x {i} = {i*n}')
        i+=1
    n = 0
