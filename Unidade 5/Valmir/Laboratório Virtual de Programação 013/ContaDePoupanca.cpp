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
    //convertendo o valor em porcentagem e atualizando atributo static taxaDeJurosAnual
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
//cálcular o rendimento mensal
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
    //aumentar a taxa de juros anual do poupador
    cout<<"[1] Aumenta a taxa de juros anual"<<endl;
    //mostrar o saldo
    cout<<"[2] Consultar saldo"<<endl;
    //mostrar o taxa de juros
    cout<<"[3] Consultar taxa de juros"<<endl;
    //sacar
    cout<<"[4] Sacar"<<endl;
    //depositar
    cout<<"[5] Depositar"<<endl;
    //Mostrar o rendimento mensal
    cout<<"[6] Mostra o rendimento mensal"<<endl;
    //fechar
    cout<<"[7] Sair"<<endl;
    cout<<setw(50)<<" "<<endl;
    cin>>op;
    //validamento de respostas
    validarResposta(op);
    //limpando tela do menu
    system("cls");
    //retorna a oplçao informada
    return op;
}
//realiza o saque
bool ContaDePoupanca::saque(float sq){
    //caso o valor de saque for menor que o ou maior que saldo retorno falso informnado que o saque não foi efetuado
    if(sq < 0 or sq > saldoDaPoupanca)
        return false;
    //caso contrário o valor de saque e decrementado de saldo
    saldoDaPoupanca -= sq;
    //e retorna verdadeiro informando que o saque foi efetuado com sucesso
    return true;
}
bool ContaDePoupanca::deposito(float dp){
    //caso o deposito seja menor que 0 retorno falso informando que o deposito falhou
    if(dp < 0)
        return false;
    //caso contrário o valor de deposito e incremendo ao saldo
    saldoDaPoupanca += dp;
    //retorno true informando que o deposito foi aceito
    return true;
}
//validamento de respostas
void ContaDePoupanca::validarResposta(int &op){
    while(op > 7 or op < 0){
        //caso o usuário informe uma opção invalida ele deve escolher outra opção válida
        cout<<"Opcao invalida:";cin>>op;
    }
}
void ContaDePoupanca::atualizarSaldo(){
    //atualizar o saldo com a taxa de juros atual
    setSaldoDaPoupanca(saldoDaPoupanca + calcularRendaMensal());
}
ContaDePoupanca::~ContaDePoupanca(){
    //destrutor
}
