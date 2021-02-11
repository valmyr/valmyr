#include <iostream>
#include<map>
#include<sstream>
using namespace std;
void split(stringstream str,string *output){
    int i = 0;
    while(getline(str,(output[i++]),' '));
}
int main() {
    map<string,int>campeonato;
    int pontuacao,limite;string time,resultado;
    bool boolean = true;
    string res[3];
    while (true) {
        cin >> limite;
        if(not(limite))break;
        if(boolean) boolean= false;
        else cout<<endl;
        for (int i = 0; i < limite; i++) {
            cin >> time;
            cin >> pontuacao;
            campeonato[time] = pontuacao;
        }
        cin.ignore();
        for (int i = 0; i < int(limite / 2); i++) {
            getline(cin, resultado);
            split(stringstream{resultado}, res);
            campeonato[res[0]] += (res[1][0] - '0') * 3;
            campeonato[res[2]] += (res[1][2] - '0') * 3;
            if ((res[1][0] - '0') > (res[1][2] - '0')) {
                campeonato[res[0]] += 5;
            } else if (((res[1][0] - '0') < (res[1][2]-'0'))) {
                campeonato[res[2]] += 5;
            } else {
                campeonato[res[0]] += 1;
                campeonato[res[2]] += 1;
            }
        }
        map<string,int>::iterator it = campeonato.begin();
        string campeaoDoCampeaonato = it->first;
        int valorMaximoDePontos = it->second;
        for(it; it != campeonato.end(); ++it){
            if(valorMaximoDePontos < it->second){
                campeaoDoCampeaonato = it->first;
                valorMaximoDePontos = it->second;
            }
        }
        if(campeaoDoCampeaonato == "Sport"){
            cout<<"O Sport foi o campeao com "<<valorMaximoDePontos<<" pontos :D"<<endl;
        }else{
            cout<<"O Sport nao foi o campeao. O time campeao foi o "<<campeaoDoCampeaonato<<" com "<<valorMaximoDePontos<<" pontos :("<<endl;
        }
        campeonato.clear();
    }
    cout<<endl;
   return 0;
}
