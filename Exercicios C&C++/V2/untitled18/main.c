#include<stdbool.h>
#include <stdio.h>
#include<math.h>
float Manipulacao(float M[][13]);
void Exibir(float M[][13], int linhas, int colunas);
int main() {
    float Matriz[12][13], Soma;
    for(int i  = 0; i < 12; i++){
        for(int j = 0; j < 13; j++){
            printf("[%d][%d] >> ",i,j);scanf("%f", &Matriz[i][j]);
        }
    }
    Exibir(Matriz,12,13);
    Soma = Manipulacao(Matriz);
    Exibir(Matriz,12,13);
    printf("Soma de todos valores %.2f", Soma);
    return 0;
}

float Manipulacao(float M[][13]) {
    bool botaovirtual1 = true,botaovirtual2 = true;
    float Maior, Soma = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 13; j++) {
            if(botaovirtual2){
                for (int k = 0; k < 12; k++) {
                    if (botaovirtual1) {
                        Maior = M[i][k];
                        botaovirtual1 = false;
                    } else {
                        if (Maior < M[i][k]) {
                            Maior = M[i][k];
                        }
                    }
                }
                botaovirtual2 = false;
            }
            Soma += fabs(Maior);
            botaovirtual1 = true;
            M[i][j] /= fabs(Maior);
        }
        botaovirtual2 = true;
    }
    return Soma;
}
void Exibir(float M[][13], int linhas, int colunas){
    printf("\n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("[%.2f]",M[i][j]);
        }
        printf("\n");
    }
}