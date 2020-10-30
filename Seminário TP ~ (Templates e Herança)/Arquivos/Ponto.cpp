#include "./Ponto.h"
template <class T>
Ponto<T>::Ponto(T x,T y){
    this->x = x;
    this->y = y;
}
template <class T>
void Ponto<T>::setX(T x){
    this->x = x;
}
template <class T>
void Ponto<T>::setY(T y){
    this->y = y;
}
template <class T>
T Ponto<T>::getX()const{
    return x;
}
template <class T>
T Ponto<T>::getY()const{
    return y;
}
template<class T>
void Ponto<T>::imprimir()const{
    cout<<"COORDENADAS: "<<endl;
    cout<<"X: "<<getX()<<endl;
    cout<<"Y: "<<getY()<<endl;
}
template<class T>
Ponto<T>::~Ponto(){

}