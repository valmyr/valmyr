#include <iostream>

using namespace std;

int main() {
    cout.precision(1);
    int n1, n2, nv;
    while(true){
        while(true){
            cin>>n1;
            if(n1>=0 && n1<=10){
                break;
            }else{
                cout<<"nota invalida\n";
                fflush(stdin);
            }
        }
        while(true){
            cin>>n2;
            if(n2>=0 && n2<=10){
                break;
            }else{
                cout<<"nota invalida\n";
            }
        }
        cout<<"media = "<<(n1+n2)/2<<endl;
        cout<<"novo calculo (1-sim 2-nao)"<<endl;
        while(true){
            cin>>nv;
            if(nv == 2||nv == 1){
                break;
            }
            cout<<"novo calculo (1-sim 2-nao)"<<endl;
        }
        if(nv == 2){
            break;
        }
    }

    return 0;
}