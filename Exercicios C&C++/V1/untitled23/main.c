#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void Exibir(int *v, int t);
int main() {
    srand(time(0));
    int tamanho,*vetor;
    printf("Informe o tamanho do vetor >> ");scanf("%d",&tamanho);
    vetor =(int*)malloc(sizeof(int)*tamanho);
    for(int i = 0; i < tamanho; i++)
        vetor[i] = rand()%101;

    Exibir(vetor,tamanho);

    return 0;
}
void Exibir(int *v,int t){
    if(0 == t){
    }
    else{
        printf("%d ",*(v++));
        Exibir(v,--t);
    }
}
