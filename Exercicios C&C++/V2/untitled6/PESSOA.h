//
// Created by valmy on 01/06/2020.
//

#ifndef UNTITLED6_PESSOA_H
#define UNTITLED6_PESSOA_H

#endif //UNTITLED6_PESSOA_H
#include <iostream>
using namespace std;
#ifndef PESSOA_H
#define PESSOA_H
#endif
class Pessoa{
  int Idade;
  string Sexo;
  string Nome;
  public:
    int Get_Idade();
    void Set_Idade(int Idade);
    string Get_Sexo();
    void Set_Sexo(string Sexo);
    string Get_Nome();
    void Set_Nome(string Nome);
    void pessoa();
    void pessoa(string Nome, int Idade, string Sexo);
};
