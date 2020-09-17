#include <iostream>
#include <math.h>
using namespace std;
class vertices{
private:
    int x ,y;
public:
    bool Verificar_Coordenada();
    float Comprimento(vertices t);
    float largura(vertices t);

};
class Retangulo{
private:

public:
    Retangulo();
    Retangulo(int x, int y);
    Retangulo(int *x, int *y);
    int get_x();
    void set_x(int x);
    int get_y();
    void set_y(int y);
    float perimetro(Retangulo t);
    float area(Retangulo t);
    bool Verificar_Retangulo(Retangulo t);
};
float Retangulo::perimetro(Retangulo t){
    return 2*(this)->Comprimento(t) + 2*(this)->largura(t);
}
float Retangulo::area(Retangulo t){
    return (this)->Comprimento(t) * (this)->largura(t);
}
float Retangulo::Comprimento(Retangulo t){
    return fabs(x - t.x);
}
float Retangulo::largura(Retangulo t){
    return fabs(y - t.y);
}
bool Retangulo::Verificar_Retangulo(Retangulo t){

    float hip_temp = sqrt( pow((this)->Comprimento(t),2)+pow((this)->largura(t),2));//hipotenusa
    float angulos_complementares = (asin((this)->largura(t)/hip_temp)+asin((this)->Comprimento(t)/hip_temp))*180/M_PI;
    if(angulos_complementares == 90)
        return 1;
    return 0;
}
Retangulo::Retangulo(int *x, int *y){
    *x = 0;
    *y = 0;
}
int Retangulo::get_x(){
    return x;
}
void Retangulo::set_x(int x){
    this->x = x;
}
int Retangulo::get_y(){
    return y;
}
void Retangulo::set_y(int y){
    this->y = y;
}
Retangulo::Retangulo() {
    x = y = 0;
}
Retangulo::Retangulo(int x, int y) {
    this -> x = x;
    this -> y = y;
    if((this)->Verificar_Coordenada()){
        cout<<" Coodenadas invalidas, atribuido padrao nos atributos" ;
    }

}
bool Retangulo::Verificar_Coordenada() {
    bool op = 0;
    if (x < 0 || x > 15) {
        op = 1;
        Retangulo(&x,&y);
    } else if(y < 0 || y > 15){
        op =1;
        Retangulo(&x, &y);
    }
    return op;
}
int main() {
    Retangulo a(0,0), b(4,3);
    a.Verificar_Retangulo(b);
    if(1){

    }else{

    }

}
