//
// Created by valmy on 01/10/2020.
//
#ifndef _LISTA_H
#define _LISTA_H
class Lista{
    string *listaNomes;
    static int dNomes;
    FILE *fp;
    FILE *fpp;
    FILE *rel;
    int size;
public:
    Lista();
    Lista(int);
    void setSize(int);
    static int getdNomes();
    void alocarLista(void);
    void ordenarNomes();
    bool inserirNome(string );
    void imprimirLista()  ;
    void tratamentoNomes();
    int menu();
    void validarRespostas(int&);
    void salvar(FILE *, string);
    void reload();
    ~Lista();
};
#endif
