#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char **Alocar_Matriz(int linhas, int colunas);
char *Vetor_Alfabeto();
void Matriz_Preencher_Aleatoriamente(char **m, int linhas,int colunas, char *vetor);	
int Contar_Letras(char **m, int linhas, int colunas);
int Contar_Vogais(char **m, int linhas, int colunas);
void Exibir_Matriz(char **m, int linhas, int colunas);
char letra_mais_ocorrente(char **m, int linhas,int colunas, char *vetor);
int letra_B_1(char **m, int linhas, int colunas);
int main(){
	srand(time(NULL));
	int tamanho;
	char **Matriz_Alfabeto, *vetor;
	vetor = Vetor_Alfabeto();
	printf("Informe a dimesao da matriz >>");scanf("%d",&tamanho);
	Matriz_Alfabeto = (char**)Alocar_Matriz(tamanho,tamanho);
	Matriz_Preencher_Aleatoriamente(Matriz_Alfabeto, tamanho, tamanho, vetor);
	Exibir_Matriz(Matriz_Alfabeto,tamanho,tamanho);
	printf("O numero de vezes que o a caracter a e A apareceram =  %d\n",Contar_Letras(Matriz_Alfabeto, tamanho, tamanho));
	printf("A Quantidade de Vogais que a matriz contem = %d\n",Contar_Vogais(Matriz_Alfabeto, tamanho, tamanho));
		printf("O caraceter mais recorrente = %c\n",letra_mais_ocorrente(Matriz_Alfabeto, tamanho, tamanho, vetor));
	if(letra_B_1(Matriz_Alfabeto,tamanho,tamanho)==1){
			printf("B");
	}else{
		printf("-1");
	}
printf("\n");
	return 0;
}	
char **Alocar_Matriz(int linhas, int colunas){
	char **m;
	m = (char**)malloc(sizeof(char*)*linhas);
	for(int i = 0; i < linhas; i++){
		m[i] = (char*)malloc(sizeof(char)*colunas);
	}
	return m;
}
char *Vetor_Alfabeto(){
	char Alfa_Min = 'a', Alfa_Ma = 'A', *Vetor;
	Vetor = malloc(sizeof(char)*52);
	for(int i = 0; i < 26; i++){
		Vetor[i] = Alfa_Min;
		Alfa_Min++;
	}
	for(int i = 26; i < 52; i++){
		Vetor[i] = Alfa_Ma;
		Alfa_Ma++;
	}
	return Vetor;
}
void Matriz_Preencher_Aleatoriamente(char **m, int linhas,int colunas, char *vetor){
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			m[i][j] = vetor[rand()%53];
		}
	}
}
void Exibir_Matriz(char **m, int linhas, int colunas){
	
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			printf("[%c]",m[i][j]);
		}
		printf("\n");
	}

}
int Contar_Letras(char **m, int linhas, int colunas){
	char letra_Mi = 'a', letra_Ma = 'A';int cont = 0;
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			if(letra_Mi == m[i][j] || letra_Ma == m[i][j])
					cont++;
		}
	}
	return cont;
}
int Contar_Vogais(char **m, int linhas, int colunas){
	char Vogais[10] = {'A','E','I','O','U','a','e','i','o','u'};
	int cont = 0;
		for(int i = 0; i < linhas; i++){
			for(int j = 0; j < colunas; j++){
					int k = 0;				
					while(k < 10){
						if(Vogais[k] == m[i][j]){
							cont++;
						}	
						k++;
					}	
			}
		}
	return cont;
}
char letra_mais_ocorrente(char **m, int linhas,int colunas, char *vetor){
int cont_1 = 0, cont_2 = 0, aux_1 = 90000000, aux_2 = 9999999;
int g, h, f, l; //indices auxiliares
	for(int k = 0, z = 26; k < 26; k++, z++){	
		for(int i = 0; i < linhas; i++){
			for(int j = 0; j < colunas; j++){
					if(vetor[k] == m[i][j]){	
							cont_1++;
					}
					if(cont_1 < aux_1){
						aux_1 = cont_1;
						g = i;
						h = j;
					}
					if(vetor[z] == m[i][j]){	
						cont_2++;
					}
					if(cont_2 < aux_2){
						aux_2 == cont_2;
						f = i;
						l = j;
					}
			}
		}
	}		
	if(aux_1 < aux_2){
		return m[g][h];
	}else{
		return m[f][l];
	}		
		
}	
int letra_B_1(char **m, int linhas, int colunas){
	char letra = 'B';int cont = 0;
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			if(letra == m[i][j])
					cont++;
		}
	}
	if(cont != 0){
		return 1;
	}else{
		return -1;
	}
}