#include "funcoes.h"
int main(){
    srand(time(NULL));
    int Linhas_Matriz_1,Linhas_Matriz_2,Colunas_Matriz_1,Colunas_Matriz_2,**Matriz_Main_1,**Matriz_Main_2;
    cout<<"Informe a dimesao da matriz 1:\n";
    cout<<"Linhas matriz 1:";
    cin>>Linhas_Matriz_1;
    cout<<"Colunas matriz 1:";
    cin>>Colunas_Matriz_1;
    cout<<"Linhas matriz 2:";
    cin>>Linhas_Matriz_2;
    cout<<"Colunas matriz 2:";
    cin>>Colunas_Matriz_2;
    Matriz_Main_1 = Alocar_Matriz(Linhas_Matriz_1,Colunas_Matriz_1);
    Matriz_Main_2 = Alocar_Matriz(Linhas_Matriz_2,Colunas_Matriz_2);
    if(Colunas_Matriz_1 == Linhas_Matriz_2){
        cout<<"Insira os valores da matriz 1: \n";
        Prencher_Matrizes(Linhas_Matriz_1,Colunas_Matriz_1,Matriz_Main_1);
        cout<<"Insira os valores da matriz 2: \n";
        Prencher_Matrizes(Linhas_Matriz_2,Colunas_Matriz_2,Matriz_Main_2);
        cout<<"Matriz 1: \n";
        Exibir_Matrizes(Linhas_Matriz_1,Colunas_Matriz_1,Matriz_Main_1);
        cout<<"Matriz 2: \n";
        Exibir_Matrizes(Linhas_Matriz_2,Colunas_Matriz_2,Matriz_Main_2);
        cout<<"Resultado do produto: \n";
        Exibir_Matrizes(Linhas_Matriz_1,Colunas_Matriz_2,Produto_Matrizes(Linhas_Matriz_1, Colunas_Matriz_1, Linhas_Matriz_2, Colunas_Matriz_2, Matriz_Main_1, Matriz_Main_2));
    }
    else{
        cout<<"Nao e possivel efetuar o escalonamento das matrizes pois a quantidade de colunas da matriz primeira e diferentes da quantidade de linhas da segunda matriz";
    }
    return 0;
}
