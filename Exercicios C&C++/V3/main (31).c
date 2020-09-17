#include <iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int **Alocar_matriz(int l, int c);
void Desalocar(int **m, int l);
void Exibir(int **m, int l, int c);
int **Preencher(int **m, int l, int c);
int main(){
    int **m, n;
    while(1){
        scanf("%d",&n);
        if(n <= 0){
            break;
        }
        m = Alocar_matriz(n,n);
        m = Preencher(m,n,n);
        Exibir(m,n,n);
        Desalocar(m,n);
    }
    
    return 0;
}
int **Alocar_matriz(int l, int c){
    int **m;
    m = (int**)malloc(sizeof(int*)*l);
    for(int i = 0; i < l; i++){
        m[i] = (int*)malloc(sizeof(int)*c);
    }
    return m;
}

void Exibir(int **m, int l, int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

int **Preencher(int **m, int l, int c){
    int cont = 1, cont_2 = 0;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            m[i][j] = pow(2,cont_2);
            cont_2++;
        }
        cont_2 = (2,cont);
        cont++;
    }
    return m;
}
void Desalocar(int **m, int l){
    for(int i = 0; i < l; i++){
        free(m[i]);
    }
    free(m);
}