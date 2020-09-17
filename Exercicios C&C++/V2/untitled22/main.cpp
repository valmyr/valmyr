#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
struct banco{
    private:
        float saldo;
        long conta;
        float v_deposito;
        float v_saque;
    public:
        float get_float();
        void Inserir_contas(banco *b);
        void Inserir_saldos(banco *b);
        void saque(banco *b, long conta);
        bool verificar_saque(banco *b, long indc_cont);
        bool verificar_conta(banco *b, long indc_cont);
        void deposito(banco *b,long conta);
        void v_saldo(banco *b, long conta);

};
void banco::Inserir_contas(banco *b){
    for(int i(0); i < 20; i++)
        b[i].conta = i + 1;
}
void banco::Inserir_saldos(banco *b){
    for(int i(0);i < 20; i++)
        b[i].saldo = rand()%10001;
}
bool banco::verificar_saque(banco *b, long indc_cont){
    if(b[indc_cont-1].saldo - b[indc_cont-1].v_saque < 0)
        return 0;
    return 1;
}
void banco::saque(banco *b, long conta){
    int op;
    cout<<"Valor saque: R$";
    b[conta-1].v_saque = get_float();
    cout<<"Verficando saque\n";
    if(verificar_saque(b, conta)){
        cout<<"Saque autorizado\n";
        b[conta-1].saldo-= b[conta-1].v_saque;
    }else{
        cout<<"Saque nao autorizado\n";
        cout << "Sair/Novo Valor [1/2]: ";
        cin >> op;
        while(op < 0||op > 2) {
            cout<<"Opcao invalida: \n";
            cin >> op;
        }
        if(op == 2){
            saque(b,conta);
        }
    }
}
void banco::deposito(banco *b,long conta){
    int op;
    cout<<"Valor deposito: R$";
    b[conta-1].v_deposito = get_float();
    if(b[conta-1].v_deposito > 0){
        b[conta-1].saldo += b[conta-1].v_deposito;
    }else{
        cout<<"Deposito nao autorizado\n"<<endl;
        cout << "Sair/Novo Valor [1/2]:";
        cin >> op;
        while(op < 0 ||op > 2) {
            cin >> op;
        }
        if(op == 2){
            deposito(b,conta);
        }

    }
}
bool banco::verificar_conta(banco *b, long conta){
    for(int i (0); i < 20; i++)
        if(b[conta-1].conta == conta)
            return 1;
    return 0;
}
float banco::get_float() {
    float temp;
    cin>>temp;
    return temp;
}
void banco::v_saldo(banco *b, long conta){
    cout<<fixed<<"Saldo: R$"<<b[conta-1].saldo<<" reais"<<endl;
}
int main() {
    int op;
    cout.precision(2);
    srand(time(NULL));
    banco *usuarios = new banco[20];
    usuarios->Inserir_contas(usuarios);
    usuarios->Inserir_saldos(usuarios);
    cout<<"Bem Vindo"<<endl;
    cout<<"Deseja: \nSacar[1]\nDepositar[2]\nConsultar Saldo[3]\n";
    cin>>op;
    while(op < 1 || op > 3){
        cout<<"Opcao invalida"<<endl;
        cin>>op;
    }
    cout<<"Numero da conta: ";
    long conta;
    cin>>conta;
    while(usuarios->verificar_conta(usuarios,conta)  != 1) {
        cout<<"conta invalida";
        cin>>conta;
    }
    if(op == 1){
        usuarios->v_saldo(usuarios,conta);cout<<endl;
        usuarios->saque(usuarios, conta);
        usuarios->v_saldo(usuarios,conta);
        cout<<"Saque finalizado\n";
    }else if(op == 2){
        usuarios->v_saldo(usuarios,conta);cout<<endl;
        usuarios->deposito(usuarios, conta);
        usuarios->v_saldo(usuarios,conta);
        cout<<"Deposito finalizado\n";
    }else{
        usuarios->v_saldo(usuarios,conta);cout<<endl;
    }

}
