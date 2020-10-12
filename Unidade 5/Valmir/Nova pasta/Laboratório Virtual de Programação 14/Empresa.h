//
// Created by valmyr on 01/10/2020.
//
/*
Importante: Compilador usado Clion, C++17.
Sistema Operacional: Windowns 10
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
Professor: Marcus Salerno
    Laboratório Virtual de Programação 014
        Faça um programa em C++ que contenha uma classe que representa um funcionário, registrando
seu nome, salário, data de admissão e departamento. Crie também uma classe que representa uma empresa,
registrando seu nome e CNPJ. Em todas as classes defina os atributos como privados e crie métodos públicos
para acessar e modificar os atributos.
        Finalmente, faça um programa que:
· Crie uma empresa com capacidade para armazenar funcionários. Não esqueça de solicitar no início quantos4
(a empresa terá uma lista de funcionários que deve ser criada dinamicamente);

· Adicione à empresa alguns funcionários,

· Dê aumento de 10% a todos os funcionários de um determinado departamento.

Obs.: Use o construtor default para as duas classes e o destrutor para limpeza de memória para a classe Empresa.
*/
#ifndef _EMPRESA_H
#define  _EMPRESA_H
//class Empresa
#include "./Funcionario.h"
class Empresa{
    //atributos
    //Instanciamento de um ponteiro do objeto funcionário
    Funcionario *F;
    //quantidade de pessoas que serão cadastrados
    int sizeF;
    //nome da empresa
    string nomeEmpresa;
    //CNPJ
    string CNPJ;
    //quantidade atual de funcionarios cadastrados
    int qFuncionario;
    //alocação dinâmica de memória na heap
    void alocarFuncionarios();
public:
    ///métodos

    //construtor
    Empresa();
    Empresa(Funcionario, string, string, int);
    //sets
    void setnomeEmpresa(string);
    void setCNPJ(string CNPJ);
    void setSize(int);

    //retorna a quantidada atual de pessoas cadastradas
    int getqFuncionarios();
    //retorna o nome da empresa
    string getnomeEmpresa()const;
    //retorna o CNPJ
    string getCNPJ() const;
    //adiciona um novo funcionaio
    void inserirFuncionario(Funcionario);
    //imprime a lista de funcionarios e o departamento e o salário
    void imprimirNomes() const;
    //aumenta o salário por departamento
    void aumentoSalarioPorderpartamento(int departamento, float porcentagem);
    //comparar duas strings
    bool compararString(string, string)const;
    //interação com o usuário
    int menu();
    void validacao_de_respostas(int & op);
    //destrutor
    ~Empresa();
};
#endif //_EMPRESA_H
