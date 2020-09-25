//
// Created by valmyr on 24/09/2020.
//
#include "Relogio.h"
void Relogio::set_hora(int hora){
    this->hora = hora;
}
void Relogio::set_minuto(int minuto){
    this->minuto = minuto;
}
void Relogio::set_segundo(int segundo){
    this->segundo = segundo;
}
int Relogio::get_hora(){
    return hora;
}
int Relogio::get_segundo(){
    return segundo;
}
int Relogio::get_minuto(){
    return minuto;
}
Relogio::Relogio(){
    hora = 0;
    minuto = 0;
    segundo = 0;
}
void Relogio::setHora(int hora, int minuto, int segundo) {
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}
Relogio Relogio::getHora(int &hora, int &minuto, int &segundo) {
    hora = this->hora;
    minuto = this->minuto;
    segundo = this->segundo;
}
void Relogio::atualizar() {
    if(segundo < 59){
        segundo++;
    }else{
        segundo =0;
        minuto++;
        if(minuto > 59){
            minuto = 0;
            hora++;
            if(hora > 23){
                hora = 0;
            }
        }
    }
}
