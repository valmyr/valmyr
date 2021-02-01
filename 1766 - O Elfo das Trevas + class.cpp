#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Renas{
	private:
		string nome;
		int peso;
		int idade;
		float altura;
	public:
		Renas(const string& = " ",const int& = 0,const int& = 0,const float& = 0.0);
		void setNome(const string&);
		void setPeso(const int&);
		void setIdade(const int&);
		void setAltura(const float&);


		string getNome()const;
		int getPeso()const;
		int getIdade()const;
		float getAltura()const;

};
Renas::Renas(const string & nome,const int& peso,const int& idade,const float& altura){
	Renas::setNome(nome);
	Renas::setPeso(peso);
	Renas::setIdade(idade);
	Renas::setAltura(altura);
}
void  Renas::setNome(const string& nome){
	this->nome = nome;
}
void Renas::setPeso(const int& peso){
	this-> peso = peso;
}
void Renas::setIdade(const int& idade){
	this->idade = idade;
}
void Renas::setAltura(const float& altura){
	this->altura = altura;
}

string Renas::getNome()const{
	return this->nome;
}
int Renas::getPeso()const{
	return this-> peso;
}
int Renas::getIdade()const{
	return this->idade;
}
float Renas::getAltura()const{
	return this->altura;
}

class Lista{
	private:
		vector<Renas>vetorDeRenas;
		int numeroDeRenasQueIraoPuxarOTreno;
	public:
		Lista();
		void setNumeroDeRenasQueIraoPuxarOTreno(int);
		void adicionarRenas(const Renas&);
		void sortCustom();
		void imprimir()const;
		~Lista(){
		    this->vetorDeRenas.clear();
		}
};
Lista::Lista(){
    this->numeroDeRenasQueIraoPuxarOTreno = 0;
}
bool lambda(const Renas& r1, Renas &r2){
    if(r1.getPeso() == r2.getPeso()) {
        if (r1.getIdade() == r2.getIdade()) {
            if (r1.getAltura() == r2.getAltura())
                return r1.getNome() < r2.getNome();
            return r1.getAltura() < r2.getAltura();
        }
        return r1.getIdade() < r2.getIdade();
    }
    return r1.getPeso() > r2.getPeso();
}
void Lista::sortCustom(){
	sort(begin(vetorDeRenas),end(vetorDeRenas),lambda);
}
void Lista::imprimir()const{
    for(int i = 0; i < numeroDeRenasQueIraoPuxarOTreno; i++){
        cout<<i+1<<" - "<<vetorDeRenas[i].getNome()<<endl;
    }
}

void Lista::setNumeroDeRenasQueIraoPuxarOTreno(int numeroDeRenasQueIraoPuxarOTreno){
	this->numeroDeRenasQueIraoPuxarOTreno=numeroDeRenasQueIraoPuxarOTreno;
}
void Lista::adicionarRenas(const Renas& renaTemporaria){
	vetorDeRenas.push_back(renaTemporaria);
}

int main(){
	int numeroDeCasosDeTeste;string nome;int peso,idade;float altura;
	int quantidadeDeRenas,numeroDeRenasQueIraoPuxarOTreno;
	Renas renaTemp;
	cin>>numeroDeCasosDeTeste;
	for(int i = 0; i  < numeroDeCasosDeTeste; i++){
		cin>>quantidadeDeRenas;
		cin>>numeroDeRenasQueIraoPuxarOTreno;
        {
            Lista r;
            r.setNumeroDeRenasQueIraoPuxarOTreno(numeroDeRenasQueIraoPuxarOTreno);
            for (int j = 0; j < quantidadeDeRenas; j++) {
                cin >> nome;
                cin >> peso;
                cin >> idade;
                cin >> altura;
                renaTemp.setNome(nome);
                renaTemp.setPeso(peso);
                renaTemp.setIdade(idade);
                renaTemp.setAltura(altura);
                r.adicionarRenas(renaTemp);
            }
            cout << "CENARIO {" << i + 1 << "}" << endl;
            r.sortCustom();
            r.imprimir();
        }

	}
	return 0;
}
