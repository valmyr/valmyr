#include<cmath>
#include <iostream>
using namespace std;
class Pessoa{
private:
    string Nome;
    int Idade;
    double Altura;
    double Peso;
    string Sexo;
public:
    Pessoa();
    Pessoa(string Nome, int Idade, double Altura, double Peso, string Sexo);
    void Set_Nome();
    void Set_Idade();
    void Set_Altura();
    void Set_Peso();
    void Set_Sexo();
    string Get_Nome();
    int Get_Idade();
    double Get_Altura();
    double Get_Peso();
    string Get_Sexo();
    double IMC();
    string Categoria();

};
//---------------------------------------------------------------------------//

double Pessoa::IMC(){
    return Peso * pow(Altura,2);
}
string Pessoa::Categoria() {
    return (IMC()<=18.5)? "Abaixo do peso normal":(IMC()>= 25)?"Peso Normal":(IMC() >= 30)?"Acima do peso normal":"Obesidade";
}
//--------------------------------------------------------------------------//
//                          Get
//-------------------------------------------------------------------------//
string Pessoa::Get_Nome(){
    return Nome;
}
int Pessoa::Get_Idade(){
    return Idade;
}
double Pessoa::Get_Altura(){
    return Altura;
}
double Pessoa::Get_Peso(){
    return Peso;
}
string Pessoa::Get_Sexo(){
    return Sexo;
}
//---------------------------------------------------------------------------//


//                          Set
//-------------------------------------------------------------------------//
void Pessoa::Set_Nome(){
    getline(cin,Nome);
}
void Pessoa::Set_Idade(){
    cin>>Idade;
    if(Idade < 1){
        cout<<"Idade Invalida\n";
        Set_Idade();
    }
}
void Pessoa::Set_Altura() {
    cin>>Altura;
    if(Altura < 0){
        cout<<"Altura Invalida\n";
        Set_Altura();
    }
}
void Pessoa::Set_Peso() {
    cin>>Peso;
    if(Peso < 0) {
        cout<<"Peso Invalido\n";
        Set_Peso();
    }
}
void Pessoa::Set_Sexo() {
    cin>>Sexo;
    Sexo[0] = toupper(Sexo[0]);
    if(Sexo[0] != 'M' and Sexo[0] != 'F'){
        cout<<"Sexo Invalido\n";
        Set_Sexo();
    }
}
//------------------------------------------------------------------------//




//Construtor iniciando atributos
Pessoa::Pessoa(){
    Nome = "Desconhecido";
    Idade = 0;
    Peso = 0;
    Altura = 0;
    Sexo = "Desconhecido";

}
//Construtor atribuido valores aos atributos da class pessoa
Pessoa::Pessoa(string Nome, int Idade, double Altura, double Peso, string Sexo){
    this->Nome = Nome;//Os atributos da class pessoa vai receber os valores das variaveis
    this->Idade = Idade;
    this->Sexo = Sexo;
    this->Altura = Altura;
    this->Peso = Peso;
}
int main() {
    Pessoa P1;
    cout<<"Nome: ";P1.Set_Nome();
    cout<<"Idade[Anos]: ";P1.Set_Idade();
    cout<<"Sexo[M/F]: ";P1.Set_Sexo();
    cout<<"Altura[m]: ";P1.Set_Altura();
    cout<<"Peso[Kg]: ";P1.Set_Peso();
    for(int i(0); i < 20; i++)cout<<"-=";
    cout<<endl;
    cout<<"Nome: "<<P1.Get_Nome()<<endl<<endl;
    cout<<"Idade[Anos]: "<<P1.Get_Idade()<<" Anos"<<endl;
    cout<<"Sexo[M/F]: "<<P1.Get_Sexo()<<endl;
    cout<<"Altura[m]: "<<P1.Get_Altura()<<"m"<<endl;
    cout<<"Peso[Kg]: "<<P1.Get_Peso()<<"Kg"<<endl;
    cout<<"Analise de IMC: "<<P1.Categoria()<<endl;
    for(int i(0); i < 20; i++)cout<<"-=";
    return 0;
}
