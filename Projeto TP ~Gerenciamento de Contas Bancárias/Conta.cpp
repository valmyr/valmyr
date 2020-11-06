#include "./Conta.h"

Conta::Conta(const string & nomeDoUsuario,const long long & CPF,const int & idade, const float & saldo, const Endereco & enderecoDoUsuario){
  setNomeDoUsuario(nomeDoUsuario);
  setCPF(CPF);
  setIdade(idade);
  setSaldo(saldo);
  setEnderecoDoUsuario(enderecoDoUsuario);
}
void Conta::setNomeDoUsuario(const string & nomeDoUsuario){
  this->nomeDoUsuario = nomeDoUsuario;
}
void Conta::setCPF(const long long & CPF){
  this->CPF = CPF;
}
void Conta::setIdade(const int & idade){
  this->idade = idade;
}
void Conta::setEnderecoDoUsuario(const Endereco & enderecoDoUsuario){
  this->enderecoDoUsuario = enderecoDoUsuario;
}
void Conta::setSaldo(const float & saldo){
  this->saldo = saldo;
}
long long Conta::getCPF()const{
  return CPF;
}
int Conta::getIdade()const{
  return idade;
}
string Conta::getEnderecoDoUsuario()const{
  return enderecoDoUsuario.rua + "," + enderecoDoUsuario.CEP + "," +enderecoDoUsuario.cidade +","+enderecoDoUsuario.estado;
}
float Conta::getSaldo()const{
  return saldo;
}
bool Conta::sacar(float valorDoSaque){
  if(valorDoSaque > saldo){
    return false;
  }
  saldo -= valorDoSaque;
  return true;
}
bool Conta::depositar(float valorDoDeposito){
  if(valorDoDeposito < 0){
    return false;
  }
  saldo+=valorDoDeposito;
  return true;
}
void Conta::imprimir()const{
  cout<<"Nome: " + nomeDoUsuario<<endl;
  cout<<"CPF: "<<CPF<<endl;
  cout<<"Idade: "<<idade<<endl;
  cout<<"Endereco: "<<getEnderecoDoUsuario()<<endl;
  cout<<"Saldo: "<<saldo<<endl;
}
Conta::~Conta(){

}
