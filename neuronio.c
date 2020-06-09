#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
float derivada(float n);
int main(){
	float x, y = .7, w,s=0,epocas;
	x = (float)(rand()%101)/100;
	printf("Informe a saida> >>");scanf("%f",&y);
	y /= 100;
	printf("Informe a quantidade de epocas >>");scanf("%f",&epocas);
	w =(float)(rand()%101)/100;
	
	printf("entrada =  %f\n",x);
	printf("peso = %f\n",w);
	printf("saida = %f\n\n",y);
	
	//treinamento
	for(int i = 0;i < epocas;i++){
		s = tanh(x*w);
		w += x * derivada(y - s);
		printf("Epoca [%d] = %f\n",i,s*100);
	}
	
	
}
float derivada(float n){
	return n*(1-n);
}