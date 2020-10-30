#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
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
};
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
class Circulo:public Ponto<T>{
    T raio;
    public:
        Circulo(T,T,T);
        T diametroCirculo()const;
        T areaCirculo()const;
        void setRaio(T raio);
        void imprimir()const;
        ~Circulo();

};
template<class T>
Circulo<T>::Circulo(T x, T y, T raio):Ponto<T>(x,y){
    setRaio(raio);
}
template<class T>
void Circulo<T>::setRaio(T raio){
    this->raio = raio;
}
template<class T>
T Circulo<T>::diametroCirculo()const{
    return 2*raio;
}
template<class T>
T Circulo<T>::areaCirculo()const{
    return M_PI *pow(raio,2);
}
template<class T>
void Circulo<T>::imprimir()const{
    cout.fill('-');
    cout<<setw(40)<<" "<<endl;
    Ponto<T>::imprimir();
    cout<<"Raio: "<<raio<<endl;
    cout<<"Area: "<<Circulo<T>::areaCirculo()<<endl;
    cout<<"Diametro: "<<Circulo<T>::diametroCirculo()<<endl;
    cout<<setw(40)<<" "<<endl;
}
template<class T>
Circulo<T>::~Circulo(){

}
int main(){
    Circulo <int> intCirculo(2,3,20);
    Circulo <float> floatCirculo(3.1,3.2,1.2);
    Circulo <double> doubleCirculo(4.62234,2.927727,4.338833);
    cout<<"Circulo com numeros [int]"<<endl;
    intCirculo.imprimir();
    cout<<"Circulo com numeros [float]"<<endl;
    floatCirculo.imprimir();
    cout<<"Circulo com numeros [double]"<<endl;
    doubleCirculo.imprimir();
    return 0;
}
