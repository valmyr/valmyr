#include <iostream>
#include<iomanip>
using namespace std;
//protótipo da função principal
int main();
//incluindo lista
#include "./Lista.cpp"
int main() {
    //intanciando objeto lista
    Lista lN;
    //variável auxilar que recebe o nome
    string Nome;
    //variável auxilar que recebe o tamanho da lista
    int sizeL;
    //soliciatndo o tamanho da lista ao usuário
    cout<<"Informe a tamanho da lista: ";cin>>sizeL;
    //enviando tamanho da lista para o atributo de destino
    lN.setsizeL(sizeL);
    //loop
    while(true) {
        //variável que recebe a opção informada na função menu
        int  op = lN.menu();
        switch(op){
            case 1:
                //caso 1 o usuário escolhei inserir um nome a lista
                cout.fill('0');
                //solicitandi que o usuário informe o nome para efetuar o cadastro
                cin.ignore();
                cout<<"Nome[" <<setw(2)<< Lista::getdNomes() + 1 << "]: ";
                getline(cin,Nome);
                //inserindo nome
                if(not(lN.inserirNome(Nome)))cout<<"Nome nao adicionada a lista"<<endl;
                //ignorando caracter especial \n
                break;
            case 2:
                //caso 2 o usuário escolhei imprimindo lista
                lN.imprimirLista();
                break;
            case 3:
                //caso 3 o usuário escolhei ordenar lista
                lN.ordenarNomes();
                cout<<"Lista Ordenada"<<endl;
                break;
            case 4:
                //caso 4 o usuário escolhei mostrar total de nomes na lista
                cout<<"Total: "<<Lista::getdNomes()<<endl;
                break;
            case 5:
                //caso 5 o usuário escolhei limpar a tela
                system("cls");
                break;
            default:
                //caso 6 o usuário escolhei fechar
                return 0;
        }
    }
}
