//Resolução
#include<iostream>
#include <utility>
#include<vector>
using namespace std;
class ProblemaFacil{
    private:
        int tamanhoDoVetor;
        vector<int>vetorDeNumeros;
    public:
        ProblemaFacil(int,vector<int>);
        int consultaPar(pair<int,int>)const;
        ~ProblemaFacil();
};
ProblemaFacil::ProblemaFacil(int tamanhoDoVetor,vector<int>vetorDeNumeros){
    this->tamanhoDoVetor = tamanhoDoVetor;
    this->vetorDeNumeros = move(vetorDeNumeros);
}
ProblemaFacil::~ProblemaFacil(){
    vetorDeNumeros.clear();
}

int ProblemaFacil::consultaPar(pair<int,int> parNumeros)const{
    int contador = 0; 
    if(parNumeros.first > 0)
        for(int i = 0; i < this->tamanhoDoVetor;i++){
            if(vetorDeNumeros[i] == parNumeros.second){
                contador+=1;
            }
           if(contador == parNumeros.first)
                return i+1;
        }
    return 0;
}
int main(){
    int tamanhoDoVetor,numeroDeConsultas,numeroTemporario;
        while(cin>>tamanhoDoVetor) {
            vector<int>vetorDeNumeros(tamanhoDoVetor,0);
            cin>>numeroDeConsultas;
            {
                for (int i = 0; i < tamanhoDoVetor; i++)
                    cin>>vetorDeNumeros[i];           
                ProblemaFacil pb({tamanhoDoVetor, vetorDeNumeros});
                pair<int, int> parDeNumeros;
                for (int i = 0; i < numeroDeConsultas; i++) {
                    cin >> parDeNumeros.first;
                    cin >> parDeNumeros.second;

                    cout << pb.consultaPar(parDeNumeros) << endl;
                }
            }
        }
    return 0;
}
