#include <iostream>
#include<iomanip>
#include<cstring>
using namespace std;
//incluindo lista
#include "./Lista.cpp"
int main() {
    //intanciando do objeto lista
    Lista lN;
    //variável auxilar que recebe o nome
    string Nome;
    //variável auxilar que recebe o tamanho da lista
    int sizeL;
    //soliciatando o tamanho da lista ao usuário
    cout<<"Informe a tamanho da lista: ";cin>>sizeL;
    //enviando tamanho da lista para o atributo de destino
    lN.setsizeL(sizeL);
    //loop
    while(true) {
        //variável que recebe a opção informada na função menu
        int  op = lN.menu();
        switch(op){
            case 1:
                //caso 1 o usuário escolheu inserir um nome a lista
                cout.fill('0');
                //solicitando que o usuário informe o nome para efetuar o cadastro
                cin.ignore();
                cout<<"Nome[" <<setw(2)<< lN.getquantidadeAtualDeNomes() + 1 << "]: ";
                getline(cin,Nome);
                //inserindo nome
                if(not(lN.inserirNome(Nome)))cout<<"Nome nao adicionada a lista"<<endl;
                //ignorando caracter especial \n
                break;
            case 2:
                //caso 2 o usuário escolheu imprimindo lista
                lN.imprimirLista();
                break;
            case 3:
                //caso 3 o usuário escolheu ordenar lista
                lN.ordenarNomes();
                cout<<"Lista Ordenada"<<endl;
                break;
            case 4:
                //caso 4 o usuário escolheu mostrar total de nomes na lista
                cout<<"Total: "<<lN.getquantidadeAtualDeNomes()<<endl;
                break;
            case 5:
                //caso 5 o usuário escolheu limpar a tela
                system("cls");
                break;
            default:
                //caso 6 o usuário escolheu fechar
                return 0;
        }
    }
}
