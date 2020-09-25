#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#include "./Relogio.cpp"
int main(){
    Relogio r1;
    cout.fill('0');
    r1.setHora(16,48,59);
    int hora, minuto, segundo;
    for(int i = 0; i < 999;i++) {
        r1.getHora(hora, minuto, segundo);
        r1.atualizar();
        cout<<setw(2)<<hora<<":"<<setw(2)<<minuto<<":"<<setw(2)<<segundo<<endl;
        system("cls");
    }
    return 0;
}
