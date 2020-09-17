#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//valmyrsilva7@gmail.com
#include <math.h>
float ajuste = 100;
float q_entradas = 1, q_oculta = 3, q_saida = 1,comum =1;
void entradas(float **m,int l, int c);
void pesos(float **m,int l, int c, float ajuste);
float **produto_matrizes(float **P, int l_peso, int comum,float **E, int c_entrada);
void Add_bias(float **m, int l, int c, int bias);
float** alocar_matrizes(int l,int c);
void Exibir(float **m, int l,int c);
void sigmoid(float **m, int l, int c);
void Delay(int n);
int main(){
    printf("\n\tinicio\n");
    srand(time(NULL));
    float **Entradas, **Pesos, **Produto_mais_bias, **Produto_matriz,**Sigmoid,**Saida;
    Pesos = alocar_matrizes(q_oculta, comum);
    Entradas = alocar_matrizes(comum,q_entradas);
    entradas(Entradas, q_entradas, comum);
    pesos(Pesos, q_oculta, comum,ajuste);
    printf("Entradas: \n");
    Exibir(Entradas,comum,q_entradas);
    printf("...\n");
    printf("Pesos 1: \n");
    Exibir(Pesos,q_oculta, comum);//
    Produto_matriz = produto_matrizes(Pesos, q_oculta, comum, Entradas, q_entradas);
    printf("...\n");
    printf("Matriz sem bias: \n");
    Exibir(Produto_matriz, q_oculta, q_entradas);
    Add_bias(Produto_matriz,q_oculta, q_entradas,1);
    printf("...\n");
    printf("Matriz com  bias: \n");
    Exibir(Produto_matriz, q_oculta, q_entradas);//2x1
    printf("...\n");
    printf("Oculta e sigmoid: \n");
    Sigmoid = Produto_matriz;
    sigmoid(Sigmoid,q_oculta, q_entradas);///1x2 peso
    Pesos = alocar_matrizes(q_saida,q_oculta);
            Exibir(Sigmoid, q_oculta, q_entradas);///2x1 oculta
    pesos(Pesos,q_entradas, q_oculta,2);
    Saida = produto_matrizes(Pesos,q_saida,q_entradas,Sigmoid,q_entradas);
    printf("...\n");
    printf("Pesos 2: \n");
    Exibir(Pesos, q_entradas, q_oculta);
    printf("...\n");
    printf("Saida: \n");
    Exibir(Saida,q_saida,q_entradas);
    printf("...\n");
    printf("Saida e sigmoid: \n");
    sigmoid(Saida,q_saida,q_entradas);
    Exibir(Saida,q_saida,q_entradas);
    Delay(100000000);
    ajuste=1;
    if(ajuste == 1){
        return 0;
    }
    main();

}

void entradas(float **m,int l, int c){
    for(int i = 0;i < l;i++)
        for(int j = 0;j < c;j++){
            m[i][j] = 1;
            //m[i][j] = rand()%(int)ajuste;
        }
}
void Saida(float **m,int l, int c){
    for(int i = 0;i < l;i++)
        for(int j = 0;j < c;j++){
            printf("indice [%d]x[%d] >>",i,j);
            scanf("%f",&m[i][j]);
        }
}
void pesos(float **m,int l, int c, float ajuste){
    for(int i =   0;i < l;i++)
        for(int j = 0;j < c;j++)
            m[i][j]=(float)(rand()%(int)ajuste)/ajuste;
}
void Add_bias(float **m, int l, int c, int bias){
    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            m[i][j] += bias;
}
float **produto_matrizes(float **P, int l_peso, int comum,float **E, int c_entrada){
    float **m;
    m = alocar_matrizes(l_peso, l_peso);
    for(int i = 0; i < l_peso; i++){
        for(int j = 0; j < c_entrada; j++){
            float somatorio = 0;
            for(int k = 0; k < comum; k++){
                somatorio+=P[i][k]*E[k][j];
            }
            m[i][j]= somatorio;
        }
    }
    return m;
}
void sigmoid(float **m, int l, int c){
    for(int i = 0;i < l; i++){
        for(int j = 0;j < c;j++){
            m[i][j] = (float)1 / (1+ exp(-m[i][j]));
        }
    }


}
float** alocar_matrizes(int l,int c){
    float **m;
    m = malloc(sizeof(float*)*l);
    for(int i = 0;i < l;i++){
        m[i] = malloc(sizeof(float)*c);
        for(int j = 0; j < c; j++)
            m[i][j]=0;
    }
    return m;
}
void Exibir(float **m, int l,int c){
    for(int i =   0;i < l;i++){
        for(int j = 0;j < c;j++){
            printf("[%.2f]",m[i][j]);
        }
        printf("\n");
    }
}
void Delay(int n){
    for(int i = 0; i < n; i++){

    }

}