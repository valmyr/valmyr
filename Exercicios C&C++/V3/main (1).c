#include <stdio.h>
#include <stdlib.h>
int main(){
	int soma=0, i = 1;
while(i<=500){
	if(i%3==0)
        soma=soma+i;
	i+=1;
}
printf("Soma: %d",soma);
return 0;
}