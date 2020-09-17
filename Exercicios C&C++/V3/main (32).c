/*Pessoal existe uma maneira de diminuir a quantidade de argumentos da função super fatorial*/
#include <stdlib.h>
#include <stdio.h>
float super_fatorial(float n, float k);
int main(){
	int limite;
	printf("Informe o valor do limite >>");scanf("%d",&limite);
	for(float i = 0;i <= limite;i++)
		printf("O super fatorial de %.f 	= %.f\n",i,super_fatorial(i, i));
	
}
float super_fatorial(float n, float k){
	if(n == 0)
		if(k == 0)
			return 1;
		else
			return super_fatorial(k-1, --k);
    else
		return n * super_fatorial(n - 1, k);
}