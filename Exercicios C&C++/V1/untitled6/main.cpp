#include "classes.h"
int main() {
    Proprietario *P1;
    P1 = new Proprietario;
    string Aux_Nome;
    getline(cin,Aux_Nome);
    P1-> Set_Nome(Aux_Nome);
    cout<<P1->Get_Nome();



    return 0;
}
