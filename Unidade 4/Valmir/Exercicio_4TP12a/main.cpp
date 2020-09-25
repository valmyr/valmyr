#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;
#include "Arcondicionado.cpp"
int main() {
    int ar, op;
    Arcondicionado *Ar = new Arcondicionado[2];
    Ar[0].setParametros(30,18,0,0,10);
    Ar[1].setParametros(25,18,0,0,10);
    while(true) {
        cout<<endl<<"Qual Arcondicionado voce quer controlar?"<<endl;
        cout<<"[1] Arcondiconado"<<endl;
        cout<<"[2] Arcondiconado"<<endl;
        cin>>ar;
        while(ar > 2 || ar < 1){
            cout<<"Opcao invalida: "<<endl;
            cin>>ar;
        }
        system("cls");
        op = Ar[ar-1].menu();
        cout<<"Arcondicionado: "<<ar<<endl;
        cout<<"Potencia: "<<Ar[ar-1].get_Potencia()<<endl;
        cout<<"Temperatura interna: "<<Ar[ar-1].ambienteTemp()<<endl;
        switch (op) {
            case 1:
                Ar[ar-1].diminuirTemp();
                break;
            case 2:
                Ar[ar-1].aumentaTemp();
                break;
            case 3:
                delete Ar;
                return 0;
            default:
                cout<<"Opcao invalida";
                return 0;
        }
    }
}
