#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<double>v = {100,50,20,10,5,2,1,.50,.25,.10,.05,.01};
    cout.precision(2);
    double valorMonetario;
    cin>>fixed>>valorMonetario;
    //doping
    valorMonetario+=0.001;
    cout<<"NOTAS:"<<endl;
    for(int i = 0; i < v.size(); i++){
        if(i == 6)
            cout<<"MOEDAS:"<<endl;
        if(i < 6)
            cout<<int(valorMonetario / v[i])<<" nota(s) de R$ "<<fixed<<v[i]<<endl;
        else
            cout<<int(valorMonetario / v[i])<<" moeda(s) de R$ "<<fixed<<v[i]<<endl;

        valorMonetario= valorMonetario-double(v[i]*int(valorMonetario / v[i]));
    }
}
