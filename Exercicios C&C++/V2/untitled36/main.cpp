//Esboço
#include <iostream>
using namespace std;
class Televisao{
private:
    int volume;
    int canal;
public:
    Televisao();
    Televisao(int, int);
    void set_volume(int );
    void set_canal(int );
    int get_volume();
    int get_canal();
    void aumenta_volume();
    void diminuir_volume();
    void trocar_de_canal(int canal);
    void trocar_de_canal();
};
Televisao::Televisao() {
    set_canal(0);
    set_volume(0);
}
Televisao::Televisao(int volume, int canal) {
    set_canal(canal);
    set_volume(volume);
}
void Televisao::set_canal(int canal) {
    this->canal = canal;
}
void Televisao::set_volume(int volume) {
    this->volume = volume;
}
int Televisao::get_canal(){
    return canal;
}
int Televisao::get_volume() {
    return volume;
}
void Televisao::aumenta_volume() {
    set_volume(++volume);
}
void Televisao::diminuir_volume() {
    set_volume(--volume);
}
void Televisao::trocar_de_canal() {
    set_canal(++canal);
}
void Televisao::trocar_de_canal(int canal) {
    set_canal(canal);
}
int main() {
    Televisao t1(100,2);
    cout<<"CANAL: "<<t1.get_canal()<<endl;
    cout<<"VOLUME: "<<t1.get_volume()<<endl;

    t1.diminuir_volume();
    t1.trocar_de_canal(20);
    cout<<"CANAL: "<<t1.get_canal()<<endl;
    cout<<"VOLUME: "<<t1.get_volume()<<endl;

    t1.aumenta_volume();
    t1.trocar_de_canal();
    cout<<"CANAL: "<<t1.get_canal()<<endl;
    cout<<"VOLUME: "<<t1.get_volume()<<endl;
    return 0;
}
