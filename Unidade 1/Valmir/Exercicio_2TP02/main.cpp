/*
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
    Laboratório Virtual de Programação 02
Escreva um programa que utilize enumeradores com as matérias do seu período. Inicialize cada matéria com um número. Depois imprima os valores das variáveis enumeradas.
*/
#include <iostream>
using namespace std;
enum disc_2p{ALGEBRA_LINEAR_I = 1 ,CALCULO_DIFERENCIAL_E_INTEGRAL_II = 2,FISICA_EXPERIMENTAL_I = 3,FISICA_GERAL_II = 4,QUIMICA = 5,TECNICAS_DE_PROGRAMACAO = 6};
int main(){
    disc_2p M = ALGEBRA_LINEAR_I;
    cout<<"ALGEBRA LINEAR I: "<<M<<endl;
    M = CALCULO_DIFERENCIAL_E_INTEGRAL_II;
    cout<<"CALCULO DIFERENCIAL E INTEGRAL II: "<<M<<endl;
    M = FISICA_EXPERIMENTAL_I;
    cout<<"FISICA EXPERIMENTAL: "<<M<<endl;
    M = FISICA_GERAL_II;
    cout<<"FISICA GERAL II: "<<M<<endl;
    M = QUIMICA;
    cout<<"TECNICAS DE PROGRAMACAO: "<<M<<endl;
}
