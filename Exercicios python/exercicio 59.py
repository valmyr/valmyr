
x = float(input("Informe o primeiro valor:"))
y = float(input("Informe o segundo valor"))
while(1):
    print('''
[1]Somar
[2]Multiplicar
[3]maior
[4]novos números
[5]sair do programa''')
    op = int(input())
    while(op < 1 or op >5):
        print("Opção invalida: ")
        op = int(input(""))
    if(op == 5):
        break
    elif(op == 1):
        print("A soma {} + {} = {}".format(x,y,x+y))
    elif(op == 2):
        print("A multiplicação de {} * {} = {}".format(x,y,x*y))
    elif(op == 3):
        if(x == y):
            print("São iguais")
        if(x < y):
            temp = x
            x = y
            y = temp
        print("O maior numero entre {} and {} = {}".format(x,y,x))
    elif(op == 4):
        x = float(input("Informe o primeiro valor:"))
        y = float(input("Informe o segundo valor"))
