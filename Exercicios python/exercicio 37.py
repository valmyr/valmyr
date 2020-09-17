decimal = int(input("Informe um número: "))
stry = str(input("Informe qual base de conversão: "))
stry = stry.upper()
if(stry == 'B'):
    print("b",f'{decimal:b}')
else:
    if(stry == 'O'):
        print("O",f'{decimal:o}')
    else:
        if(stry == 'X'):
            print("H",f'{decimal:x}')
