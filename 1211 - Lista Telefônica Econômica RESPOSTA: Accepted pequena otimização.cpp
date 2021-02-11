#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;
int main(){
    int limite, economiaDeTonner= 0,mudarDeNumero = 0;
    string atualizarNumero;
    vector<string>listaTelefonica;
    while(cin>>limite) {
        for(int i = 0; i < limite; i++) {
            cin>>atualizarNumero;
            listaTelefonica.push_back(atualizarNumero);
        }
        sort(listaTelefonica.begin(),listaTelefonica.end());
        atualizarNumero = listaTelefonica[0];
        for (int j = 1; j < listaTelefonica.size(); j++) {
            for(int k = 0; k < listaTelefonica[j].size(); k++){
                if (listaTelefonica[j][k] == atualizarNumero[k]) {
                    mudarDeNumero++;
                } else {
                        if (atualizarNumero[mudarDeNumero] != listaTelefonica[j][mudarDeNumero]){
                            atualizarNumero = listaTelefonica[j];
                        }
                    break;
                }
            }
            economiaDeTonner += mudarDeNumero;
            mudarDeNumero = 0;
        }
        listaTelefonica.clear();
        cout << economiaDeTonner << endl;
        economiaDeTonner = 0;
    }
    return 0;
}

