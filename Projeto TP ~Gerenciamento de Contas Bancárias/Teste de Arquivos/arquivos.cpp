#include<iostream>
#include<fstream>
#include <vector>
#include<cstdlib>
using namespace std;
class Pessoa{
    string nome;
    int idade;
    int dSize;
    vector<Pessoa> listaDePessoas;
  public:
    Pessoa(string = "0", int = 0);
    void setNome(string);
    void setIdade(int);
    void addPessoa(Pessoa &);
    void imprimir();
    bool salvaLista();
};
void Pessoa::setNome(string nome){
  this->nome=nome;
}
void Pessoa::setIdade(int idade){
  this->idade = idade;
}
bool Pessoa::salvaLista(){
  fstream arquivos;
  arquivos.open("./Dados.txt",ios::out|ios::binary);
  if(arquivos.is_open())
    cout<<"Arquivo aberto..."<<endl;
  for(int i = 0; i < listaDePessoas.size(); i++){
      arquivos<<listaDePessoas[i].nome<<endl;
      arquivos<<listaDePessoas[i].idade<<endl;
  }
  arquivos.close();
  if(not(arquivos.is_open())){
    cout<<"...Arquvo fechado"<<endl;
  }
  return true;
}
void Pessoa::imprimir(){
  for(int i = 0; i < listaDePessoas.size(); i++){
    cout<<"Nome: "<<listaDePessoas[i].nome<<endl;
    cout<<"Idade: "<<listaDePessoas[i].idade<<endl;
  }
}
void Pessoa::addPessoa(Pessoa & auxPessoa){
    listaDePessoas.push_back(auxPessoa);
    dSize+=1;
}
Pessoa::Pessoa(string nome, int idade){
    this->nome = nome;
    this->idade = idade;
}
int main(){
  Pessoa lista;
  Pessoa pAux;
  string nome; int t, idade;
  cout<<"Informe a quantidade de pessoas da lista:";cin>>t;
  cin.ignore();
  for(int i = 0; i < t; i++){
    cout<<"["<<i+1<<"]"<<"Nome: "; getline(cin, nome);
    pAux.setNome(nome);
    cout<<"["<<i+1<<"]"<<"Idade: "; cin>>idade;
    //cin.ignore();
    pAux.setIdade(idade);
    lista.addPessoa(pAux);
    cin.ignore();
  }
  lista.salvaLista();
  lista.imprimir();
  system("notepad Dados.txt");
}///
