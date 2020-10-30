#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#include "./Ponto.cpp"
#include "./Circulo.cpp"
int main(){
    Circulo <int> intCirculo(2,3,20);
    Circulo <float> floatCirculo(3.1,3.2,1.2);
    Circulo <double> doubleCirculo(4.62234,2.927727,4.338833);
    cout.fill('-');
    cout<<setw(40)<<" "<<endl;
    cout<<"Circulo com numeros [int]"<<endl;
    intCirculo.imprimir();
    cout<<"Circulo com numeros [float]"<<endl;
    floatCirculo.imprimir();
    cout<<"Circulo com numeros [double]"<<endl;
    doubleCirculo.imprimir();
    return 0;
}
