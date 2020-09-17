from datetime import datetime
today = datetime.now()
ano = int(input("Informe o ano que você nasceu:"))
if(-ano + today.year > 18):
    print("Já passou do tempo do alistamento\n passou ",f'{(-ano + today.year)-18}')
else:
    if(-ano + today.year == 18):
        print("É a hora de  se alista!!!")
    else:
        print("Você ainda vai se alistar \nfaltam ",f'{+18 +ano-today.year}')
