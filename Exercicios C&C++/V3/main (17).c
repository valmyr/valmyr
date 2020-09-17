#include<stdio.h>
int main(){
	int v[20], media = 0,v_2[20], cont  = 0, moda = 0;
printf("Informe os valores do vetor\n");
	for(int i = 0; i < 20; i++){
		printf("[%d]>> ",i);scanf("%d",&v[i]);
		media += v[i];
		v_2[i] = v[i];
	}
	printf("Os numeros digitados ...\n");
	for(int i = 0; i <20; i++){
		for(int j = 0; j < 20; j++){
			if(v[i] == v_2[j]){
				cont++;
			}
		}
		
		if(!i){
			moda = cont;
		}else{
			if(moda < cont){
				moda = cont;
			}
		}
		cont = 0 ;
		printf("[%d] ",v[i]);
	}
	float mediana = (v[8]+v[9])/2.0;
	printf("A media de numeros do vetor e %.2f",media/20.0);
	printf("A mediana e %.2f",mediana);
	printf("A moda e %d",moda);
	return 0;
}