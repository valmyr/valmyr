#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class SpursRocks{
    private:
        int inscricaoNaLiga;
        int marcados;
        int recebidos;
        int pontos;
    public:
        SpursRocks(int = 0,int = 0);
        void setPontos(int);
        void setInscricaoNaLiga(int);
        void setMarcados(int);
        void setRecebidos(int);
        int getInscricaoNaLiga()const;
        int getPontos()const;
        int getMarcados()const;
        int getRecebidos()const;
};
SpursRocks::SpursRocks(int inscricaoNaLiga,int pontos){
    this->inscricaoNaLiga = inscricaoNaLiga;
    this->pontos = pontos;
    this->marcados = 0;
    this->recebidos = 0;
}
void SpursRocks::setMarcados(int marcados){
    this->marcados+=marcados;
}
void SpursRocks::setRecebidos(int recebidos){
    this->recebidos+=recebidos;
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
int SpursRocks::getMarcados()const{
    return this->marcados;
}
int SpursRocks::getRecebidos()const{
    return this->recebidos;
}
bool customOrd(SpursRocks c1,SpursRocks c2){
    //cout<<c1.getInscricaoNaLiga()<<" inscricaoNaLiga "<<c2.getInscricaoNaLiga()<<endl;
    //cout<<c1.getPontos()<<" Pontos "<<c2.getPontos()<<endl;
    //cout<<c1.getMarcados()<<" Pontos "<<c2.getMarcados()<<endl;
    //cout<<c1.getRecebidos()<<" recebidos "<<c2.getRecebidos()<<endl;
    //cout<<float(c1.getMarcados())/float(c1.getRecebidos())<<" avange "<<float(c2.getMarcados())/float(c2.getRecebidos())<<endl;
    if(c1.getPontos() == c2.getPontos()){
        if(float(c1.getMarcados())/float(c1.getRecebidos()) == float(c2.getMarcados())/float(c2.getRecebidos())){
            if(c1.getMarcados() == c2.getMarcados()){
    //            cout<<"Nivel 4"<<endl;
                return c1.getInscricaoNaLiga() > c2.getInscricaoNaLiga();
            }
    //        cout<<"Nivel 3"<<endl;
            return c1.getMarcados() < c2.getMarcados();
        }
    //    cout<<"Nivel 2"<<endl;
        return float(c1.getMarcados())/float(c1.getRecebidos()) > float(c2.getMarcados())/float(c2.getRecebidos());
    }
    //cout<<"Nivel 1"<<endl;
    return c1.getPontos() > c2.getPontos();
}
void classificaoDeTimes(vector<SpursRocks>classif){
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
        if(contador > 0)
            cout<<endl;
        cin>>n;
        if(n == 0)
            break;
        int limite = n*(n-1)/2;
        {
            vector<SpursRocks>classif(n);
            for(int i = 0; i < limite; i++){
                cin>>numeroDeInscricaoNaLiga;
                cin>>numeroDePontos;
                SpursRocks tmp1(numeroDeInscricaoNaLiga,numeroDePontos);
                cin>>numeroDeInscricaoNaLiga;
                cin>>numeroDePontos;
                SpursRocks tmp2(numeroDeInscricaoNaLiga,numeroDePontos);
                classif[tmp1.getInscricaoNaLiga()-1].setMarcados(tmp1.getPontos());
                classif[tmp1.getInscricaoNaLiga()-1].setRecebidos(tmp2.getPontos());
                classif[tmp2.getInscricaoNaLiga()-1].setMarcados(tmp2.getPontos());
                classif[tmp2.getInscricaoNaLiga()-1].setRecebidos(tmp1.getPontos());
                if (tmp1.getPontos() > tmp2.getPontos()) {
                    classif[tmp1.getInscricaoNaLiga()-1].setPontos(classif[tmp1.getInscricaoNaLiga()-1].getPontos()+2);
                    classif[tmp2.getInscricaoNaLiga()-1].setPontos(classif[tmp2.getInscricaoNaLiga()-1].getPontos()+1);
                    classif[tmp1.getInscricaoNaLiga()-1].setInscricaoNaLiga(tmp1.getInscricaoNaLiga());
                    classif[tmp2.getInscricaoNaLiga()-1].setInscricaoNaLiga(tmp2.getInscricaoNaLiga());
                }else{
                    classif[tmp1.getInscricaoNaLiga()-1].setPontos(classif[tmp1.getInscricaoNaLiga()-1].getPontos()+1);
                    classif[tmp2.getInscricaoNaLiga()-1].setPontos(classif[tmp2.getInscricaoNaLiga()-1].getPontos()+2);
                    classif[tmp1.getInscricaoNaLiga()-1].setInscricaoNaLiga(tmp1.getInscricaoNaLiga());
                    classif[tmp2.getInscricaoNaLiga()-1].setInscricaoNaLiga(tmp2.getInscricaoNaLiga());
                }
            }
            cout<<"Instancia "<<(contador++)+1<<endl;
            classificaoDeTimes(classif);
            classif.clear();
        }
    }while(true);
    return 0;
}
