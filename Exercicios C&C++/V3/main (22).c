#include <stdlib.h>
#include <stdio.h>
int main(){
	float matriz[3][3],vetor_colunas[3],vetor_linhas[3];
	printf("Insira os valores da matriz\n");
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			printf("[%d][%d]>>",i,j);
			scanf("%f",&matriz[i][j]);//Inserindo os valores na matriz
		}
	}
	int k = 0;//variavel que usarei nos vetores
	printf("Matriz informada >>\n");//mostrando a matriz
	for(int i = 0;i < 3;i++){
		float somatorio_linhas = 0;//variavel auxiliar para a soma das linhas
		float somatorio_colunas = 0;//variavel auxiliar para a soma das colunas
		for(int j = 0; j < 3;j++){
			
			printf("[%.2f	]",matriz[i][j]);
			somatorio_linhas += matriz[i][j];//fazendo a soma da linhas
			somatorio_colunas += matriz[j][i];//fazebdo a soma das colunas
		}
		vetor_linhas[k] = somatorio_colunas;//atribuindo  soma das linhs ao vetor linhas no indece k
		vetor_colunas[k] = somatorio_linhas;//atribuindo  soma das linhs ao vetor coluna no indece k
		k++;//indo para o proximo indece				
		printf("\n");
		
	}
	float soma_total = 0;
	printf("Soma de cada coluna >>\n");
	for(int k = 0;k < 3; k++){
		printf("[%.f	]\n",vetor_colunas[k]);//mostrando a soma das columas
		soma_total+= vetor_colunas[k];//somando cada valor das colunas
		
	}

	printf("Soma de cada linha >>\n");	
	for(int k = 0;k < 3; k++){
		printf("[%.f	]\n",vetor_linhas[k]);//mostrando a soma das linhas
		soma_total += vetor_linhas[k];//somado cada valor das linhas
		
	}
	printf("soma total %.2f",soma_total);//mostrando a soma total
	return 0;
}