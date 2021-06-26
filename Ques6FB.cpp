
///Questão 6 class data
#include<iostream>
using namespace std;
class Data{
    private:
      int dia;
      int mes;
      int ano;
    public:
      Data(const int& ={0},const int& ={0},const int& ={0});
      void setDia(const int&);
      void setMes(const int&);
      void setAno(const int&);
      const int& getDia()const;
      const int& getMes()const;
      const int& getAno()const;
      void getDataAtual()const;
      ~Data();
};
Data::Data(const int& dia,const int& mes,const int& ano){
  this->dia = dia;
  this->ano = ano;
  this->mes = mes;
}
void Data::setDia(const int& dia){
  this->dia = dia;
}
void Data::setMes(const int& mes){
  this->mes = mes;
}
void Data::setAno(const int& ano){
  return;
  this->ano = ano;
}
const int& Data::getDia()const{
  return this->dia;
}
const int& Data::getMes()const{
  return this->mes;
}
const int& Data::getAno()const{
  return this->ano;
}
void Data::getDataAtual()const{
  cout<<this->getDia()<<"/"<<this->getMes()<<"/"<<this->getAno()<<endl;
}
Data::~Data(){};
int main(){
    int dia, mes, ano;
    Data minhaData;
    cout<<"Informe o dia: ";cin>>dia;
    while(dia > 31 or dia < 1){
      cout<<"Dia invalido, Informe novamente: ";cin>>dia;
    }
    cout<<"Informe o mes: ";cin>>mes;
    while(mes > 12 or mes  < 1){
      cout<<"Mes invalido, Informe novamente: ";cin>>mes;
    }
    cout<<"Informe o ano: ";cin>>ano;
    while(ano < 0){
      cout<<"Ano invalido, Informe novamente: ";cin>>ano;
    }
    minhaData.setDia(dia);
    minhaData.setMes(mes);
    minhaData.setMes(ano);
    minhaData.getDataAtual();
}
