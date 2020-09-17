#include <stdio.h>
#include<stdlib.h>
double media(double  *v,  int tamanho);
double quadrado_distancia(double  *v,  int tamanho);
double raiz(double  *v,  int tamanho);
int main() {

    double *Vetor, n;
    printf("informe o tamnaho do vetor >>\n");scanf("%lf",&n);
    Vetor = (double*)malloc(sizeof(double)*n);
    printf("Informe os valores do vetor >>\n");
    for(int i = 0; i < n; i++){
        printf("[%d] >> ");scanf("%lf", &Vetor[i]);
    }
    printf("Media %.f", media(Vetor,n)/n);


    return 0;
}

double media(double  *v,  int tamanho){
    double  soma;
    for(int i = 0; i < tamanho; i++){
        soma+=v[i];
    }
    return soma;
}