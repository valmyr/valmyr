
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

float **alocar_matriz(int linhas, int colunas);
void tanh_(float **m, int linhas, int colunas);
float **Multiplicacao_de_Matrizes(float **M1, float **M2, int Linhas_M1,int Comum_M1_e_M2,int Colunas_M2);
float **alocar_matriz(int linhas, int colunas){
    float **m;
    m = (float**)malloc(sizeof(float*)*linhas);
    for(int i = 0; i < linhas; i++){
        m[i] = (float*)malloc(sizeof(float)*colunas);
        for(int  j = 0; j < colunas; j++){
            m[i][j] = 0;
        }
    }
    return m;
}
float **Multiplicacao_de_Matrizes(float **M1, float **M2, int Linhas_M1,int Comum_M1_e_M2,int Colunas_M2){
    float **m = alocar_matriz(Linhas_M1,Colunas_M2);
    for(int i = 0; i < Linhas_M1; i++){
        for(int j = 0; j < Colunas_M2; j++){
            float Somatorio = 0;
            for(int k = 0; k < Comum_M1_e_M2; k++){
                Somatorio += M1[i][k]*M2[k][j];
            }
            m[i][j] = Somatorio;
        }
    }
    return m;
}
void tanh_(float **m, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            m[i][j] = (float)(exp(m[i][j]) - exp(-m[i][j]))/(exp(m[i][j])+exp(-m[i][j]));
        }
    }
}

float **Treianamento(float **Entradas, float **Pesos, float **Saidas, int Linhas, int Comum, int Colunas);
float **Erro(float **Saida, float **Saida_Ob, int linhas, int colunas);
float **Atualizando_pesos(float **Entradas,float **Pesos,float **Erro_,int Linhas, int Comum, int Colunas);
float **Derivada(float **Erro_,int Linhas, int Colunas);
void Aleatorios(float **m,int linhas,int colunas);
void Exibir_Matriz(float **m, int linhas, int colunas);
int main() {
    srand(time(NULL));
    float **Entradas, **Saidas, **Pesos;

    /* Entradas = |A*B|
     *            |0|0|
     *   4x2      |0|1|
     *            |1|0|
     *            |1|1|
     *
     * Pesos = A| |al|
     *   2x1   B| |al|
     *
     *
     *
     * Saidas =   |S|
     *            |0|
     *    4x1     |0|
     *            |0|
     *            |1|
     *
     */
//----------------------------------------------------------------------------//
int Linhas_En = 4, Comum = 2, Colunas_Pe = 1;
/*   Alocação das matrizes de pesos e das entradas                            */
//----------------------------------------------------------------------------//
    Entradas = alocar_matriz(Linhas_En,Comum);
    Pesos = alocar_matriz(Comum,Colunas_Pe);
    Saidas = alocar_matriz(Linhas_En,Colunas_Pe);

/*    Preenchendo entradas                                                        */
Entradas[0][0] = 0;Entradas[0][1] = 0;
Entradas[1][0] = 0;Entradas[1][1] = 1;
Entradas[2][0] = 1;Entradas[2][1] = 0;
Entradas[3][0] = 1;Entradas[3][1] = 1;
Aleatorios(Pesos,Comum,Colunas_Pe);
Saidas[3][0] = 1;
printf("Entradas\n");
Exibir_Matriz(Entradas,Linhas_En,Comum);
printf("Pesos\n");
Exibir_Matriz(Pesos,Comum,Colunas_Pe);
printf("Saida\n");
Exibir_Matriz(Saidas,4,1);///
   int Epocas = 100.;
   for(int i = 0; i <= Epocas; i++){
       printf("Epoca [%d]\n",i);
       // Treianamento(Entradas,Pesos,Saidas,Linhas_En,Comum,Colunas_Pe);
        Exibir_Matriz(Treianamento(Entradas,Pesos,Saidas,Linhas_En,Comum,Colunas_Pe),Linhas_En,Colunas_Pe);
   }

}
float **Treianamento(float **Entradas, float **Pesos, float **Saidas, int Linhas, int Comum, int Colunas){
    float **Saidas_Ob,**Erro_;
/*                   Saida sem a função de ativação                           */
    Saidas_Ob = Multiplicacao_de_Matrizes(Entradas, Pesos, Linhas ,Comum ,Colunas);
/*                   Saida com a função de ativação                           */
    tanh_(Saidas_Ob,Linhas,Colunas);
/*                    Erro                                                    */
    Erro_ = Erro(Saidas,Saidas_Ob,Linhas,Colunas);
/*                     Atualizando pesos                                       */
    Atualizando_pesos(Entradas, Pesos, Erro_, Linhas, Comum, Colunas);

    return Saidas_Ob;
}
float **Erro(float **Saida, float **Saida_Ob, int linhas, int colunas){
    float **erro = alocar_matriz(linhas, colunas);
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            erro[i][j] = Saida[i][j]-Saida_Ob[i][j];
        }
    }
    return erro;
}
float **Atualizando_pesos(float **Entradas,float **Pesos,float **Erro_,int Linhas, int Comum, int Colunas){
    float **deri = Derivada(Erro_,Linhas,Colunas);

    return Pesos;
}
float **Derivada(float **Erro_,int Linhas, int Colunas){
    for(int i = 0; i < Linhas; i++){
        for(int j = 0; j < Colunas; j++){
            Erro_[i][j] = Erro_[i][j] * (1 - Erro_[i][j]);
        }
    }
    return Erro_;
}
void Aleatorios(float **m,int linhas,int colunas) {
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            m[i][j] = (float)(rand()%101)/100;
        }
    }
}
void Exibir_Matriz(float **m, int linhas, int colunas){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("[%.3f]",m[i][j]);
        }
        printf("\n");
    }
}
