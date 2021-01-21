#include "Neural.h"
Neural::Neural(int tamanho){
    this->tamanho = tamanho;
    this->pesos = new double[tamanho];
    for(int i = 0; i < this->tamanho;i++){
        this->pesos[i]= double(rand()/double(RAND_MAX));
        cout<<"Pesos "<<this->pesos[i]<<endl;
    }
    this->tendencia = double(rand()/double(RAND_MAX));
    cout<<"Tendencia "<<this->tendencia<<endl;

}
double Neural::sigmoid(double x) {
    return 1/(1+exp(-x));
}
double Neural::run(double *entradas) {
        double soma = 0;
        for(int i = 0; i < this->tamanho;i++){
            soma+=entradas[i]*this->pesos[i];
        }
        soma+=this->tendencia;
        return this->sigmoid(soma);

}
double Neural::treinamento(double * entradas,double alvo){
    double y = this->run(entradas);
    for(int i = 0; i < this->tamanho; i++){
        this->pesos[i]+=(alvo-y)*entradas[i];
    }
    this->tamanho+=(alvo-y);
}
