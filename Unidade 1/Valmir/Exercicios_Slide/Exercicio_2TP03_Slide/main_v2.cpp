#include <iostream>
#include<stdlib.h>//
using namespace std;
///Para este programa vou considerar que todos os usuarios já estão cadastrados.
struct Banco{
    private:
        string Nome;
        float Saldo;
        long int Conta;
        int Agencia;
        long int CPF;
        long int RG;
    public:
        Banco::Banco(string Nome,float Saldo,long int Conta,int Agencia,long int CPF,long int RG);
        string get_Nome();
        void set_Nome(string Nome);
        float get_Saldo();
        void set_Saldo(float Saldo);
        long int get_Conta();
        void set_Conta(long int Conta);
        int get_Agencia();
        void set_Agencia(int Agencia);
        long int get_CPF();
        void set_CPF(int CPF);
        bool Possui_Conta();
};
string Banco::get_Nome(){
    return Nome;
}
void Banco::set_Nome(string Nome){
    this->Nome = Nome;
}
float Banco::get_Saldo(){
    return Saldo;
}
void Banco::set_Saldo(float Saldo){
    this->Saldo = Saldo;
}
long int Banco::get_Conta(){
    return Conta;
}
void Banco::set_Conta(long int Conta){
    this->Conta = Conta;
}
int Banco::get_Agencia(){
    return Agencia;
}
void Banco::set_Agencia(int Agencia){
    this->Agencia = Agencia;
}
long int Banco::get_CPF(){
    return CPF;
}
bool Banco::Possui_Conta(){
    char op;
    do{
        cout<<"Possui conta cadastrada? [S/N] >> ";cin>>op;
        op = toupper(op);
        if( 'N' == op or op == 'S')break;
    }while(true);
    if(op == 'S')return 1;
    return 0;
}
int main(){
    Banco *Usuarios = (Banco*)malloc(sizeof(Banco)*20); Banco auxiliar;
    bool op = auxiliar.Possui_Conta();
    if(op){
        cout<<"Informe seu Nome: ";
    }
    // teste
}
