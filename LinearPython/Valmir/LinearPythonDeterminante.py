import os 
import math
import numpy as np
import random
def exibirMatriz(matriz):
    for i in range(0,matriz.shape[1]):
        for j in range(0, matriz.shape[0]):
            print("{:3d}".format(matriz[i][j]),end=" ")
        print()
def inserirAleatoriamente(sizeMatriz,variacao):
    matriz = np.empty([sizeMatriz,sizeMatriz],dtype = int)
    for i in range(0,matriz.shape[0]):
        for j in range(0,matriz.shape[1]):
            matriz[i][j] = random.randint(0,variacao)
    return matriz
def inserirManualmente(sizeMatriz):
    matriz = np.empty([sizeMatriz,sizeMatriz],dtype = int)
    for i in range(0,matriz.shape[0]):
        for j in range(0,matriz.shape[1]):
            matriz[i][j] = int(input("[{:2d}][{:2d}]>>".format(i,j)))
    return matriz

def determinante(matriz):
    det = 0
    if(matriz.shape[0] - 1 == 0):
        return matriz[0][0]
    else:
        for i in range(0,matriz.shape[0]):
            if(matriz[0][i]):
                det += matriz[0][i]*pow(-1,i)*determinante(cofatores(matriz,matriz.shape[0],0,i))
        return det
def cofatores(matriz,sizeMatriz,linhaExcluir, ColunaExcluir):
    mAux = np.empty([sizeMatriz-1,sizeMatriz-1], dtype = int)
    k = 0
    z = 0
    for i in range(0,matriz.shape[0]):
        for j in range(0, matriz.shape[0]):
            if(i != linhaExcluir and j != ColunaExcluir):
                mAux[k][z] = matriz[i][j]
                z+=1
        if(i != linhaExcluir):
            z = 0
            k+=1
    return mAux
def main():
    print("{}".format("=-"*20))
    sizeMatriz = int(input("INFORME A ORDEM DA MATRIZ: "))
    print("{}".format("=-"*20))
    print("{}DESEJA".format(' '*15))
    print("{}".format("=-"*20))
    print("[1] Inserir Manualmete")
    print("[2] Inserir Aleatoriamete")
    print("{}".format("=-"*20))
    op = int(input())
    print("{}".format("=-"*20))
    while(op > 2 or op < 1):
        op = int(input("Opcao invalida: "))
    if(op == 1):
        matriz = inserirManualmente(sizeMatriz)
    else:
        op = int(input("Informe a variacao de numeros aleatorios: "))
        print("{}".format("=-"*20))
        matriz = inserirAleatoriamente(sizeMatriz,op+1)
    print("{}".format("=-"*20))
    print("\nA matriz informada: \n")
    print("{}".format("=-"*20))
    exibirMatriz(matriz)
    print("{}".format("=-"*20))
    print("\nA deteminante da matriz e: \n")
    print("Det(M) = {}".format(determinante(matriz)))
    print("{}".format("=-"*20))
    op = int(input("[0] Reiniciar: "))
    if(op):
        return 0    
    os.system("cls")
    main() 
os.system("cls")
main()
