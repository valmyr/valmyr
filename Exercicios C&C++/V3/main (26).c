#include <stdio.h>
#include <math.h>
float fatorial(int n);
int main();
int main(){
	int x, n;
	printf("Informe o valor de x >>");scanf("%d",&x);
	printf("Informe o valor de n >>");scanf("%d",&n);
	int i = 0,sinal = 1;
	float cos_x = 0;
	while(i <= n){
		cos_x += (pow(x,i)/fatorial(i))*sinal;
		sinal*=-1;
		i+=2;
	}
	printf("cos(%d) = %f",x,cos_x);
}
float fatorial(int n){
	if(n == 0){
		return 1;
    }
    else{
    	
    	return n*fatorial(n-1);
    }
	
}