#include <stdio.h>
#include <stdlib.h>
float *multp(float Matriz[6][6],float valor);
int main() {
    float Matriz[6][6], A, *v;
    printf("Informe os 36 valores: \n");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            printf("[%d][%d]>> ", i ,j);scanf("%f",&Matriz[i][j]);
        }
    }
    printf("Informe o valor de A>>");scanf("%f",&A);
    v = multp(Matriz, A);
    for(int i = 0; i < 36; i++){
        printf("%.2f ",v[i]);
    }
    return 0;
}

float *multp(float Matriz[6][6], float valor){
    int cont = 0;
    float *vetor = (float*)malloc(sizeof(float)*36);
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            vetor[cont++] = Matriz[i][j]*valor;
        }
    }
    return vetor;
}