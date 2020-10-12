//
// Created by valmyr on 02/10/2020.
//
#include "./ContaDePoupanca.h"
//iniciamento do atributo static
float ContaDePoupanca::taxaDeJurosAnual = 0;
//construtor
ContaDePoupanca::ContaDePoupanca(float saldoDaPoupanca){
    this->saldoDaPoupanca = saldoDaPoupanca;
}
//modificando taxa de juros
void ContaDePoupanca::modificarTaxaDeJuros(float taxaDeJurosAnual_){
    //transformando valor em porcentagem e atualizando atributo static taxaDeJurosAnual
    taxaDeJurosAnual = taxaDeJurosAnual_/100.0;
}
//set saldo
void ContaDePoupanca::setSaldoDaPoupanca(float saldoDaPoupanca){
    this->saldoDaPoupanca = saldoDaPoupanca;
}
//get saldo
float ContaDePoupanca::getSaldoDaPoupanca()const{
    return saldoDaPoupanca;
}
//cálcula o rendimento mensal
float ContaDePoupanca::calcularRendaMensal(){
    return (saldoDaPoupanca * taxaDeJurosAnual) / (12.0);
}
//retorna a taxa de Juros atual
float ContaDePoupanca::getTaxaDeJuros(){
    return taxaDeJurosAnual;
}
//interação com o usuário menu
int ContaDePoupanca::menu(){
    //variável auxliar
    int op;
    cout.fill('=');
    cout<<setw(50)<<" "<<endl;
    cout.fill(' ');
    cout<<setw(25)<<"DESEJA"<<endl;
    cout.fill('=');
    cout<<setw(50)<<" "<<endl;
    //opções
    cout<<"[1] Aumenta a taxa de juros anual"<<endl;
    cout<<"[2] Consultar saldo"<<endl;
    cout<<"[3] Consultar taxa de juros"<<endl;
    cout<<"[4] Sacar"<<endl;
    cout<<"[5] Depositar"<<endl;
    cout<<"[6] Mostra o rendimento mensal"<<endl;
    cout<<"[7] Sair"<<endl;
    cout<<setw(50)<<" "<<endl;
    cin>>op;
    //validamento de respostas
    validarResposta(op);
    //limpando tela
    system("cls");
    //retorna a oplçao informada
    return op;
}
//realiza o saque
bool ContaDePoupanca::saque(float sq){
    if(sq < 0 or sq > saldoDaPoupanca)
        //caso o valor de saque for menor que o ou maior que saldo retorno falso informnado que o saque não foi efetuado
        return false;
    //caso contrário o valor de saque e decrementado de saldo
    saldoDaPoupanca -= sq;
    //e retorna verdadeiro informando que o saque foi efetuado com sucesso
    return true;
}
bool ContaDePoupanca::deposito(float dp){
    if(dp < 0){
        return false;
    }
    saldoDaPoupanca += dp;
    return true;
}

void ContaDePoupanca::validarResposta(int &op){
    while(op > 6 or op < 0){
        cout<<"Opcao invalida:";cin>>op;
    }
}
void ContaDePoupanca::atualizarSaldo(){
    setSaldoDaPoupanca(saldoDaPoupanca + calcularRendaMensal());
}
ContaDePoupanca::~ContaDePoupanca(){
    cout<<"Desalocando"<<endl;
}
