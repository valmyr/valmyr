//
// Created by valmy on 21/01/2021.
//

#ifndef UNTITLED75_NEURAL_H
#define UNTITLED75_NEURAL_H
class Neural{
private:
    double *pesos;
    double tendencia;
    int tamanho;
public:
    Neural(int);
    double sigmoid(double );
    double run(double *);
    double treinamento(double *, double);
};
#endif //UNTITLED75_NEURAL_H
