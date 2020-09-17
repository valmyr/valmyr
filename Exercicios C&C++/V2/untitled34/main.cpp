#include <iostream>
#include<iomanip>
int main();
using namespace std;
class contaBancaria{
    string nome;
    float saldo;
    int conta;
public:

    contaBancaria();
    void realizar_Saque();
    void fazer_Deposito();
    float consulta_saldo();

    void set_nome(string nome);
    void set_saldo(float saldo);
    void set_conta(int conta);

    string get_nome();
    int get_conta();
    int menu();
    bool verificar_Conta(int conta);


};
//----------------------construtores------------------------------
contaBancaria::contaBancaria() {
    nome = "Desconhecido";
    saldo = 0;
    conta = 0;
}
//-----------------------------------------------------------

//-----------------------------gets--------------------------
string contaBancaria::get_nome(){
    return nome;
}
int contaBancaria::get_conta(){
    return conta;
}
//-----------------------------------------------------------
//------------------------sets-------------------------------
void contaBancaria::set_conta(int conta) {
    this->conta = conta;
}
void contaBancaria::set_nome(string nome) {
    this->nome = nome;
}
void contaBancaria::set_saldo(float saldo) {
    this->saldo = saldo;
}

//-------------------------------------------------------------
float contaBancaria::consulta_saldo() {
    return saldo;
}
void contaBancaria::fazer_Deposito() {
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
        if (op == 2) fazer_Deposito();
    }else{
        cout<<"Deposito aceito.\n";
        saldo+=Deposito;
    }
}
void contaBancaria::realizar_Saque() {
    float Saque = 0; int  op = 0;
    cout<<"Informe o Valor do Saque: ";cin>>Saque;
    if(Saque > saldo) {
        cout << "Saque nao autorizado\n";
        cout<<"Deseja Sair[1]\nTentar novamente[2]\n";
        cin>>op;
        while(op < 1|| op > 2){
            cout<<"Opcao invalida\n";
            cout<<"Tente Novamente: ";cin>>op;
        }
        if(op == 2) {
            realizar_Saque();
        }
    }
    else {
        cout << "Saque autorizado.\n";
        saldo -= Saque;
    }
}
int contaBancaria::menu(){
    int op;
    cout.fill('=');
    cout<<setw(25)<<"DESEJA"<<setw(25);
    cout<<"\n";
    cout<<"[1]  Sacar\n[2]  Depositar\n[3]  Saldo\n[4]  Sair\n";
    cout<<setw(50)<<""<<endl;
    cin>>op;
    return op;
}
bool contaBancaria::verificar_Conta(int conta){
    while(conta < 1 or conta > 2){
        cout<<"Conta invalida\n";
        cout<<"Tente novamente: ";
        cin>>conta;
    }
    return true;

}
int main() {
    contaBancaria *c1 = new contaBancaria[2];
    int conta;
    c1[0].set_nome("Valmir");
    c1[0].set_conta(1);
    c1[0].set_saldo(20);
    c1[1].set_nome("Stephaine");
    c1[1].set_conta(2);
    c1[1].set_saldo(30);
    while(true){
        int op = c1->menu();
        if (op < 4) {
            cout << "Conta: ";
            cin >> conta;
            c1->verificar_Conta(conta);
            cout << "Titular: " << c1[conta - 1].get_nome() <<"\nConta: "<<c1[conta-1].get_conta()<<endl;
            switch (op) {
                case 1:
                    c1[conta - 1].realizar_Saque();
                    break;
                case 2:
                    c1[conta - 1].fazer_Deposito();
                    break;
                case 3:
                    cout << "Saldo atual: " << c1[conta - 1].consulta_saldo() << endl;
                    break;
                default:
                    cout << "impossivel";
            }
        } else
            return 0;
    }
}