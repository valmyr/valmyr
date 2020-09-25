#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#include "./Relogio.cpp"
int main(){
    Relogio r1;
    r1.setHora(23,59,59);
    for(int i = 0; i < 999;i++) {
        r1.get_hora();
        r1.atualizar();
        r1.mostrar_hora();
        system("cls");
    }
    return 0;
}
