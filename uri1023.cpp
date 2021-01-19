#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

class Estiagem{
	private:
		int quantidadeDeMoradores;
		int consumoTotalDeAgua;
	public:
		Estiagem(int = 0, int = 0);

		void setQuantidadeDeMoradores(int);
		void setConsumoTotalDeAgua(int);

		int getQuantidadeDeMoradores()const;
		int getConsumoTotalDeAgua()const;
		~Estiagem();
};

bool formulaDeOrdenacao(Estiagem, Estiagem);
int verificarSeJaExiste(int ,vector<Estiagem>);
Estiagem::Estiagem(int quantidadeDeMoradores, int consumoTotalDeAgua){
	this->quantidadeDeMoradores = quantidadeDeMoradores;
	this->consumoTotalDeAgua = consumoTotalDeAgua;
}
void Estiagem::setQuantidadeDeMoradores(int quantidadeDeMoradores){
	this->quantidadeDeMoradores = quantidadeDeMoradores;
}
void Estiagem::setConsumoTotalDeAgua(int consumoTotalDeAgua){
	this->consumoTotalDeAgua = consumoTotalDeAgua;
}
int Estiagem::getQuantidadeDeMoradores()const{
	return quantidadeDeMoradores;
}
int Estiagem::getConsumoTotalDeAgua()const{
	return consumoTotalDeAgua;
}
Estiagem::~Estiagem(){}
class Lista{
	private:
		vector<Estiagem>vetorDeCidades;
		void __su__();
	public:
		void adicionandoCidades(Estiagem);
		void ordenarAscendeteDeConsumo();

		double mediaDeConsumoPorPessoa();
		void printList();
		~Lista();

};
void Lista::adicionandoCidades(Estiagem auxTemp){
	vetorDeCidades.push_back(auxTemp);
}
void Lista::ordenarAscendeteDeConsumo(){
	sort(vetorDeCidades.begin(),vetorDeCidades.end(),formulaDeOrdenacao);
}
double Lista::mediaDeConsumoPorPessoa(){
	double mediaConsumo = 0, mediaDePessoas = 0;
	for(auto i: vetorDeCidades){
		mediaConsumo+=float(i.getConsumoTotalDeAgua());		
		mediaDePessoas+=float(i.getQuantidadeDeMoradores());
	}
	int m = (double(double(mediaConsumo)/double(mediaDePessoas)))*1000;

	if(m%10 > 5)
		m-=m%10;
	return double(m/1000.0);
}
void Lista::printList(){
  this->__su__();
  this->ordenarAscendeteDeConsumo();
  for(auto i : vetorDeCidades){
    cout<<i.getQuantidadeDeMoradores()<<"-"<<i.getConsumoTotalDeAgua()<<" ";
  }
  cout<<endl;
}
void Lista::__su__(){
	vector<Estiagem>auxVetor;
	Estiagem aux;

	int mediaTemporario = int(vetorDeCidades[0].getConsumoTotalDeAgua()/vetorDeCidades[0].getQuantidadeDeMoradores());
	aux.setQuantidadeDeMoradores(vetorDeCidades[0].getQuantidadeDeMoradores());
	aux.setConsumoTotalDeAgua(mediaTemporario);
	auxVetor.push_back(aux);
	for(int i = 1; i < vetorDeCidades.size(); i++){
		int mediaTemporario = int(vetorDeCidades[i].getConsumoTotalDeAgua()/vetorDeCidades[i].getQuantidadeDeMoradores());

		int index = verificarSeJaExiste(mediaTemporario,auxVetor);
		if(index == -1){
			aux.setQuantidadeDeMoradores(vetorDeCidades[i].getQuantidadeDeMoradores());
			aux.setConsumoTotalDeAgua(mediaTemporario);
			auxVetor.push_back(aux);
		}else{
			auxVetor[index].setQuantidadeDeMoradores(auxVetor[index].getQuantidadeDeMoradores()+vetorDeCidades[i].getQuantidadeDeMoradores());
		}
	}
	vetorDeCidades.clear();
	vetorDeCidades = auxVetor;
}
Lista::~Lista(){
	vetorDeCidades.clear();
}
int main(){
	Estiagem auxEstiagem;
	cout.precision(2);
	int n;
	int auxQuandtidadeDeMoradores = 0;
	int auxConsumoTotalDeAgua = 0;
	int contador = 0;
	while(true){
		{
			Lista listaDeEstiagem;
			cin>>n;
			if(not(n))
				break;
			if(contador > 0){
				cout<<endl;
			}
			for(int i = 0; i < n; i++){
				cin>>auxQuandtidadeDeMoradores;
				cin>>auxConsumoTotalDeAgua;
				auxEstiagem.setQuantidadeDeMoradores(auxQuandtidadeDeMoradores);
				auxEstiagem.setConsumoTotalDeAgua(auxConsumoTotalDeAgua);
				listaDeEstiagem.adicionandoCidades(auxEstiagem);
		    }
		    float mediaDeConsumo = listaDeEstiagem.mediaDeConsumoPorPessoa();
		    cout<<"Cidade# "<<contador+1<<":"<<endl;
		    listaDeEstiagem.printList();
		    cout<<"Consumo medio: "<<fixed<<double(mediaDeConsumo)-0.001<<" m3."<<endl;
		   }
		contador+=1;
	}
	return 0;
}
bool formulaDeOrdenacao(Estiagem est1, Estiagem est2){
	if(est1.getConsumoTotalDeAgua() < est2.getConsumoTotalDeAgua())
		return true;
	return false;
}
int verificarSeJaExiste(int chave,vector<Estiagem>vetorAtual){

	for(int i = 0; i < vetorAtual.size();i++)
		if(vetorAtual[i].getConsumoTotalDeAgua() == chave)
			return i;
	return -1;
}
