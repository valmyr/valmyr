#include <iostream>
#include <iomanip>
using namespace std;
#include "./ContaDePoupanca.cpp"


int main() {
    //instacianmento de um objeto
    ContaDePoupanca *Poupador = (ContaDePoupanca *)new ContaDePoupanca[2];
    int op0, op1;
    float p, juros,sq,dp;
    cout<<"Saldo[BRL] do poupador 1: ";cin>>p;
    Poupador[0].setSaldoDaPoupanca(p);
    cout<<"Saldo[BRL] do poupador 2: ";cin>>p;
    Poupador[1].setSaldoDaPoupanca(p);
    while(true){
        cout<<"[1] Poupador"<<endl;
        cout<<"[2] Poupador"<<endl;
        cin >> op0;
        system("cls");
        while(op0 > 2 or op0 < 1){
            cout<<"Opcao invalida: ";
            cin>> op0;
        }
        op1=Poupador[op0-1].menu();
        switch(op1){
            case 1:
                cout<<"Informe a porcentagem do aumento: ";
                cin>>juros;
                ContaDePoupanca::modificarTaxaDeJuros(juros);
                Poupador[op0-1].atualizarSaldo();
                break;
            case 2:
                cout<<"["<<op0<<"]  Saldo atual "<<Poupador[op0-1].getSaldoDaPoupanca()<<"BRL"<<endl;
                break;
            case 3:
                cout<<"Taxa de juros atual: "<<Poupador[op0-1].getTaxaDeJuros()*100<<endl;
                break;
            case 4:
                cout<<"Informe o valor do saque: ";
                cin>>sq;
                if(Poupador[op0-1].saque(sq))cout<<"Saque realizado"<<endl;
                else cout<<"Falha no saque"<<endl;
                break;
            case 5:
                cout<<"Informe o valor do deposito: ";
                cin>>dp;
                if(Poupador[op0-1].deposito(dp))cout<<"Deposito realizado"<<endl;
                else cout<<"Falha no deposito"<<endl;
            case 6:
                cout<<"O rendimento mensal:"<<Poupador[op0-1].calcularRendaMensal()<<" BRL"<<endl;
                break;

            default:
                delete []Poupador;
                cout<<"Finalizando"<<endl;
                return 0;
        }
    }
    return 0;
}
