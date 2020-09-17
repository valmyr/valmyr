#include <iostream>
#include<iomanip>
using namespace std;
class Relogio{
    private:
        int Hora;
        int Minuto;
        int Segundo;
    public:
        Relogio();
        Relogio(int Hora, int Minuto, int Segundo);
        Padrao_Universal();
        Padrao_Americano();
};
Relogio::Relogio(){
    Hora = Segundo = Minuto = 0;
}
Relogio::Relogio(int Hora, int Minuto, int Segundo){
        this->Hora = Hora;
        this->Minuto = Minuto;
        this->Segundo = Segundo;
}
Relogio::Padrao_Universal(){
    cout<<setw(2)<<Hora<<":"<<setw(2)<<Minuto<<":"<<setw(2)<<Segundo<<endl;
}
Relogio::Padrao_Americano(){
    if(Hora > 12)
        cout<<setw(2)<<Hora-12<<":"<<setw(2)<<Minuto<<":"<<setw(2)<<Segundo<<" "<<"PM"<<endl;
    else if(Hora == 0)
        cout<<setw(2)<<Hora+12<<":"<<setw(2)<<Minuto<<":"<<setw(2)<<Segundo<<" "<<"AM"<<endl;
    else
        cout<<setw(2)<<Hora<<":"<<setw(2)<<Minuto<<":"<<setw(2)<<Segundo<<" "<<"AM"<<endl;
}
int main(){
    cout.fill('0');
    Relogio();
    Relogio h1;
    h1.Padrao_Universal();
    h1.Padrao_Americano();

    return 0;
}
