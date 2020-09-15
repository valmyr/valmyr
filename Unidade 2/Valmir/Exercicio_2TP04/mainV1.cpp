#include <iostream>
using namespace std;
#include<cmath>
int main();
class Retangulo{
    private:
        int x1;int y1;
        int x2;int y2;
    public:
        bool verificar_Coordenadas();
        bool verificar_Retangulo();
        bool verificar_Quadrado(); 
        
        void set_x1();
        void set_y1();
        void set_x2();
        void set_y2();
        
        float comprimento();
        float largura();
        float area();
        float perimetro();
};

void Retangulo::set_x1(){
    cout<<"X1: "; cin>>x1;
}
void Retangulo::set_y1(){
    cout<<"Y1: "; cin>>y1;
}
void Retangulo::set_x2(){
    cout<<"X2: "; cin>>x2;
}
void Retangulo::set_y2(){
    cout<<"Y1: "; cin>>y2;
}
float Retangulo::perimetro() {
    return 2*(largura()+comprimento());
}
float Retangulo::area() {
    return largura()* comprimento();
}
float Retangulo::comprimento() {
    if(fabs(y1-y2) > fabs(x1-x2))
        return fabs(y1-y2);
    return fabs(x1 - x2);
}
float Retangulo::largura() {
    if(fabs(y1 - y2) > fabs(x1 - x2))
        return fabs(x1-x2);
    return fabs(y1 - y2);
}
bool Retangulo::verificar_Retangulo() {
    float Hipot_temp = sqrt(pow(comprimento(), 2) + pow(largura(), 2));
    float angulos_complementares = (asin(comprimento() / Hipot_temp) + asin(largura() / Hipot_temp)) * 180 / M_PI;
    angulos_complementares = (int)angulos_complementares;
    if (angulos_complementares == 90.00 and not(verificar_Quadrado())){
        return true;
    }
        return false;
}
bool Retangulo::verificar_Quadrado() {
    if(comprimento() == largura())
        return true;
    return false;
}
bool Retangulo::verificar_Coordenadas() {
    bool op = 0;
    if(x1 < 0 || x1 >= 15)op = 1;
    else if(x2 < 0 || x2 >= 15)op = 1;
    else if(y1 < 0 || y1 >= 15)op = 1;
    else if(y2 < 0 || y2 >= 15)op = 1;
    return op;
}
void opcoes(){
    int op;
    cout<<"Tentar novamente[1]\nSair[2]\n";
    while(op< 1 || op > 2){
        cout<<"Opcao invalida\n";
        cout<<"Tente novamente: ";
        cin>>op;
    }
    if(op == 1)main();
        return ;
}
int main() {
    Retangulo *r1 = new Retangulo; 
    r1->set_x1();
    r1->set_y1();
    r1->set_x2();
    r1->set_y2();
    if(r1->verificar_Coordenadas()){
        cout<<"Coordenadas invalidas\n";
        opcoes();
    }else {
        if(r1->verificar_Retangulo()||r1->verificar_Quadrado()){
            string str = (r1->verificar_Retangulo()) ? "Sim" : "Nao";
            cout << "E um retangulo? " << str << endl;
            str = (r1->verificar_Quadrado()) ? "Sim" : "Nao";
            cout << "E um Quadrado? " << str << endl;
            cout << "Comprimento: " << r1->comprimento() << endl;
            cout << "Largura: " << r1->largura() << endl;
            cout << "Area: " << r1->area() << endl;
            cout << "Perimetro: " << r1->perimetro() << endl;
            cout<<"Fim\n";
            opcoes();
        }else{
            cout<<"Nao e um quadrado nem um retangulo\n";
            opcoes();
        }
    }
}