#include <iostream>
#include <cmath>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<ctime>
using namespace std;
int **cofatores(int **matriz, int sizeMatriz, int linhaExcluir, int colunaExcluir);
void inserirManualmente(int ***matriz, int sizeMatriz);
void inserirAleatoriamente(int ***matriz, int sizeMatriz, int intervalorDeVariacao);
int **alocarMatriz(int sizeMatriz);
void exibirMatriz(int **matriz, int sizeMatriz);
int determinanteMatriz(int **m, int sizeMatriz);
int main(){
    srand(time(NULL));
    int **matriz; int t = 5, op;
    cout.fill('=');
    cout<<"Informe a ordem da matriz: ";
    cin>>t;
    cout<<setw(50)<<" "<<endl;
    cout.fill(' ');
    cout<<setw(25)<<"Deseja"<<endl;
    cout.fill('=');
    cout<<setw(50)<<" "<<endl;
    cout<<"[1] Inserir aleatoriamente"<<endl;
    cout<<"[2] Inserir manualmente"<<endl;
    cout<<setw(50)<<" "<<endl;
    cin>>op;
    switch (op){
        case 2:
            inserirManualmente(&matriz,t);
            break;
        case 1:
            cout<<"Informe o limite de variacao dos numeros aleatorios: ";
            cin>>op;
            inserirAleatoriamente(&matriz,t,op+1);
            break;
    }
     cout<<endl;
     exibirMatriz(matriz,t);
     cout<<endl;
     cout<<"A determinante d matriz e"<<endl;
     cout<<"Det(M) = "<<determinanteMatriz(matriz,t)<<endl<<endl;
     cout<<endl<<"[0] Reiniciar?";cin>>op;
     if(not(op)){
         system("cls");
         main();
    }
     return 0;
}
void exibirMatriz(int **matriz, int sizeMatriz){
    cout.fill('0');
    for(int i = 0; i < sizeMatriz; i++){
        for(int j = 0; j < sizeMatriz; j++){
            cout<<setw(2)<<" "<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}
int **alocarMatriz(int sizeMatriz){
    int **mAux;
    mAux = (int**)new int*[sizeMatriz];
    for(int i = 0; i < sizeMatriz; i++){
       mAux[i] = (int*)new int[sizeMatriz];
       for(int j = 0; j < sizeMatriz; j++)
            mAux[i][j] = 0;
    }
    return mAux;
}
int **cofatores(int **matriz, int sizeMatriz, int linhaExcluir, int colunaExcluir){
    int **mAux = alocarMatriz(sizeMatriz -1);
    int k = 0, p = 0 ;
    for(int i = 0; i < sizeMatriz; i++){
        for(int j = 0; j < sizeMatriz; j++){
            if(j != colunaExcluir and i != linhaExcluir){
                mAux[p][k] = matriz[i][j];
                k++;
            }
        }
        if(i != linhaExcluir){
            p++;
            k = 0;
        }
    }
    return mAux;
}
int determinanteMatriz(int **m, int sizeMatriz){
    int det = 0;
    if(sizeMatriz-1 == 0){
        return m[0][0];
    }else{
        for(int j = 0; j < sizeMatriz; j++){    
            if(m[0][j])
                det+=  m[0][j]*pow(-1,j)*determinanteMatriz(cofatores(m,sizeMatriz,0,j),sizeMatriz-1); 
        } 
        return  det;
    }

}
void inserirManualmente(int ***matriz, int sizeMatriz){
    int **mAux = alocarMatriz(sizeMatriz);
    for(int i = 0; i < sizeMatriz; i++){
        for(int j = 0; j < sizeMatriz; j++){
            cout<<"["<<i<<"]"<<"["<<j<<"] >>";
            cin>>mAux[i][j];
        }
    }
    *matriz = mAux;
}
void inserirAleatoriamente(int ***matriz, int sizeMatriz, int intervalorDeVariacao){
    int **mAux = alocarMatriz(sizeMatriz);
    for(int i = 0; i < sizeMatriz; i++){
        for(int j = 0; j < sizeMatriz; j++){
            mAux[i][j]= rand()%intervalorDeVariacao;
        }
    }
    *matriz = mAux;
}
