#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
#include "Neural.cpp"

int main(){
    srand(time(NULL));
    double treinamentoValores[4][2] = {
            {0,0},
            {1,0},
            {0,1},
            {1,1}
    };

    double alvos[4] = {0,1,1,1};
    Neural net(2);
    int iteracoes = 0;

    while(iteracoes < 100){
        for(int i = 0; i < 4; i++){
            net.treinamento(treinamentoValores[i],alvos[i]);
            cout<<"Alvo: "<<alvos[i]<<" Entrada: "<<net.run(treinamentoValores[i])<<"epocas: "<<iteracoes<<"indece: "<<i+1<<endl;
        }
        iteracoes+=1;
    }
    cout<<"Treinamento completo"<<endl;


    return 0;
}
