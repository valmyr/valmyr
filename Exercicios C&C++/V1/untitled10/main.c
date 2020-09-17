#include <stdio.h>
#include <stdlib.h>
int vetor(int *p1,int c1,int *p2, int c2,int *p3,int c3);
int Quantidade_de_termos_diferentes(int *p1,int c1,int *p2, int c2);

int main() {
    int vetor_1[6] = {1,2,3,4,5}, vetor_2[3]= {1,3,5},*p3;
    p3 = malloc(sizeof(int)*Quantidade_de_termos_diferentes(vetor_1,6,vetor_2,3));
    vetor(vetor_1, 6, vetor_2, 3,p3,Quantidade_de_termos_diferentes(vetor_1,6,vetor_2,3));
    return 0;
}
int vetor(int *p1,int c1,int *p2, int c2,int *p3, int c3){
    int k = 0;
    for(int i = 0; i < c1; i++){
        for(int j = 0; j < c2; j++){
            if(p1[i] != p2[j]){
                p3[k] = 0;
                k++;
                break;
            }
        }
    }
    for(int i = 0; i < c3; i++)
        printf("%d ",p3[i]);
}
int Quantidade_de_termos_diferentes(int *p1,int c1,int *p2, int c2){
    int k = 0;
    for(int i = 0; i < c1; i++){
        for(int j = 0; j < c2; j++){
            if(p1[i] == p2[j]){
                p1[i] = p1[i]-p2[j];
            }
            if(p1[i] != 0){
                k++;
            }
        }
    }
    printf("%d\n\n\n\n\n ",k);
   // return k;
}