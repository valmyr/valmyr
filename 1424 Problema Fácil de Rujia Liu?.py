#gerador De Casos de Testes - 1424 Problema Fácil de Rujia Liu?
import random
def main(quantidadeDeNumeros,limiteDeNumeros,limiteDeRepeticoes):
    print(f'{quantidadeDeNumeros} {quantidadeDeNumeros}')
    for i in range(quantidadeDeNumeros):
        print(f'{random.randint(0,limiteDeNumeros)}',end=' ')

    for i in range(quantidadeDeNumeros):
        print(f'{random.randint(0,limiteDeRepeticoes)} {random.randint(0,limiteDeNumeros)}',end='\n')
main(1000,10,3)
