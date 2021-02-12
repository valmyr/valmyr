#include <iostream>
#include<map>
using namespace std;
int main() {
    int pontuacao,limite;
    string input_Time1,placar,input_Time2;
    cin>>limite;
    while (limite != 0) {
    	map<string,int>campeonato;
        for (int i = 0; i < limite; i++) {
            cin >> input_Time1;
            cin >> pontuacao;
            campeonato[input_Time1] = pontuacao;
        }
        for(int i = 0; i < int(limite/2); i++){
            cin>>input_Time1;
            cin>>placar;
            cin>>input_Time2;
            campeonato[input_Time1] += int(int((placar[0] - '0')) * 3);
            campeonato[input_Time2] += int(int((placar[2] - '0')) * 3);
            if (placar[0] - '0' > placar[2] - '0'){
                campeonato[input_Time1] += 5;
            }else if (placar[0] - '0' < placar[2]-'0'){
                campeonato[input_Time2] += 5;
            }else{
                campeonato[input_Time1] += 1;
                campeonato[input_Time2] += 1;
            }
        }
        map<string,int>::iterator it = campeonato.begin();
        string campeaoDoCampeaonato = it->first;

        int valorMaximoDePontos = it->second;
        if(limite == 1)
        	valorMaximoDePontos = pontuacao;
        for(it; it != campeonato.end(); ++it){
            if(it->second > valorMaximoDePontos){
                campeaoDoCampeaonato = it->first;
                valorMaximoDePontos = it->second;
            }
        }
        if(campeaoDoCampeaonato == "Sport")
            cout<<"O Sport foi o campeao com "<<int(valorMaximoDePontos)<<" pontos :D"<<endl<<endl;
        else
            cout<<"O Sport nao foi o campeao. O time campeao foi o "<<string(campeaoDoCampeaonato)<<" com "<<int(valorMaximoDePontos)<<" pontos :("<<endl<<endl;

    	cin>>limite;
        campeonato.clear();

    }
    return 0;
}
