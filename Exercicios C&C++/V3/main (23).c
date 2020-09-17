#include<stdio.h>
int Situacao_Aluno(float Media_Final, int N_Faltas, int Q_Horas);
int main(){
	float Media;
	int Faltas, Q_Horas, cont = 0;
	printf("Informe a sua media o numero de faltas e a quantidade de horas respectivamente\n");
	do{
		do{		
			printf("[M] >>");scanf("%f",&Media);
			if(Media == -1){
				break;
			}
		}while(!(Media >=0 && Media <= 100));
			if(Media == -1){
				break;
			}
		printf("[F] >>");scanf("%d",&Faltas);
		printf("[H] >>");scanf("%d",&Q_Horas);
		printf("Media = %.f\n Numero de faltas = %d\n  Quatidade de Horas = %d\n",Media,Faltas,Q_Horas);
		if(Situacao_Aluno(Media,Faltas,Q_Horas) == 1){
			printf("Parabens voce foi aprovado!!!\n");
		}else{
			printf("Infelizmente voce foi reprovado\n");
		}
		
	}while(1);


}

int Situacao_Aluno(float Media_Final, int N_Faltas, int Q_Horas){

	if(Media_Final >= 60){//considerando que 1h sao uma aulas
		if(N_Faltas == 0||100 - (N_Faltas * 100 * 1/Q_Horas) >= 75){
			return 1;
		}
	}else{
		return 0;
	}
}