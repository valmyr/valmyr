#include <stdio.h>
float fatorial(float n);// calcula o faltorial por recursao 3! = 3*2*1=6
float pow_custom(float x, float y);//calcula x^y 2^2= 2*2 =4
int main(){
	float x ,n, sinal = 1, serie = 0;
	printf("Informe a quantidade de iteracoes >> ");scanf("%f",&n);
	printf("Informe o valor de x >>");scanf("%f",&x);
	
	for(int i = 0;i < n; i+=2){
		serie += pow_custom(x,i)/fatorial(i);
	}
	printf("serie >> %f",serie);
}
float pow_custom(float x, float y){
	float produtorio = 1;
	for(int i = 0;i < y;i++){
		produtorio*= x;
		
	}
	return produtorio;
}
float fatorial(float n){
	if(n == 0){
		
		return 1;
	}else{
		
		return n * fatorial(n-1);
	}
	
	
}
