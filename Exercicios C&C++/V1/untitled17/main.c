#include <stdio.h>
#include <stdlib.h>
#include<time.h>
float **alocar_matriz(int linhas, int colunas);
void Exibir_Matriz(float **m,int  L,int C);
void Preenchendo_Matriz(float **m,int  L,int C);
void Organizar_Matriz(float **m,int  L,int C);

int main(){
	srand(time(0));
	float **Matriz_numeros_aleatorios;
		Matriz_numeros_aleatorios = alocar_matriz(2, 2);
		Preenchendo_Matriz(Matriz_numeros_aleatorios, 2, 2);
		Exibir_Matriz(Matriz_numeros_aleatorios, 2, 2);
			printf("\n");
		Organizar_Matriz(Matriz_numeros_aleatorios, 2, 2);
		Exibir_Matriz(Matriz_numeros_aleatorios, 2, 2);

}


float **alocar_matriz(int linhas, int colunas){
	float **m;
	m = malloc(sizeof(float*)*linhas);
	for(int i = 0;i < colunas;i++){
		m[i] = malloc(sizeof(float));
	}
	return m;
}

void Preenchendo_Matriz(float **m,int  L,int C){
	float cont = 4;
	for(int i = 0;i< L;i++){
		for(int j = 0;j < C;j++){
			m[i][j] = cont;
			++cont;//(float)(rand()%101);
		}
	}
}
void Exibir_Matriz(float **m,int  L,int C){
	for(int i = 0;i< L;i++){
		for(int j = 0;j < C;j++){
			printf("[%.2f]",m[i][j]);
		}
		printf("\n");
	}
}


/*
            4 3
            2 1

            3 4
            2 1

            3 2
            4 1

            3 2
            1 4

            2 3
            1 4

            2 1
            3 4

            1 2
            3 4

*/


void Organizar_Matriz(float **m,int  L,int C){
	float buffer_1,buffer_2;
	for(int i = 0;i < L;i++){
		for(int j = 0;j < C;j++){
		    for(int k  = j; k < L; k++) {
                printf("%d %d\n",i,j);
                if(m[i][j] > m[i][j]){
                    printf("%d",m[i][j]);

                }

            }
		}
	}

}
