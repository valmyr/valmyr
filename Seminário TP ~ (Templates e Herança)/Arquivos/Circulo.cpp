#include "./Circulo.h"
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