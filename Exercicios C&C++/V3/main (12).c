#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main() {
    int n, *v, menor, i;
    bool a = true;
    scanf("%d",&n);
    v = (int *)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        if(i <= n -1)
            scanf("%d ",&v[i]);
        else
            scanf("%d",&v[i]);
        if(a){
            menor = v[i];
        }else{
            if(menor > v[i]){
                menor = v[i];
            }
        }
    
        a = false;
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", i);
    
    return 0;
}