#include <iostream>
#include <iomanip>
using namespace std;
#include "./ContaDePoupanca.cpp"
int main() {
    //instacianmento de dois objetos do tipo ContaDePoupanca
    ContaDePoupanca *Poupador = (ContaDePoupanca *)new ContaDePoupanca[2];
    //variáveis auxiliares
    int op0, op1;
    //precisão de casas decimais
    cout.precision(3);
    //p = saldo, juros em %, sq = saque, dp = deposito
    float p, juros, sq, dp;
    cout<<"Saldo[BRL] do poupador 1: ";cin>>p;
    Poupador[0].setSaldoDaPoupanca(p);
    cout<<"Saldo[BRL] do poupador 2: ";cin>>p;
    Poupador[1].setSaldoDaPoupanca(p);
    //loop
    while(true){
        //
        cout<<"[1] Poupador"<<endl;
        cout<<"[2] Poupador"<<endl;
        cin >> op0;
        system("cls");
        //validamento da variavel op0
        while(op0 > 2 or op0 < 1){
            cout<<"Opcao invalida: ";
            cin>> op0;
        }
        //interação com o usuário menu
        op1=Poupador[op0-1].menu();
        switch(op1){
            case 1:
                //caso o usuário informe 1 ele deseja modificar a taxa de juros
                cout<<"Informe a porcentagem do aumento: ";
                cin>>juros;
                //modificando taxa de juros
                ContaDePoupanca::modificarTaxaDeJuros(juros);
                //atualizando saldo com a nova taxa de juros
                Poupador[op0-1].atualizarSaldo();
                break;
            case 2:
                //caso o usuário informe 2 ele deseja ver o saldo atual
                cout<<"Saldo atual "<<Poupador[op0-1].getSaldoDaPoupanca()<<"BRL"<<endl;
                break;
            case 3:
                //caso o usuário informe 3 ele deseja ver a taxa de juros atual
                cout<<"Taxa de juros atual: "<<Poupador[op0-1].getTaxaDeJuros()*100<<" %"<<endl;
                break;
            case 4:
                //caso o usuário informe 4 ele deseja sacar
                cout<<"Informe o valor do saque: ";
                cin>>sq;
                //verificando se o saque foi aceito
                if(Poupador[op0-1].saque(sq))cout<<"Saque realizado"<<endl;
                else cout<<"Falha no saque"<<endl;
                break;
            case 5:
                //caso o usuário informe 5 ele deseja depositar
                cout<<"Informe o valor do deposito: ";
                cin>>dp;
                //verificando se o deposito foi aceito
                if(Poupador[op0-1].deposito(dp))cout<<"Deposito realizado"<<endl;
                else cout<<"Falha no deposito"<<endl;
                break;
            case 6:
                //caso o usuário informe 6 ele deseja ver o rendimento mensal
                cout<<"O rendimento mensal:"<<Poupador[op0-1].calcularRendaMensal()<<" BRL"<<endl;
                break;

            default:
                //desalocando memória heap
                delete []Poupador;
                cout<<"Finalizando"<<endl;
                cout<<"Desalocando"<<endl;
                return 0;

        }
    }
}
