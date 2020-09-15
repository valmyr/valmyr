#include <iostream>

using namespace std;
class Retangulo{
    private:
        int x, y;
    public:

        int get_x();
        void set_x(int x);
        int get_y();
        void set_y(int y);
        int Area(int x, int y);
};
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
int Retangulo::Area(int x, int y){
    int area = x * y;
    return area;
}
int aux(){
    int numero;
    cin>>numero;
    return numero;
}
int main(){
    Retangulo r1;
    cout<<"Base: ";
    r1.set_x(aux());
    cout<<"Altura: ";
    r1.set_y(aux());
    cout<<r1.get_x()<<" x "<<r1.get_y()<<endl;
    cout<<"Area = "<<r1.Area(r1.get_x(),r1.get_y());

}
