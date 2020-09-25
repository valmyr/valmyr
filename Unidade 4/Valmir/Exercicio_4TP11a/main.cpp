#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#include "./Relogio.cpp"
int main(){
    Relogio r1;
    cout.fill('0');
    r1.setHora(23,59,59);
    int hora, minuto, segundo;
    for(int i = 0; i < 999;i++) {
        r1.get_hora();
        r1.atualizar(hora, minuto, segundo);
    	cout<<setw(2)<<hora<<":"<<setw(2)<<minuto<<":"<<setw(2)<<segundo<<endl;
        system("cls");
    }
    return 0;
}
