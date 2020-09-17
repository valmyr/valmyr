#include <stdio.h>
double soma_c_imp(double m[][6],int linhas,int colunas);
double media_aritme_1_4(double m[][6],int linhas,int colunas);
void substituir(double m[][6],int linhas,int colunas);
int main() {
    double Matriz[3][6];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            printf("[%d][%d]>>");scanf("%lf",&Matriz[i][j]);
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            printf("[%.2lf]",Matriz[i][j]);
        }
        printf("\n");
    }
    printf("Soma da colunas impares  %.2flf",soma_c_imp(Matriz,3,6));
    printf("Media Aritmetrica das colunas 2 e 4  %.2flf",media_aritme_1_4(Matriz,3,6));
    substituir(Matriz,3,6);
    return 0;
}
double soma_c_imp(double m[][6],int linhas,int colunas){
    double soma = 0;
    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < linhas; j++){
            if(i % 2 == 0){
                soma+=m[i][j];
            }
        }
    }
    return  soma;
}
double media_aritme_1_4(double m[][6],int linhas,int colunas){
    double cont = 0, media = 0;
    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < linhas; j++){
            if(i == 1 || i == 3){
                media+=m[i][j];
                cont++;
            }
        }
    }
    return media/cont;
}

void substituir(double m[][6],int linhas,int colunas){
    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < linhas; j++){
            m[5][j] = m[0][j]+m[1][j];
            printf("[%.2lf]",m[i][j]);
        }
        printf("\n");
    }
}