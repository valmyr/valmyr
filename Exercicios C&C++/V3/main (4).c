#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

char cartas [13] = {'A','2','3','4','5','6','7','9','X','J','Q','K'};
char nipes [4][8] = {"Ourinho","Espadas","Copas","Paus"};
int resposta;


	int main(int argc, char *argv[]) {

do{
	setlocale(LC_ALL,"Portuguese");
		system("color A");
		srand(time(NULL));
		system("cls");
		printf("SEJA BEM-VINDO AO JOGO CARTAS\n");
		printf("Você Tirou um %c de %s ",cartas[rand()%14],nipes[rand()%8]);
		printf("1-Outra Rodada\n");
		printf("2-Sair do Jogo\n");
		printf("Digite a opção deseja: \n");
		scanf("%d",&resposta);
		system("cls");
		
}while(resposta!=2);
	system("pause");
	return 0;
}