#include <stdio.h>
/*
        4 3 2 1


*/
int main()
{
    int vetor[2][2] = {4,3,2,1};
    int aux1, aux2, temp = vetor[0][0];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) {
            if(temp > vetor[i][j]){
                aux1 = vetor[i][j];
                vetor[i][j] = temp;
                vetor[i][j+1]= aux1;

            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++)
            printf("\n\n%d ",vetor[i][j]);
    }
    return 0;
}
