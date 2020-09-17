#include "funcoes.h"
int main() {
    int **Matriz_A, **Matriz_B,**Matriz_C, *v;
    v = (int*)matriz(1,4);
    Dimensoes(v);
    Matriz_A = matriz(v[0],v[1]);
    Matriz_B = matriz(v[2],v[3]);
    Matriz_C = matriz(v[1],v[2]);
    if(Verificar(v) == 1){
        printf("Adicionando valores nas matrizes\n\n");
        printf("Informe os valores da matriz: 1\n");
        Preencher_Matriz(Matriz_A,v,0);
        printf("Informe os valores da matriz: 2\n");
        Preencher_Matriz(Matriz_B,v,2);
        printf("Exibindo Matriz...\n\n\n");
        Exibir_Matriz(Matriz_A,v[0],v[1]);
        printf("\n");
        Exibir_Matriz(Matriz_B,v[2],v[3]);
        Prodruto(Matriz_A, Matriz_B,v,Matriz_C);
        for(int i = 0 ;i < v[1];i++){
            for(int j =0; j < v[2]; j++){
                printf("[%d]",Matriz_C[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("impossivel realizar o produto das matriz pois a quantidade de colunas da primeira matriz e diferente das linhas da segunda matriz");
    }
        //

    return 0;
}
