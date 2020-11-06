#include"./Conta.h"
class ContaPoupanca:public Conta{
    public:
      ContaPoupanca(const string & = "0",const long long & = 0,const int & = 0,const float & = 0,const Endereco & =  {"0","0","0","0"});
      bool cadastroUsuario();
       bool salvarDados();
};
bool ContaPoupanca::salvarDados(){
   return true;
}
bool ContaPoupanca:: cadastroUsuario(){
  return true;
}
ContaPoupanca::ContaPoupanca(const string & nomeDoUsuario,const long long & CPF,const int & idade, const float & saldo, const Endereco & EnderecoDoUsuario)
      :Conta(nomeDoUsuario,CPF,idade,saldo,EnderecoDoUsuario){
}
