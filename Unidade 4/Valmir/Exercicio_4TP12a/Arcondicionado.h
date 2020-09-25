//
// Created by valmy on 24/09/2020.
//

#ifndef _ARCONDICIONADO_H
#define _ARCONDICIONADO_H
class Arcondicionado{
private:
    float sensorTemp;
    float maxTemp;
    float varPot;
    float varTemp;
    float maxPot;
public:
    Arcondicionado();
    void setParametros(float, float, float,float, float );
    float get_Potencia();
    float ambienteTemp();
    void aumentaTemp();
    ~Arcondicionado();
    void diminuirTemp();
    int menu();
};
#endif //UNTITLED41_ARCONDICIONADO_H
