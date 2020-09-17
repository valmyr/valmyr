#include<stdio.h>
int main(){
    double m[3][6], soma_coluna_im = 0,soma_2_e_4 = 0, cont = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            printf("[%d][%d] >>",i,j);
            scanf("%lf",&m[i][j]);
        }
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            if(i % 2 != 0){
                soma_coluna_im+=m[j][i];
            }
            if(i == 1 || i ==3){
                soma_2_e_4+=m[j][i];
                cont++;
            }
        }
    }
    printf("Soma de todas as colunas impares %lf \n media das colunas 2 e 4 %lf\n",soma_coluna_im,soma_2_e_4/cont);
    
    for(int j = 0; j < 3; j++){
        m[j][5] = m[j][0]+m[j][1];
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            printf("[%.2lf]",m[i][j]);
        }//
        printf("\n");
    }
}