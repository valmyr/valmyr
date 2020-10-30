#include "./Ponto.h"
#ifndef _CIRCULO_H
#define _CIRCULO_H
template<class T>
class Circulo:public Ponto<T>{
    private:
    	T raio;
    public:
        Circulo(T,T,T);
        T diametroCirculo()const;
        T areaCirculo()const;
        void setRaio(T raio);
        void imprimir()const;
        ~Circulo();

};
#endif//_CIRCULO_H