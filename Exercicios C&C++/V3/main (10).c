#include <iostream>
#include<stdlib.h>
using namespace std;
void alocar_matriz(int ***m, int l, int c);
void desalocar_matriz(int **m, int l);
void Exibir(int **m,int l, int c);
int main() {
    int n, **matriz;
    while(1){
        cin>>n;
        if(n == 0){
            break;
        }
        alocar_matriz(&matriz,n,n);
        for(int i = 0; i < n ; i++){
            for(int j = 0;j < n; j++){
                if(!(n>2&&i >= 1&& j >=1 &&i<= n-2&&j<=n-2)){
                    matriz[i][j] = 1;
                }else{
                	if((n>2&&i >= 2&& j >=2 &&i<= n-3&&j<=n-3))
                 	   matriz[i][j] = 3;
                	else
                		matriz[i][j] = 2;
                }
            }
        }
        Exibir(matriz,n,n);
        desalocar_matriz(matriz,n);
        cout<<endl;

    }
    return 0;
}
void alocar_matriz(int ***m, int l, int c){
    int **retur;
    retur = (int**)malloc(sizeof(int*)*l);
    for(int i = 0; i < l; i++){
        retur[i]= (int*)malloc(sizeof(int)*c);
    }
    *m =retur;
}
void desalocar_matriz(int **m, int l){
    for(int i  =0; i < l; i++){
        free(m[i]);
    }
    free(m);
}
void Exibir(int **m,int l, int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cout<<fixed<<"  "<<m[i][j]<<"   ";
        }
        cout<<endl;
    }
}