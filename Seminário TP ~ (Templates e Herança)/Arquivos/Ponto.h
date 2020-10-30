#ifndef _PONTO_H
#define _PONTO_H
template <class T>
class Ponto{
    T x;
    T y;
    public:
        Ponto(T = 0,T = 0);
        void setX(T);
        void setY(T);
        T getX()const;
        T getY()const;
        void imprimir()const;
        ~Ponto();
};
#endif//_PONTO_H