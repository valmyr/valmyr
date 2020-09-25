//
// Created by valmy on 24/09/2020.
//
#ifndef _RELOGIO_H
#define _RELOGIO_H
class Relogio{
private:
    int hora;
    int minuto;
    int segundo;
public:
    Relogio();

    void setHora(int, int, int);
    Relogio getHora(int &, int &,int &);

    void set_hora(int );
    void set_minuto(int );
    void set_segundo(int );

    int get_hora();
    int get_minuto();
    int get_segundo();

    void atualizar();
};
#endif
