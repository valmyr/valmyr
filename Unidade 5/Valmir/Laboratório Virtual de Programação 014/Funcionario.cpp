//
// Created by valmyr on 01/10/2020.
//
//
#include "./Funcionario.h"
//construtor com parâmetos
Funcionario::Funcionario() {
    //iniciando valores dos atributos
    this->nome = "0";
    this->dataAdmissao = "0";
    this->salario = 0;
    this->departamento = -1;
}
Funcionario::Funcionario(string nome, string dataAdmissao, int departamento, float salario) {
    //iniciando valores dos atributos
    this->nome = nome;
    this->dataAdmissao = dataAdmissao;
    this->salario = salario;
    this->departamento = departamento;
}
//                  sets Funcionários
//-------------------------------------------------------
void Funcionario::setSalario(float salario) {
    this->salario = salario;
}
void Funcionario::setDataAdmissao(string dataAdimssao) {
    this->dataAdmissao = dataAdmissao;
}
void Funcionario::setNome(string nome) {
    this->nome = nome;
}
//                  gets Funcionários
//-------------------------------------------------------
string Funcionario::getNome() const{
    return nome;
}
string Funcionario::getDataAdmissao() const{
    return dataAdmissao;
}
float Funcionario::getSalario() const{
    return salario;
}
void Funcionario::setDepartamento(int departamento) {
    this->departamento = departamento;
}
int Funcionario::getDepartamento() const{
    return departamento;
}
//---------------------------------------------------------------------/
