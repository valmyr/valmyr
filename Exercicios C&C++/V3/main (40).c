#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
struct Aluno{
  string Nome;
  float *Nota;
  float Media = 0;
  public:
    void get_Nome();
    string set_Nome();

    void get_Notas();
    float *set_Notas();


    float set_Media();

};
void Aluno::get_Nome(){
  string Nome;
  fflush(stdin);
  cin>>(Nome);//problema ao utilizar o getline para pegar o nome e o sonbrenome o codigo bug e eu não sei o porque
  this -> Nome = Nome;
}
string Aluno::set_Nome(){
  return Nome;
}
void Aluno::get_Notas(){
  float *Nota = (float*)malloc(sizeof(float)*4);
  for(int i = 0; i < 4; i++){
    cout<<"Nota ["<<i+1<<"] = ";cin>>Nota[i];
  }
  this -> Nota = Nota;
}
float *Aluno::set_Notas(){
  for(int i = 0; i < 4; i++){
    cout<<"\tNota ["<<i+1<<"] = "<<Nota[i]<<endl;
  }
  return Nota;
}
float Aluno::set_Media(){

  for(int i  = 0; i < 4; i++){
    Media += Nota[i];
  }
  return Media/4;
}

int main() {
  struct Aluno *Dados;
  Dados = (Aluno *)malloc(sizeof(struct Aluno)*2);
  for(int  i = 0; i < 2; i++){
    cout<<"Informe o nome["<<i+1<<"] >>";
    Dados[i].get_Nome();
    cout<<"Informe as Notas["<<i+1<<"]\n";
    Dados[i].get_Notas();
  }
  cout<<"\n";
  for(int i = 0; i < 2; i++){
      cout<<"Nome ["<<i+1<<"]: "<<Dados[i].set_Nome()<<endl;
      cout<<"Notas["<<i+1<<"]:\n";
      Dados[i].set_Notas();
      cout<<"\t\tMedia:"<<Dados[i].set_Media()<<endl;
  }
  

}