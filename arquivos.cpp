#include < iostream >
#include < fstream >
#include < vector >
using namespace std;
class Pessoa{
  private:
    string nome;
    int idade;
    vector < Pessoa > Lista;
  public:
    Pessoa(string = "0", int = 0);
    void setNome(string);
    string getNome();
    void setIdade(int);
    int getIdade();
    bool addLista(Pessoa);
    void imprimirLista();
    bool carregarLista();
    bool salvarLista();
    int menu();
    friend ostream& operator<< (ostream& , Pessoa& );
    friend istream& operator>> (istream&, Pessoa&);
};
int Pessoa::menu(){
  int op;
  cout<<"[1] Adicionar"<<endl;
  cout<<"[2] Salvar"<<endl;
  cout<<"[3] Carregar Dados"<<endl;
  cout<<"[4] Imprimir Lista"<<endl;
  cout<<"[5] Sair"<<endl;
  cin>>op;
  system("cls");
  return op;
}

bool Pessoa::carregarLista(){
  fstream arq("Dados1.bin", ios::in);
  Pessoa pAux;
  if(not(arq.is_open())){
    cout<<"Erro ao abrir o arquivo"<<endl;
    return false;
  }
  while(arq.read(reinterpret_cast<char *> (&pAux),sizeof(Pessoa))){
    Lista.push_back(pAux);
  }
  arq.close();
  return true;
}
bool Pessoa::salvarLista(){
  fstream arq("Dados1.bin", ios::out);
  Pessoa pAux;
  if(not(arq.is_open())){
    cout<<"Erro ao salvar"<<endl;
    return false;
  }
  for(int i = 0 ;i < Lista.size();i++){
    pAux = Lista[i];
    arq.write(reinterpret_cast<char *> (&pAux),sizeof(Pessoa));
  }
  return true;
}
void Pessoa::imprimirLista(){
  for(int i = 0; i < Lista.size(); i++){
      cout<<Lista[i]<<endl;
  }
}
istream& operator>> (istream& i, Pessoa& pAux){
  string nome; int idade;
  cout<<"Nome: ";cin>>nome;
  cout<<"Idade: ";cin>>idade;
  pAux.setNome(nome);
  pAux.setIdade(idade);
  return i;
}
bool Pessoa::addLista(Pessoa pAux){
  Lista.push_back(pAux);
  return true;
}

ostream& operator<< (ostream& o, Pessoa& pAux){
  cout<<pAux.getNome()<<" "<<pAux.getIdade();
  return o;
}
Pessoa::Pessoa(string nome, int idade){
  this->nome = nome;
  this->idade = idade;
}
void Pessoa::setNome(string nome){
  this->nome = nome;
}
void Pessoa::setIdade(int idade){
  this->idade = idade;
}
string Pessoa::getNome(){
  return nome;
}
int Pessoa::getIdade(){
  return idade;
}
int main(){
  Pessoa lista, pAux;
  while ((true)) {
    int op (lista.menu());
    switch (op) {
      case 1:
        cin>>pAux;
        lista.addLista(pAux);
        cout<<"Adicionado"<<endl;
        break;
      case 2:
        lista.salvarLista();
        cout<<"Lista salva"<<endl;
        break;
      case 3:
        lista.carregarLista();
        cout<<"Lista carregada"<<endl;
        break;
      case 4:
        lista.imprimirLista();
        cout<<"Lista impressa"<<endl;
        break;
      default:
        system("notepad Dados1.bin");
        return 0;
    }
      system("pause");
  }
}
