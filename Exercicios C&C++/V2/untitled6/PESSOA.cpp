//
// Created by valmyr on 01/06/2020.
//

#include"./PESSOA.h"
void pessoa :: pessoa(){
    Idade = 0;
    Sexo = "\0";
    Nome = "\0";
}
pessoa::pessoa(string Nome, string Sexo, int Idade){
    this -> Nome = Nome;
    this -> Sexo = Sexo;
    this -> Idade = Idade;
}
int Pessoa::Get_Idade(){
    return Idade;
}
void Pessoa::Set_Idade(int Idade){
    this -> Idade = Idade;
}
string Pessoa::Get_Sexo(){
    return Sexo;
}
string Pessoa::Set_Sexo(string Sexo){
    this -> Sexo = Sexo;
}
string Pessoa::Get_Nome(){
    return Nome;
}
void Pessoa::Set_Nome(string Nome){
    this -> Nome = Nome;
}