#include <stdio.h>
int SomaSerie(int i, int j,int k);
int main(){
    int i, j, k;
    printf("Informe o intervalo.\n Com as chaves e a virgula!\n Exemplo [i,j] \n>> ");scanf("[%d,%d]",&i,&j);
    printf("Informe o Valor de K >> ");scanf("%d",&k);
    printf("%d",SomaSerie(i,j,k));
    return 0;
}
int SomaSerie(int i, int j,int k){
    return i >= j ? j: i + SomaSerie(i+k,j,k);
}