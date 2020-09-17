#include<stdio.h>
int main(){
	printf("Informe 10 temperaturas>>\n");
	float v[10], maior = 0, cont = 0,media = 0;
	for(int i = 0; i < 10; i++){
		printf("[%d]>> ",i);scanf("%f",&v[i]);
		media+= v[i];
		if(v[i] > maior){	
			maior = v[i];
	
		}
	}
	printf("\n");
	for(int i = 0; i < 10; i++){
		printf("[%.2f] ",v[i]);
		if(media /10 >  v[i]){
			cont++;
		}
	}
	printf("A maior temperatura foi %.2f\n",maior);
	printf("A media de temperaturas e %.2f\n",media/10);
	printf("O numero de dias em que a temperatura foi maior que a media %.2f dias\n",cont);
	return 0;
}