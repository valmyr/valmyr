#include <iostream>
#include<map>
using namespace std;
int main() {
  map<int,int>escritorios;
  int quantidadeDeEscritoriosNaUltimaSemana;
  int quantidadeDeEscritoriosNosUltimosDias;
  int escritorio;
  cin>>quantidadeDeEscritoriosNaUltimaSemana>>quantidadeDeEscritoriosNosUltimosDias;
  for(int i = 0; i < quantidadeDeEscritoriosNosUltimosDias; i++){
    cin>>escritorio;
    escritorios[escritorio] = escritorio; 
  }
  for(int i = 0; i < quantidadeDeEscritoriosNaUltimaSemana; i++){
    cin>>escritorio;
    if(escritorios[escritorio] == 0){
      cout<<1;
      escritorios[escritorio] = escritorio;
    }else{
      cout<<0;
    }
    cout<<endl;
  }
  return 0;
}
