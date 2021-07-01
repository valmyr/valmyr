#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1
int *alocarVetor(int);
int main(){
	int * vetor, *vetorImpar=NULL,*vetorPar=NULL;
	int size,sizeImpar=0,sizePar=0;
	srand(time(NULL));
	printf("Informe tamango do vetor:	"	);
	scanf("%d",&size);
	vetor = alocarVetor(size);
	for(int i =0;i < size;i++)
	    vetor[i]=1000+rand()%9000;
	
	for(int i = 0;i<size;i++)
	    printf("input v[%d] = %d\n",i,vetor[i]);
	printf("\n");
	for(int i = 0; i < size; i++){
		if(vetor[i] % 2 ==1){
			vetorImpar = (int*)realloc(vetorImpar,sizeof(int)*(sizeImpar+1));
			vetorImpar[sizeImpar++]=vetor[i];
		}else{
			vetorPar = (int*)realloc(vetorPar,sizeof(int)*(sizePar+1));
			vetorPar[sizePar++]=vetor[i];
		}
	}
	int j=0,k=0;
	for(int i = 0;i <size;i++){
		if(i < sizePar){
			vetor[i]=vetorPar[j++];
		}else{
			vetor[i]=vetorImpar[k++];
		}
		
	}
	for(int i = 0;i<size;i++)
	    printf("output v[%d] = %d\n",i,vetor[i]);
	return 0;
}
int* alocarVetor(int size){
     return (int*)(malloc(sizeof(int)*size));
}
