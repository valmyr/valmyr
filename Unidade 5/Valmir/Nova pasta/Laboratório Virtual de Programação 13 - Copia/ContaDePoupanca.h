//
// Created by valmyR on 02/10/2020.
//

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
    //atualiza o saldo
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
