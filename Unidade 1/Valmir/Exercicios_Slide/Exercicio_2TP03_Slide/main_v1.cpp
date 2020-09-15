#include <iostream>

using namespace std;
struct Banco{
    string Nome;
    int Agencia;
    int Conta;
    float Saldo;
};
int main(){
    Banco *Dados;
    Dados = (Banco)malloc(sizeof(Banco) * 20);
    char a;
    cout<<"Possui conta?";
    do{
        cin>>a;
        a = toupper(a);
    }while(a != 'S' || a != 's');

}
