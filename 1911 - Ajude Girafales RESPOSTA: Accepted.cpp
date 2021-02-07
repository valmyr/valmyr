#include<iostream>
#include<map>
using namespace std;
auto input(int & limite){
    map<string,string>assinaturas;
    string aluno,assinatura;
    cin>>limite;
    for(int i = 0; i < limite; i++){
        cin>>aluno;cin>>assinatura;
        assinaturas[aluno] = assinatura;
    }
    return assinaturas;
}
int main(){
    map<string,string>assinaturaOriginal,assinataturaDaAula;
    map<string,string>::iterator it;
    int limite;
    while(true){
        int assinaturaInvalida = 0;
        assinaturaOriginal = input(limite);
        if(!limite)break;
        assinataturaDaAula = input(limite);
        if(limite) {
            for (it = assinataturaDaAula.begin(); it != assinataturaDaAula.end(); it++) {
                int contadorEMaiorQueUm = 0;
                for (int i = 0; i < it->second.size(); i++) {
                    if (assinaturaOriginal[it->first][i] != assinataturaDaAula[it->first][i]) {
                        contadorEMaiorQueUm++;
                    }
                    if (contadorEMaiorQueUm > 1) {
                        assinaturaInvalida += 1;
                        break;
                    }
                }
            }
        }
        cout << assinaturaInvalida << endl;
    }
    return 0;
}
