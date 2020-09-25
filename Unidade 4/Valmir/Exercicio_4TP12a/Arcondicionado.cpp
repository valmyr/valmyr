//
// Created by valmy on 24/09/2020.
//
#include "./Arcondicionado.h"
Arcondicionado::Arcondicionado(){
    sensorTemp = 0;
    maxTemp = 0;
    varPot= 0;
    varTemp = 0;
    maxPot = 0;
}
void Arcondicionado::setParametros(float sensorTemp, float maxTemp, float varPot,float varTemp,float maxPot){
    this->sensorTemp = sensorTemp;
    this->maxTemp = maxTemp;
    this->varPot= varPot;
    this->varTemp = varTemp;
    this->maxPot = maxPot;
}
float Arcondicionado::ambienteTemp(){
    return fabs(sensorTemp - varTemp);
}
void Arcondicionado::aumentaTemp(){
    if(varPot <= 0){
        cout<<"Ops, Arcondicionado em espera."<<endl;
        return;
    }
    varPot--;
    varTemp-=float(maxTemp)/maxPot;
}
void Arcondicionado::diminuirTemp(){
    if(varPot >= maxPot){
        cout<<"Arcondicionado no maximo"<<endl;
        return;
    }
    varPot++;
    varTemp+=float(maxTemp/maxPot);
}
float Arcondicionado::get_Potencia() {
    return maxPot;
}
int Arcondicionado::menu(){
    int op;
    cout.fill('-');
    cout<<setw(40)<<" "<<endl;
    cout.fill( ' ');
    cout<<setw(20)<<"DESEJA"<<setw(20)<<" "<<endl;
    cout.fill('-');
    cout<<setw(40)<<" "<<endl;
    (varPot < maxPot)? cout<<"[1] Diminuir temperatura"<<endl: cout<<" "<<endl;
    (varPot >= 0)?cout<<"[2] Aumentar temperatura"<<endl:cout<<" "<<endl;
    cout<<"[3] Desligar"<<endl;
    cout<<setw(40)<<" "<<endl;
    cin>>op;
    return op;
}
Arcondicionado::~Arcondicionado() {
    delete this;
}
