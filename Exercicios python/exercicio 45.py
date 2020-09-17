import random
def main():
    usuario = int(input("Pedra[1]\nPapel[2]\nTesoura[3]\n"))
    maquina = int(random.randint(1,3))
    strven = "Você  venceu !!"
    strper = "Você perdeu!!!"
    lista=["","pedra", "papel", "tesoura"]
    print("Você escolheu: ",f'{lista[usuario]}')
    print("O PC escolheu: ",f'{lista[maquina]}')
    if(maquina == usuario):
        print("Empate!!!")
    elif(maquina == 1 and usuario == 2):
        print(strven)
    elif((maquina == 2 and usuario == 1)):
        print(strper)
    elif(maquina == 1 and usuario == 3):
        print(strper)
    elif((maquina == 3 and usuario == 1)):
        print(strven)
    elif(maquina == 2 and usuario == 3):
        print(strven)
    elif((maquina == 3 and usuario == 2)):
        print(strper)
    maquina = 0
    usuario = 0
main()
