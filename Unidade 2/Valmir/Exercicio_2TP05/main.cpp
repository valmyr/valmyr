/*
Importante: Compilador usado Clion, C++17.
Sistema Operacional: Windows 10

Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
    Laboratório Virtual de Programação 05
Defina uma classe em C++ para representar uma pessoa. Uma pessoa, no nosso caso, possui os seguintes atributos:
·   Nome, Idade, Altura, Peso e Sexo.
A classe deve possuir métodos para modificar e acessar cada um dos atributos, um método para calcular o IMC
(Índice de Massa Corpórea), um método que forneça o nome da pessoa e um método que retorne a sua categoria de
acordo com o IMC. O IMC é obtido através da divisão do peso pela altura ao quadrado e é interpretado da seguinte
forma:

·   IMC <= 18,5:  Abaixo do peso normal

·   18,5 < IMC <= 25:  Peso Normal

·   25 < IMC <= 30: Acima do peso normal.

·   IMC > 30: Obesidade

            Escreva uma aplicação para utilizar os métodos descritos na classe.
*/
#include <iostream>
#include<iomanip>
#include<stdlib.h>
#include<cmath>
int main();//protótipo da função main()
using namespace std;
class Pessoa{
private:
    //Atributos da class
    string nome;
    int idade;
    double altura;
    double peso;
    string sexo;
public:
//Construtores da class
    Pessoa();
//sets
    void set_nome();
    void set_idade();
    void set_altura();
    void set_peso();
    void set_sexo();
//gets
    string get_nome();
    int get_idade();
    double get_altura();
    double get_peso();
    string get_sexo();
    //Cálculo do imc
    double IMC();
    //Categorias
    string categoria();

};
//---------------------------------------------------------------------------//
//Cálculo do imc
double Pessoa::IMC(){
    return peso / pow(altura,2);
}
//Categorias
string Pessoa::categoria() {
    //Usando o operador ternário para verificar a categoria de peso do usuário
    return (IMC()<=18.5)? "Abaixo do peso normal":(IMC()<= 25)?"Peso Normal":(IMC() <= 30)?"Acima do peso normal":"Obesidade";
}
//--------------------------------------------------------------------------//
//                          Get
//-------------------------------------------------------------------------//
string Pessoa::get_nome(){
    return nome;
}
int Pessoa::get_idade(){
    return idade;
}
double Pessoa::get_altura(){
    return altura;
}
double Pessoa::get_peso(){
    return peso;
}
string Pessoa::get_sexo(){
    return sexo;
}
//---------------------------------------------------------------------------//
//                          Set
//-------------------------------------------------------------------------//
void Pessoa::set_nome(){
    cin.ignore();
    getline(cin,nome);
}
void Pessoa::set_idade(){
    cin>>idade;
   //se a idade for menor que 1 o usuário deve digitar novamente
    if(idade < 1){
        cout<<"Idade Invalida "<<endl;
        cout<<"Tente novamente: ";
        set_idade();
    }
}
void Pessoa::set_altura() {
    cin>>altura;
    //se a altura for menor que 0 o usuário deve digitar novamente
    if(altura < 0){
        cout<<"Altura Invalida"<<endl;
        cout<<"Tente novamente:";
        set_altura();
    }
}
void Pessoa::set_peso() {
    cin>>peso;
    //se a peso for menor que 0 o usuário deve digitar novamente
    if(peso < 0) {
        cout<<"Peso Invalido"<<endl;
        cout<<"Tente novamente:";
        set_peso();
    }
}
void Pessoa::set_sexo() {
    cin>>sexo;
    //Converte a primeira letra da string sexo para maiúsculo
    sexo[0] = toupper(sexo[0]);
    if(sexo[0] != 'M' and sexo[0] != 'F'){
        //se for diferente de M ou F causa um erro e o usuário deve digita novamente
        cout<<"sexo Invalido"<<endl;
        cout<<"Tente novamente:";
        set_sexo();
    }
}
//------------------------------------------------------------------------//
//Construtor iniciando atributos
Pessoa::Pessoa(){
    nome = "\n\0";
    idade = 0;
    peso = 0;
    altura = 0;
    sexo = "\n\0";

}
int main() {
    //Intância do objeto pessoa
    Pessoa P1;
    //Variavel Opção
    int op;
    //O manipulador paramétrico cout.fill também pode ser usado para definir o caractere de preenchimento.
    cout.fill('-');
    //Coletando dados do usuário
    //Optei por colocar o cin>>  nos set pois é a melhor forma de validar os dados
    //Não altera a real função do set logo pode ser usado.
    cout<<"Nome: ";P1.set_nome();
    cout<<"Idade[Anos]: ";P1.set_idade();
    cout<<"Sexo[M/F]: ";P1.set_sexo();
    cout<<"Altura[m]: ";P1.set_altura();
    cout<<"Peso[Kg]: ";P1.set_peso();

    //Repetindo 50 vezes o caracter de preenchimento '-'
    cout<<setw(50)<<" "<<endl;
    //Mostrando nome
    cout<<endl<<"Nome: "<<P1.get_nome()<<" "<<endl;
    //Mostrando Idade
    cout<<"Idade[Anos]: "<<P1.get_idade()<<" Anos"<<endl;
    //Mostrando Sexo
    cout<<"Sexo[M/F]: "<<P1.get_sexo()<<endl;
    //Mostrando Altura
    cout<<"Altura[m]: "<<P1.get_altura()<<"m"<<endl;
    //Mostarndo Peso
    cout<<"Peso[Kg]: "<<P1.get_peso()<<"Kg"<<endl;
    //Analisando o imc do usuário
    /*
     *              ATENÇÃO
     *   O Exercício não solicitou a impressão do IMC
     *  cout<<"IMC:  "<<P1.IMC()<<endl;
     */
    cout<<"Analise de IMC: "<<P1.categoria()<<endl;
    //Repetindo 50 vezes o caracter de preenchimento '-'
    cout<<setw(50)<<" "<<endl;
    //Perguntando ao usuário se ele deseja sair do programa ou continuar
    cout<<"Deseja"<<endl<<" Sair[1]"<<endl<<" Continuar[2]"<<endl;
    cin>>op;
    //1 para sair 2 para continuar
    while(op < 1 or op > 2){
        //Caso seja maior que 2 e menor que 1 a opção informada pelo usuário e invalida
        cout<<"Opcao invalida";
        //É ele deve informa uma nova opção
        cout<<"Tente novamente:";
        cin>>op;
    }
    if(op == 2) {
        //Caso o usuário digite 2 reinicia o programa atravez da chamada da função principal
        main();
    }
    //Caso contrário o programa para de ser executado
    return 0;
}
