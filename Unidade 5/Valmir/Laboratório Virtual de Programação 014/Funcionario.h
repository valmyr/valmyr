//
// Created by valmyr on 01/10/2020.
//
//
#ifndef _FUNCIONARIO_H
#define _FUNCIONARIO_H
//class funcionário
class Funcionario{
    //atributos
    string nome;
    string dataAdmissao;
    int departamento;
    float salario;
public:
    //métodos
    //construtores
    Funcionario(string, string, int,float);
    Funcionario();
    //sets
    void setNome(string);
    void setDataAdmissao(string );
    void setSalario(float);
    void setDepartamento(int);
    //gets
    string getNome() const;
    string getDataAdmissao() const;
    float getSalario() const;
    int getDepartamento() const;

};
#endif //_FUNCIONARIO_H
