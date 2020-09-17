#include <iostream>
using namespace std;
class ContaBancaria{
    string Nome;
    float Saldo;
    int Conta;
public:

    ContaBancaria();
    ContaBancaria(string Nome, int Conta, float Saldo);
    void Realizar_Saque();
    void Fazer_Deposito();
    float Consulta_Saldo();

    void Set_Nome(string Nome);
    void Set_Saldo(float Saldo);
    void Set_Conta(int Conta);

    string Get_Nome();
    float Get_Saldo();
    int Get_Conta();


};
//----------------------construtores------------------------------
ContaBancaria::ContaBancaria() {
    Nome = "Desconhecido";
    Saldo = 0;
    Conta = 0;
}
ContaBancaria::ContaBancaria(string Nome, int Conta, float Saldo) {
    this->Nome = Nome;
    this->Conta = Conta;
    this->Saldo = Saldo;
}

//-----------------------------------------------------------

//-----------------------------gets--------------------------
string ContaBancaria::Get_Nome(){
    return Nome;
}
float ContaBancaria::Get_Saldo(){
    return Saldo;
}
int ContaBancaria::Get_Conta(){
    return Conta;
}
//-----------------------------------------------------------
//------------------------sets-------------------------------
void ContaBancaria::Set_Conta(int Conta) {
    this->Conta = Conta;
}
void ContaBancaria::Set_Nome(string Nome) {
    this->Nome = Nome;
}
void ContaBancaria::Set_Saldo(float Saldo) {
    this->Saldo = Saldo;
}

//-------------------------------------------------------------
float ContaBancaria::Consulta_Saldo() {
    return Saldo;
}
void ContaBancaria::Fazer_Deposito() {
    float Deposito, op;
    cout<<"Informe o Valor do Deposito: ";cin>>Deposito;
    if(Deposito < 0) {
        cout << "Deposito não autorizado\n";
        cout << "Deseja Sair[1]\nTentar novamente[2]\n";
        cin >> op;
        while (op < 1 || op > 2) {
            cout << "Opcao invalida\n";
            cout << "Tente Novamente: ";
            cin >> op;
        }
        if (op == 2) Fazer_Deposito();
    }else
        Saldo+=Deposito;
}
void ContaBancaria::Realizar_Saque() {
    float Saque = 0; int  op = 0;
    cout<<"Informe o Valor do Saque: ";cin>>Saque;
    if(Saque > Saldo) {
        cout << "Saque nao autorizado\n";
        cout<<"Deseja Sair[1]\nTentar novamente[2]\n";
        cin>>op;
        while(op < 1|| op > 2){
            cout<<"Opcao invalida\n";
            cout<<"Tente Novamente: ";cin>>op;
        }
        if(op == 2) {
            Realizar_Saque();
        }
    }
    else {
        cout << "Saque autorizado\n";
        Saldo -= Saque;
    }
}
int main() {
    ContaBancaria C1("Valmir",1,20), C2("Stephanie",2,30);
    C1.Realizar_Saque();
    C2.Realizar_Saque();
    C1.Consulta_Saldo();
    C2.Consulta_Saldo();
    return 0;
}