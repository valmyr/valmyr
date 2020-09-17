/*Pessoal alguém sabe desenvolver um algoritmo mais simples para ordenar matrizes eu pensei nesse no caso pegar a matriz e transformar em um vetor e ordena o vetor porém e muito extenso...ou seja inviável tenho que alocar a matriz e o vetor*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
float **alocar_matriz(int linhas, int colunas);
void Exibir_Matriz(float **m,int  L,int C);
void Preenchendo_Matriz(float **m,int  L,int C);
void Organizar_Matriz(float **m,int  L,int C);
void Organizar_Vetor(float *v, int t);
void desalocar_matriz(float**m,int linhas);
float preencher(float **m,int linhas, int colunas);
//principal
int main(){
	srand(time(NULL));
	float **Matriz_numeros_aleatorios;
int l, c;
	l =1;c=1;
	printf("Informe a quatidade de linhas>>");scanf("%d",&l);
	printf("Informe a quatidade de colunas>>");scanf("%d",&c);
	printf("\n");
		Matriz_numeros_aleatorios = alocar_matriz(l, c);
		preencher(Matriz_numeros_aleatorios,l, c);
		Exibir_Matriz(Matriz_numeros_aleatorios,l, c);
	printf("\n");
		Organizar_Matriz(Matriz_numeros_aleatorios,l, c);
		Exibir_Matriz(Matriz_numeros_aleatorios,l, c);
	desalocar_matriz(Matriz_numeros_aleatorios,c);
	
}
//


float **alocar_matriz(int linhas, int colunas){
	float **m;
	m = (float**)malloc(sizeof(float*)*linhas);
	if(m == NULL){
		printf("Erro na alocacao");
		return 0;
	}
	for(int i = 0;i < linhas;i++){
		m[i] =(float*) malloc(sizeof(float)*colunas);
		if(m[i] == NULL){
			printf("Erro na alocacao");
			return 0;
		}
	}
	return m;
}
void Exibir_Matriz(float **m,int  L,int C){
	for(int i = 0;i< L;i++){
		for(int j = 0;j < C;j++){
			printf("[%.2f]	",m[i][j]);
		}
		printf("\n");
	}
}

void Organizar_Matriz(float **m,int  L,int C){
	float *v;
	int k = 0;
	v =(float*) malloc(sizeof(float)*L*C);
	for(int i = 0;i < L;i++){
			for(int j = 0;j < C;j++){
				v[k]=m[i][j];
				k++;
			}
		}
	Organizar_Vetor(v, L*C);
		k = 0;
		for(int i = 0;i < L;i++){
			for(int j = 0;j < C;j++){
				m[i][j] = v[k];
				k++;
			}
		}
		
		free(v);
	
}
void Organizar_Vetor(float *v, int t){
	float aux1,aux2;
	for(int i = 0;i < t;i++){
		for(int j = i; j < t ;j++){
			if(v[i]>v[j]){
				aux1=v[i];
				aux2 =v[j];
				v[i]= aux2;
				v[j] = aux1;
			}
			
		}
	}
}
void desalocar_matriz(float**m,int linhas){
	for(int i = 0;i < linhas;i++){
		free(m[i]);

	}
	free(m);
		printf("\nMatriz desalocada\nFim...");


}
float preencher(float **m,int linhas, int colunas){
	for(int i = 0;i < linhas;i++){
		for(int j = 0; j < colunas;j++){
			m[i][j] = (float)(rand()%101)*(0.2);//prenchendo matriz
		}
	}
}