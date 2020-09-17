#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Programa para fazer o produto de matrizes
by Valmyr 16/05/2020
*/

float **Alocar_Matriz(int Linhas, int Colunas);
void Inserir_Valores(float **m, int Linhas, int Colunas, char c);
void Exibir_Matriz(float **m, int Linhas, int Colunas);
float **Produto_de_M1_M2(float **M1, float **M2, int Linhas_1, int Colunas_C1_L2, int Colunas_2);
int main(){
    char c;
    float **M1, **M2, **M3;
    float Linhas_1,Colunas_1,Linhas_2,Colunas_2,Linhas_E_Colunas_Comum;
    printf("\n\nInforme os valores usando Colchetes exemplo... [2x2]\n");
    printf("Informe a quantidade de linhas e colunas da matriz 1: [NxM] >> ");scanf("[%fx%f]",&Linhas_1,&Colunas_1);printf("\n");
    fflush(stdin);
    printf("Informe a quantidade de linhas e colunas da matriz 2: [MxK] >> ");scanf("[%fx%f]",&Linhas_2,&Colunas_2);printf("\n\n");
    printf("Dimensoes:\n");
    printf("M1 = [%.f x %.f]\nM2 = [%.f x %.f]\n\n",Linhas_1,Colunas_1,Linhas_2,Colunas_2);
    if(Colunas_1 != Linhas_2){
        fflush(stdin);
        printf("Erro, quantidade de colunas da matriz 1 diferente da quantidade de linhas da matriz 2 impossivel realizar o produto.\n\n");
        printf("Reiniciar? S/N >> ");scanf("%c",&c);
        fflush(stdin);
        return c == 'S' || c == 's' ? main(): 0;
    }
    Linhas_E_Colunas_Comum = Colunas_1;
    M1 = Alocar_Matriz(Linhas_1,Linhas_E_Colunas_Comum);
    M2 = Alocar_Matriz(Linhas_E_Colunas_Comum,Colunas_2);
    char s;
    do{
        fflush(stdin);
        printf("Aleatoriamente? S/N >>");scanf("%c",&s);
    }while(c == 'n' || c == 'N' || c == 'S' ||c == 's');

    printf("\n");
    printf("Insirar os valores da matriz 1>>\n\n");
    Inserir_Valores(M1,Linhas_1,Linhas_E_Colunas_Comum,s);
    printf("Insirar os valores da matriz 2>>\n\n");
    Inserir_Valores(M2,Linhas_E_Colunas_Comum,Colunas_2,s);
    printf("matriz 1: \n\n");
    Exibir_Matriz(M1,Linhas_1,Linhas_E_Colunas_Comum);
    printf("matriz 2: \n\n");
    Exibir_Matriz(M2,Linhas_E_Colunas_Comum,Colunas_2);
    M3 = Produto_de_M1_M2(M1, M2, Linhas_1, Linhas_E_Colunas_Comum, Colunas_2);
    printf("resultado do produto :\n\n");
    Exibir_Matriz(M3,Linhas_1,Colunas_2);
    return 0;
}
float **Alocar_Matriz(int Linhas, int Colunas){
    float **matriz;
    matriz = malloc(sizeof(float*)*Linhas);
    for(int i = 0; i < Linhas; i++){
        matriz[i] = malloc(sizeof(float)*Colunas);
    }
    return matriz;
}
void Inserir_Valores(float **m, int Linhas, int Colunas, char c){
    srand(time(NULL));
    for(int i = 0; i < Linhas; i++){
        for(int j = 0; j < Colunas; j++){
            fflush(stdin);
            if(c == 's' || c == 'S') {
                m[i][j] = (rand() % 3)*0.3;
                printf("indece [%d][%d] = [%.2f]\n",i,j,m[i][j]);
            }
            if(c == 'n'||c == 'N'){
                printf("indece [%d][%d] >>",i,j);
                scanf("%f",&m[i][j]);
            }
        }
    }
}
void Exibir_Matriz(float **m, int Linhas, int Colunas){
    for(int i = 0; i < Linhas; i++){
        for(int j = 0; j < Colunas; j++){
            printf("[%.2f] ",m[i][j]);
        }
        printf("\n");
    }
}
float **Produto_de_M1_M2(float **M1, float **M2, int Linhas_1, int Linhas_E_Colunas_Comum, int Colunas_2){
    float **Produto_Entre_M1_E_M2, Somatorio = 0;
    Produto_Entre_M1_E_M2 = Alocar_Matriz(Linhas_1,Colunas_2);
    for(int i = 0; i < Linhas_1; i++){
        for(int j = 0; j < Colunas_2; j++){
            for(int k = 0; k < Linhas_E_Colunas_Comum; k++){//Terceiro for alinhado usar-se o dado em comum como limte de interações
                Somatorio += M1[i][k]*M2[k][j];
            }
            Produto_Entre_M1_E_M2[i][j] = Somatorio;
            Somatorio = 0;
        }
    }
    return Produto_Entre_M1_E_M2;
}