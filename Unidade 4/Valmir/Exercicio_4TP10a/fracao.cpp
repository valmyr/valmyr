//
// Created by valmyr on 23/09/2020.
//
#include "./fracao.h"
Rational::Rational(){
    //atribuição por padrão 1 no numerador e 1 no denominador
    set_numerador(1);
    set_denominador(1);

}
Rational::Rational(int numerador, int denominador){
    //atribuir os valores que o desenvolvedor passou como argumentos da função aos atributos da class
    set_numerador(numerador);
    set_denominador(denominador);
}
Rational Rational::dividir(Rational f1, Rational f2){
    //Cálculo da divisão
    numerador = f1.numerador * f2.denominador;
    denominador = f1.denominador * f2.numerador;
    //simplificando divisão
    mdc(*this);
    //retornando objeto
    this->sinal();
}
Rational Rational::multiplicar(Rational f1, Rational f2){
    //Cálculo
    numerador =f1.numerador * f2.numerador;
    denominador = f1.denominador * f2.denominador;
    //simplificando
    //e passando por refêrencia o Objeto para que não precise usar return
    mdc(*this);
    //retonando objeto
    this->sinal();
}
void Rational::set_numerador(int numerador){
    //atribuindo valores ao atributo da class
    if(not(numerador)){
        cout<<"Fracao invalida informe numeros diferente de zero"<<endl;
        main();
    }
    this->numerador = numerador;
}
void Rational::set_denominador(int denominador){
    //atribuindo valores ao atributo da class
    //caso o denominado informando pelo usuário seja igual a zero o usuário recebe a mensagem
    //"Fracoes invalido informe numeros diferente de zero"
    if(not(denominador)){
        cout<<"Fracoes invalido informe numeros diferente de zero"<<endl;
        main();
    }
    //caso contrario o atributo recebe o valor informado
    this->denominador = denominador;
}
int Rational::get_numerador(void){
    //retornando numerador
    return numerador;
}
int Rational::get_denominador(void){
    //retornando denominador
    return denominador;
}
void Rational::mdc(Rational &fr){
    //usando o algoritmo de Euclides para determinar o mdc
    int numAux = fr.numerador;
    int denAux = fr.denominador;
    while(denAux != 0){
        int temp = numAux % denAux;
        numAux = denAux;
        denAux = temp;
    }
    //como estou acessando diretamente o endereço da variável FR não preciso usar return
    fr.numerador /= numAux;
    fr.denominador /= numAux;
}
void Rational::exibir(Rational F1, Rational F2, char sinal){
    //Exibindo a fração
    cout<<"("<<F1.numerador<<" / "<<F1.denominador<<") "<<sinal
    <<" ("<<F2.numerador<<" / "<<F2.denominador<<") = ";
}
void Rational::exibir(void){
    //precisão 2 casas decimais após a vírgula
    cout.precision(2);
    //exibindo o resultado
    cout<<"("<<numerador<<" / "<<denominador<<")";
    //Mostrando ponto flutuante
    cout<<endl<<"Ponto flutuante: "
    <<fixed<<(double)numerador/denominador<<endl;
}
void Rational::sinal(){
    //invertendo o sinal do resultado caso o denominador seja negativo
    if(denominador < 0){
        numerador*=-1;
        denominador*=-1;
    }
}
