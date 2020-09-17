#include <stdio.h>
//valmyrsilva7@gmail.com ajuda kkk
#include <stdlib.h>
#include <time.h>
#include <math.h>
void entradas(float **m,int l, int c);
void pesos(float **m,int l, int c);
float **produto_matrizes(float **P, int lp, int comum,float **E, int ep);
void Add_bias(float **m, int l, int c, int bias);
float** alocar_matrizes(int l,int c);
void Exibir(float **m, int l,int c);
void sigmoid(float **m, int l, int c);
int main(){
	srand(time(NULL));
	float **Entradas, **Pesos, **Produto_mais_bias, **Produto_matriz,**Sigmoid;
	Entradas = alocar_matrizes(2, 2);
	Pesos = alocar_matrizes(2, 2);
	entradas(Entradas, 2, 2);
	pesos(Pesos, 2, 2);
	printf("Entradas: \n");
	Exibir(Entradas, 2, 2);
	printf("...\n");
	printf("Pesos: \n");
	Exibir(Pesos, 2, 2);
	Produto_matriz = produto_matrizes(Pesos, 2, 2, Entradas, 2);
	Add_bias(Produto_matriz,2,2,1);
	printf("...\n");
	printf("Matriz com  bias: \n");
	Exibir(Produto_matriz, 2, 2);
	printf("...\n");
	printf("Sigmoid: \n");
	Sigmoid = Produto_matriz;
	sigmoid(Sigmoid,2,2);
	Exibir(Sigmoid, 2, 2);
	
	
}

void entradas(float **m,int l, int c){
	for(int i = 0;i < l;i++)
		for(int j = 0;j < c;j++){
			printf("indice [%d]x[%d] >>",i,j);
			scanf("%f",&m[i][j]);
		}
}
void pesos(float **m,int l, int c){
	for(int i =   0;i < l;i++)
		for(int j = 0;j < c;j++)
			m[i][j]=(float)(rand()%101)/100;
}
void Add_bias(float **m, int l, int c, int bias){
	for(int i = 0; i < l; i++)
		for(int j = 0; j < c; j++)
			m[i][j] += bias;
}
float **produto_matrizes(float **P, int lp, int comum,float **E, int ep){
	float **m;
	m = alocar_matrizes(lp, ep);
	for(int i = 0; i < lp; i++){
		for(int j = 0; j < ep; j++){
			float somatorio = 0;
			for(int k = 0; k < comum; k++){
				somatorio+=P[i][k]*E[k][j];
			}
			m[i][j]= somatorio;
		}
	}
	return m;
}
void sigmoid(float **m, int l, int c){
	float sigmoid = 0;
	for(int i = 0;i < l; i++){
		for(int j = 0;j < c;j++){
			sigmoid = (1 - exp(m[i][j]))/(1 + exp(m[i][j]));
			if(sigmoid >= 0){
				m[i][j] = 1;
			}
			else{
			    m[i][j] = -1;
			}
			
		}
	}
	
	
}
float** alocar_matrizes(int l,int c){
	float **m;
	m = malloc(sizeof(float*)*l);
	for(int i =   0;i < l;i++){
		m[i] = malloc(sizeof(float)*c);
		for(int j = 0; j < c; j++)
			m[i][j]=0;
	}
	return m;
}
void Exibir(float **m, int l,int c){
	for(int i =   0;i < l;i++){
		for(int j = 0;j < c;j++){
			printf("[%.2f]",m[i][j]);
		}
		printf("\n");
	}	
}