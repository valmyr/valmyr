#include <stdio.h>
//Agora roda!!!
int main (){
	int produto;
printf("quanto vc gastou?");
scanf("%d",&produto);
    if(produto>1500){// tinha um espaço aleatório
        printf("A compra foi taxada");//faltava um ponto e vírgula
    }
    else {
        printf("Esta dentro dos conformes");//faltava um ponto e vírgula
    }
return 0;
}