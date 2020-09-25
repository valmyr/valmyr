//
// Created by valmyr on 23/09/2020.
//
#include<iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
int main();
#include "./fracao.cpp"
int main() {
    //instanciando objetos
    Rational f1, f2, fr;
    //variaveis que receberam os valores informados pelo usuário
    int num_, den_, op;
    //variável que recebera o sinal da operação
    char oper;
    //solicitando dados do usuário
    cout<<"Informe a primeira fracao: "<<endl;
    cout<<"[a]  >> ";
    cin>>num_;
    cout<<"[b]  >> ";
    cin>>den_;
    //enviando dados para atribuir ao objeto
    f1.set_numerador((int)num_);
    f1.set_denominador((int)den_);
    cout<<"Informe a segunda fracao: "<<endl;
    cout<<"[a]  >> ";
    cin>>num_;
    cout<<"[b]  >> ";
    cin>>den_;
    //enviando dados para atribuir ao objeto
    f2.set_numerador((int)num_);
    f2.set_denominador((int)den_);
    //interação com o usuário
    cout<<"Informe a operacao: "<<endl<<"[*] Multiplicacao "<<endl<<"[/] Divisao"<<endl;
    cout<<">> ";

    cin>>oper;
    while(oper != '*' and oper != '/'){
        //Validando respostas
        cout<<"opcao invalida"<<endl;
        cout<<"tente novamente: "<<endl;
        cin>>oper;
    }
    cout<<"Resultado: "<<endl;
    if(oper == '/'){
        //caso o usuário informe o caracter '/' ele deseja efetuar uma divisão de frações
        //exibindo frações
        fr.exibir(f1,f2,oper);
        fr.dividir(f1,f2);
    }else if(oper == '*'){
        //caso o usuário informe o caracter '*' ele deseja  efetuar a multiplicação de frações
        fr.exibir(f1,f2,oper);
        fr.multiplicar(f1,f2);
    }
    //exibindo resultado
    fr.exibir();
    //interação com o usuário
    cout<<endl<<"Deseja finalizar?"<<endl;
    cout<<"[1] Sim"<<endl<<"[2] Nao"<<endl<<">>";
    cin>>op;
    //validando resposta
    while(op < 1 or op > 2){
        cout<<"opcao invalida"<<endl;
        cout<<"tente novamente: "<<endl;
        cin>>op;
        //ignorando o caracter '\n'
        cin.ignore();
    }
    //caso o usuário informe 1 ele quer fechar o programa
    if(op == 1)
        return 0;
    //Limpando a tela
    //No windows o comando que limpa a tela do prompt de
    //comando e o cls no linux o comando que limpa a tela do terminal e clear
    system("cls");
    //caso contrário ele quer reiniciar
    main();
}
