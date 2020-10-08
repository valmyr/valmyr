#include <iostream>
#include<iomanip>
using namespace std;
#include "./Lista.cpp"
int main() {
    Lista lN;
    string Nome;
    int size =10, i = 0,aa;
    cout<<"Informe a tamanho da lista: ";cin>>size;
    cout<<"[1]Banco de dados"<<endl;
    cin>>aa;
    lN.setSize(size);
    if(aa==1){
        lN.reload();
        lN.imprimirLista();
        i = Lista::getdNomes();
    }
    while(true) {
        int  op = lN.menu();
        switch(op){
            case 1:
                cout.fill('0');
                if(i <= size){
                    cin.ignore();
                    cout<<"Nome[" <<setw(2)<< i + 1 << "]: ";
                    getline(cin,Nome);
                    i++;
                    lN.inserirNome(Nome);
                }
                break;
            case 2:
                lN.imprimirLista();
                break;
            case 3:
                lN.ordenarNomes();
                cout<<"Lista Ordenada"<<endl;
                break;
            case 4:
                cout<<"Total: "<<Lista::getdNomes()<<endl;
                break;
            case 5:
                system("cls");

                break;
            case 6:
                return 0;
                break;
        }
    }
}
