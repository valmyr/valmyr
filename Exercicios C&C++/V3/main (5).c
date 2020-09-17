#include <stdio.h>
int main(){
	int v[5]={1,2,1,3,2},cont = 0;
	for(int i = 0;i < 5;i++){
		cont = 0;
		for(int j = 0;j < 5;j++){
			if(v[i]==v[j]){
				cont +=1;
			}
		}
		if(cont == 1){
			printf("%d ",v[i]);
        }
	}
}