//
// Created by valmyr on 01/10/2020.
/*
Importante: Compilador usado Clion, C++17.
Sistema Operacional: Windowns 10
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
Professor: Marcus Salerno
    Laboratório Virtual de Programação 015
        Crie uma classe que possui como atributos uma lista de nomes e uma variável que
indica o seu tamanho máximo. Crie um método para essa classe que ordena os nomes em ordem
alfabética, um método que insere um nome na lista e um método que imprime essa lista. Não 
esqueça de criar a lista dinamicamente no construtor, a partir do valor do tamanho máximo 
passado por parâmetro. Não esqueça também de liberar no Destrutor o espaço de memória utilizado.
        Na main, crie uma aplicação para inserir alguns nomes na lista e imprimir essa lista ordenada.
*/
#ifndef _LISTA_H
#define _LISTA_H
class Lista{
    //ponteiro do tipo string que receberá lista de nomes
    string *listaNomes;
    //atributo que contará a quantidade atual de nomes na lista
    int quantidadeAtualDeNomes;
    //Atributo que receberá o tamanho máximo da lista
    int sizeL;
public:
    //construtor default
    Lista();
    //construtor com paramêtro
    Lista(int);
    //set tamanho máximo
    void setsizeL(int);
    //get quantidade atual da lista
    int getquantidadeAtualDeNomes();
    //alocando dinâmicamente a lista de nomes na memória heap
    void alocarLista(void);
    //ordena em ordem alfabética os nomes da lista
    void ordenarNomes();
    //adiciona um nome na lista
    bool inserirNome(string);
    //mostra na tela do usuário a lista
    void imprimirLista() const ;
    //converte a primeira letra do nome para maiúscula
    void tratamentoNomes();
    //interação com o usuário
    int menu();
    //valida a resposta do usuário
    void validarRespostas(int&);
    //destrutor
    ~Lista();
};
#endif
