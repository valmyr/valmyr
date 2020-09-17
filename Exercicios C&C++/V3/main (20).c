#include <stdio.h>

#include<stdlib.h>



int main() {

    char m[5][10], v[10], pontos[5]; int i = 0, j = 0;

    printf("Informe as respostas de cada aluno >>\n");

    while(i < 5){

        printf("Aluno %d\n",i+1);

        j = 0;

        while(j < 10){

            while(1){

                printf("[%d][%d]>> ",i+1,j+1);

                scanf("%c",&m[i][j]);

                fflush(stdin);

                if((m[i][j]>='a'&& m[i][j] <= 'd')){

                    break;

                }else{

                    printf("Opcao invalida\n");

                }

            }

            j++;

        }

        i++;



    }



    printf("Informe o gabarito\n");

    for(int r = 0; r < 10; r++){

        printf("[%d]>> ",r+1);

        scanf("%c",&v[r]);

        fflush(stdin);

    }

    for(int i = 0; i < 5; i++){

        int soma_de_pontos = 0;

        for(int j = 0; j < 10; j++){

            if(m[i][j] == v[j]){

                soma_de_pontos+=1;

            }

        }

        pontos[i]= soma_de_pontos;

    }

    for(int i = 0; i < 5; i++){

        printf("Aluno %d fez %d pontos\n",i+1, pontos[i]);

    }



    return 0;

}