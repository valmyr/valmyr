#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class SpursRocks{
    private:
        int inscricaoNaLiga;
        int quantidadeDePontosRecebidos;
        int pontos;
    public:
        SpursRocks(int = 0,int = 0);
        void setPontos(int);
        void setInscricaoNaLiga(int);
        void setQuantidadeDePontosRecebidos();
        int getInscricaoNaLiga()const;
        int getPontos()const;
        int getQuantidadeDePontosRecebidos()const;
};
SpursRocks::SpursRocks(int inscricaoNaLiga,int pontos){
    this->inscricaoNaLiga = inscricaoNaLiga;
    this->pontos = pontos;
    this->quantidadeDePontosRecebidos = 0;

}
void SpursRocks::setQuantidadeDePontosRecebidos(){
    this->quantidadeDePontosRecebidos+=1;
}
int SpursRocks::getInscricaoNaLiga()const{
    return this->inscricaoNaLiga;
}
int SpursRocks::getPontos()const{
    return this->pontos;
}
void SpursRocks::setPontos(int pontos){
    this->pontos = pontos;
}
void SpursRocks::setInscricaoNaLiga(int inscricaoNaLiga){
    this->inscricaoNaLiga = inscricaoNaLiga;
}
int SpursRocks::getQuantidadeDePontosRecebidos()const{
    return this->quantidadeDePontosRecebidos;
}
class Times{
    private:
        vector<SpursRocks>times;
        int n;
    public:
        Times(int = 0);
        void inserirTime(SpursRocks );
        void classificaoDeTimes();
};
Times::Times(int n){
    this->n = n;
}
void Times::inserirTime(SpursRocks temporario){
    times.push_back(temporario);
}
bool customOrd(SpursRocks c1,SpursRocks c2){
    if(c1.getPontos() == c1.getPontos()){
        if(c1.getPontos()/float(c1.getQuantidadeDePontosRecebidos()) == c2.getPontos()/float(c2.getQuantidadeDePontosRecebidos())){
            if(c1.getQuantidadeDePontosRecebidos() == c2.getQuantidadeDePontosRecebidos()){
               cout<<"nivel 4"<<endl;    
                return c1.getInscricaoNaLiga() > c2.getInscricaoNaLiga();
            }
            cout<<"nivel 3"<<endl;
            return c1.getQuantidadeDePontosRecebidos() < c2.getQuantidadeDePontosRecebidos();    
        }
        cout<<"nivel 2"<<endl;
        return c1.getPontos()/float(c1.getQuantidadeDePontosRecebidos()) > c2.getPontos()/float(c2.getQuantidadeDePontosRecebidos());
    }
    cout<<"nivel 1"<<endl;
    return c1.getPontos() > c2.getPontos();
}
void Times::classificaoDeTimes(){
    vector<SpursRocks>classif(n);
    for(int i = 1; i < times.size();i++){
        if(times[i-1].getPontos() > times[i].getPontos()){
            classif[times[i-1].getInscricaoNaLiga()-1].setPontos(classif[times[i-1].getInscricaoNaLiga()-1].getPontos()+2);
            classif[times[i-1].getInscricaoNaLiga()-1].setInscricaoNaLiga(times[i-1].getInscricaoNaLiga());
            classif[times[i-1].getInscricaoNaLiga()-1].setQuantidadeDePontosRecebidos();
            classif[times[i].getInscricaoNaLiga()-1].setPontos(classif[times[i].getInscricaoNaLiga()-1].getPontos()+1);
            classif[times[i].getInscricaoNaLiga()-1].setInscricaoNaLiga(times[i].getInscricaoNaLiga());
            classif[times[i].getInscricaoNaLiga()].setQuantidadeDePontosRecebidos();
        }else{
            classif[times[i].getInscricaoNaLiga()-1].setPontos(classif[times[i].getInscricaoNaLiga()-1].getPontos()+2);
            classif[times[i].getInscricaoNaLiga()-1].setInscricaoNaLiga(times[i].getInscricaoNaLiga());
            classif[times[i].getInscricaoNaLiga()].setQuantidadeDePontosRecebidos();
            classif[times[i-1].getInscricaoNaLiga()-1].setPontos(classif[times[i-1].getInscricaoNaLiga()-1].getPontos()+1);
            classif[times[i-1].getInscricaoNaLiga()-1].setInscricaoNaLiga(times[i-1].getInscricaoNaLiga());
            classif[times[i-1].getInscricaoNaLiga()-1].setQuantidadeDePontosRecebidos();
        }
    }
   sort(classif.begin(),classif.end(),customOrd);
    for(int i = 0; i < classif.size()-1; i++){
        cout<<classif[i].getInscricaoNaLiga()<<" ";
    }

    cout<<classif[classif.size()-1].getInscricaoNaLiga()<<endl;
}
int main(){
    int n, numeroDeInscricaoNaLiga, numeroDePontos;
    int contador = 0;
    do{
        cin>>n;
        if(n == 0)
            break;
        int limite = n*(n-1)/2;
        {
            Times t(n);
            for(int i = 0; i < limite; i++){
                cin>>numeroDeInscricaoNaLiga;
                cin>>numeroDePontos;
                SpursRocks tmp1(numeroDeInscricaoNaLiga,numeroDePontos);
                t.inserirTime(tmp1);
                cin>>numeroDeInscricaoNaLiga;
                cin>>numeroDePontos;
                SpursRocks tmp2(numeroDeInscricaoNaLiga,numeroDePontos);
                t.inserirTime(tmp2);
            }
            cout<<"Instancia "<<(contador++)+1<<endl;
            t.classificaoDeTimes();
        }
    }while(true);
    return 0;
}
