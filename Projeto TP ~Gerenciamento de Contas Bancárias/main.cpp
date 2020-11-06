#include <iostream>
#include <fstream>
using namespace std;
#include"./Conta.cpp"
#include"./ContaPoupanca.h"
int main(){
    Endereco p;
    p.CEP ="13737838374";
    p.cidade ="Alagoas";
    p.estado = "Arapiraca";
    p.rua = "rt";
    Conta *b = new ContaPoupanca("Valmir Ferreira da Silva",1289373876,21,300000,p);

    b->imprimir();
    b->sacar(1000);
    b->imprimir();
    b->depositar(1000);
    b->imprimir();
}
