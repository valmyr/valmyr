import numpy as np
def Exibir(m):
    for i in range(0, m.shape[1]):
        for j in range(0,m.shape[1]):
            print(f'[{m[i][j]}]',end ='')
        print()
def matriz_Simetrica(m):
    cont = 0
    for i in range(0,m.shape[0]):
        for j in range(0,m.shape[1]):
            if(m[i][j] != m[j][i]):
                return False
    return True
def matriz_Ant_Simetrica(m):
    if(matriz_Nula(m)):
        return False
    for i in range(0, m.shape[0]):
        for j in range(0, m.shape[1]):
            if(m[i][j] != -m[j][i]):
               return False
            if(i == j and m[i][j] != 0):
                return False
    return True
def matriz_Identidade(m):
    cont = 0
    for i in range(0,m.shape[0]):
        for j in range(0, m.shape[1]):
            if(i != j and m[i][j] != 0):
                return False
            elif(m[i][j] == 1):
                cont+=1
    if(cont == m.shape[1]):
        return True
    return False
def matriz_Nula(m):
    for i in range(m.shape[0]):
        for j in range(m.shape[1]):
            if(m[i][j] != 0):
                return False
    return True

def main():
    ta = int(input("Informe o tamanho da matriz: "))
    m = np.empty([ta,ta], dtype = int)
    for i in range(0,ta):
        for j in range(0, ta):
           m[i][j] = int(input(f'[{i+1}][{j+1}]: '))
    op = False
    print()
    Exibir(m)
    print("Matriz >> ")
    if(matriz_Simetrica(m)):
        op = True
        print("Matriz simetrica")
    if(matriz_Ant_Simetrica(m)):
        op = True
        print("Matriz ant-simetrica")
    if(matriz_Identidade(m)):
        op = True
        print("Matriz Identidade")
    if(matriz_Nula(m)):
        op = True
        print("Matriz Nula")
    elif(ta > 1 and not(op)):
        print("Matriz Desconhecida")
    print("Deseja:\n Continuar[1]\n Sair[0]")
    op = int(input(""))
    while(op < 0 or op >1):
        print("Opcao invalida")
        op = int(input("Tente Novamente: "))
    if(op):
        main()
main()
