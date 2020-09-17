#include <stdio.h>
#include <stdlib.h>
int **alocarmatriz(int linhas,int colunas);
void Exibir_matriz(int **m, int linhas, int colunas);
int main(){
	int n,k = 1,**m;
	printf("Informe o valo de n>>");scanf("%d",&n);
	m = alocarmatriz(n, n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			m[i][j]=k;	
			k++;		
		}
	}
Exibir_matriz(m, n, n);
	
}

int **alocarmatriz(int linhas,int colunas){
	int **m;
	m = malloc(sizeof(int*)*linhas);
	
	for(int i = 0;i < linhas;i++){
		m[i]= malloc(sizeof(int)*colunas);
		for(int j = 0;j < colunas;j++){
			m[i][j]=0;			
		}
	}
	return m;
}

void Exibir_matriz(int **m, int linhas, int colunas){
    for(int i = 0;i < linhas;i++){
		for(int j = 0;j < colunas;j++){
				printf("[%d]	",m[i][j]);
		}
		printf("\n");
	}
}