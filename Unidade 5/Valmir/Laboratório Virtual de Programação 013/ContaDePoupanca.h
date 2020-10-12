//
// Created by valmyR on 02/10/2020.
//
/**
Importante: Compilador usado Clion, C++17.
Sistema Operacional: Windowns 10
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
Professor: Marcus Salerno

Crie uma classe em C++ chamada ContaDePoupanca. Use um membro de dados static para conter a taxaDeJurosAnual para 
cada um dos poupadores. Cada membro da classe contém um membro de dados private saldoDaPoupanca indicando a quantia
que o poupador atualmente tem em depósito. Forneça um método membro calculeRendimentoMensal que calcule o rendimento
mensal multiplicando o saldo pela taxaDeJurosAnual dividida por 12; este rendimento deve ser somado ao saldoDaPoupanca.
Forneça uma função membro static modifiqueTaxaDeJuros que inicializa a variável static taxaDeJurosAnual com um novo valor.
Escreva um programa de teste que instancia dois objetos diferentes contaDePoupanca, poupador1 e poupador2, com saldos de
R$ 2000,00 e R$ 3000,00, respectivamente. Inicialize taxaDeJurosAnual com 6%, então calcule o rendimento mensal e imprima
os novos saldos para cada um dos poupadores. Inicialize então a taxaDeJurosAnual com 8%, calcule o rendimento do próximo
mês e imprima o novo saldo para cada um dos poupadores.
*/
#ifndef UNTITLED48_CONTADEPOUPACA_H
#define UNTITLED48_CONTADEPOUPACA_H
class ContaDePoupanca{
private:
    //atributos privados
    static float taxaDeJurosAnual;
    float saldoDaPoupanca;
public:
    //atributos publicos
    //construtor
    ContaDePoupanca(float = 0);
    //destrutor
    ~ContaDePoupanca();
    // cálculo de renda mensal
    float calcularRendaMensal();
    //set do valor da poupança
    void setSaldoDaPoupanca(float = 0);
    //get do valor da poupança
    float getSaldoDaPoupanca(void) const;
    //retornar a taxa de juros atual
    static float getTaxaDeJuros();
    //modifica a taxa de juros
    static void modificarTaxaDeJuros(float= 0);
    //atualizar saldo
    void atualizarSaldo();
    //função para um realizar o saque
    bool saque(float = 0);
    //função para um realizar o deposito
    bool deposito(float = 0);
    //interação com o usuário menu
    int menu();
    //validamento de opções do menu
    void validarResposta(int &op);
};
#endif //UNTITLED48_CONTADEPOUPACA_H
