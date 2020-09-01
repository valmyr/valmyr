#include <stdio.h>
#include <stdlib.h>
int **Alocar_Matriz(int linhas, int colunas);//Alocacao dinamica de matrizes
void Exibir_Matriz(int **m, int linhas, int colunas);
int main(){
	int **Matriz, **Matriz_Transpo, linhas, colunas, somatorio = 0, somatoriotransposta = 0;
	printf("Informe a quantidade de linhas da matriz >> ");scanf("%d",&linhas);
	printf("Informe a quantidade de colunas da matriz >> ");scanf("%d",&colunas);
	printf("Dimesoes [%d]x[%d]\n",linhas,colunas);
	Matriz = Alocar_Matriz(linhas, colunas);
	Matriz_Transpo = Alocar_Matriz(colunas,linhas);
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			printf("Indece [%d][%d] >> ",i,j);scanf("%d",&Matriz[i][j]);
		    Matriz_Transpo[j][i] = Matriz[i][j];//matriz transposta
		}
	}
	printf("Matriz :\n");
	Exibir_Matriz(Matriz, linhas, colunas);
	printf("Matriz transposta :\n");	
	Exibir_Matriz(Matriz_Transpo, colunas,  linhas);
	
	
	for(int i = 0; i < colunas; i++){
		somatorio+=Matriz[0][i];
	}
	for(int i = 0; i < linhas; i++){
		somatoriotransposta+=Matriz[i][0];
	}
	printf("\nSomatorio das colunas da primeira linha da matriz = %d",somatorio);	
	printf("\nSomatorio das linhas da primeira coluna da matriz transposta = %d",somatoriotransposta);
	
}
int **Alocar_Matriz(int linhas, int colunas){
	int **m;
	m = malloc(sizeof(int*)*linhas);
	for(int i = 0;i < linhas; i++){
		m[i]= malloc(sizeof(int)*colunas);
		
	}
   return m;	
}
void Exibir_Matriz(int **m, int linhas, int colunas){
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			printf("[	%d	]",m[i][j]);
		}
		printf("\n");
	}
	
}
