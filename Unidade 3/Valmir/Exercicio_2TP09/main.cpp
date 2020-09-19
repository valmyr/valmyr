#include<iostream>
#include<iomanip>
#include <cstdlib>
/*
Importante: Compilador usado Clion, C++17.
Sistema Operacional: Windowns 10
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
Professor: Marcus Salerno
    Laboratório Virtual de Programação 09
1.      Crie uma classe chamada Rational para realizar aritmética com frações.
Descrição: Utilize variáveis do tipo inteiro para representar os dados private
da classe – o numerador e o denominador. Forneça um construtor que permita que
um objeto dessa classe seja inicializado com valores quando ele for declarado.
O construtor deve conter valores-padrão no caso de nenhum inicializador ser fornecido.
 Forneça funções-membro public que realizam cada uma das tarefas a seguir:
a)      Multiplicar dois números Rational.
b)      Dividir dois números Rational.
Adicione à classe anterior chamada Rational as seguintes funcionalidades:
a)      Imprimir os números Rational na forma a/b, onde a é o numerador e b é o denominador.
b)      Imprimir os números Rational em formato de ponto flutuante.
Obs.: Crie um programa para testar a classe.
Obs.: Para vocês entenderem como se calcula a multiplicação de frações, lembrem-se que haverá
 uma fração que será gerada como resultado da multiplicação de outras duas, ou seja, dada a classe
 Fracao, na main teremos:
int main(){
     Fracao f1, f2, fr;
     ....
     fr.multiplica(f1, f2);
}
PS.: o método multiplica, da fração fr, recebe as duas frações (f1 e f2), multiplica os denominadores e
 numeradores (obedecendo as regras das frações) e o resultado é armazenado no denominador e numerador da fr.
Neste exemplo, é importante que vocês saibam (ou pesquisem) como são realizadas a multiplicação e divisão
de frações.
*/
#include <iostream>
#include<cstdlib>
using namespace std;
int main();///protótipo da função main()
class Rational{
    int numerador;
    int denominador;
    //Metodo para o cálculo do máximo divisor comum
    void MDC(Rational &);
public:
    //construtor padrão
    Rational();
    //o construtor  que recebe os argumentos do desenvolvedor
    Rational(int , int);
    //Método que efetuar a multiplicação das frações
    Rational Multiplicar(Rational, Rational);
    //Método que efetuar a divisão das frações
    Rational Dividir(Rational, Rational);
    //atribuir valores aos atributos da class
    void set_denominador(int );
    void set_numerador(int);
    //retorna o numerador
    int get_numerador(void);
    //retorna o denominador
    int get_denominador(void);
    //Exibir as frações na notação usual
    void Exibir(Rational, Rational, char);
    //exibir o resultado
    void Exibir(void);
    //Método para inverter o sinal
    void sinal();

};
Rational::Rational(){
    //atribuição por padrão zero no numerador e 1 no denominador
    set_numerador(0);
    set_denominador(1);

}
Rational::Rational(int numerador, int denominador){
    //atribuir os valores que o desenvolvedor passou como argumentos da função aos atributos da class
    set_numerador(numerador);
    set_denominador(denominador);
}
Rational Rational::Dividir(Rational F1, Rational F2){
    //Cálculo da divisão
    numerador = F1.numerador * F2.denominador;
    denominador = F1.denominador * F2.numerador;
    //simplificando divisão
    MDC(*this);
    //retornando objeto
    this->sinal();
    return *this;
}
Rational Rational::Multiplicar(Rational F1, Rational F2){
    //Cálculo
    numerador = F1.numerador * F2.numerador;
    denominador = F1.denominador * F2.denominador;
    //simplificando
    //e passando por refêrencia o Objeto para que não precise usar return
    MDC(*this);
    //retonando objeto
    this->sinal();
    return *this;
}
void Rational::set_numerador(int numerador){
    //atribuindo valores ao atributo da class
    this->numerador = numerador;
}
void Rational::set_denominador(int denominador){
    //atribuindo valores ao atributo da class
    //caso o denominado informando pelo usuário seja igual a zero o usuário recebe a mensagem
    //"Denominador invalido informe um numero diferente de zero"
    if(denominador == 0){
        cout<<"Denominador invalido informe um numero diferente de zero"<<endl;
        main();
    }
    //caso contrario o atributo recebe o valor informado
    this->denominador = denominador;
}
int Rational::get_numerador(void){
    //retornando numerador
    return numerador;
}
int Rational::get_denominador(void){
    //retornando denominador
    return denominador;
}
void Rational::MDC(Rational &FR){
    //usando o algoritmo de Euclides para determinar o mdc
    int numAux = FR.numerador;
    int denAux = FR.denominador;
    while(denAux != 0){
        int temp = numAux % denAux;
        numAux = denAux;
        denAux = temp;
    }
    //como estou acessando diretamente o endereço da variável FR não preciso usar return
    FR.numerador /= numAux;
    FR.denominador /= numAux;
}
void Rational::Exibir(Rational F1, Rational F2, char sinal){
    //Exibindo a fração
    cout<<"("<<F1.numerador<<" / "<<F1.denominador<<") "<<sinal<<" ("<<F2.numerador<<" / "<<F2.denominador<<") = ";
}
void Rational::Exibir(void){
    //precisão 2 casas decimais após a vírgula
    cout.precision(2);
    //exibindo o resultado
    cout<<"("<<numerador<<" / "<<denominador<<")";

}
void Rational::sinal(){
    //Invertendo o sinal do resultado caso o denominador seja negativo
    if(denominador < 0){
        numerador*=-1;
        denominador*=-1;
    }
}
int main() {
    //instanciando objetos
    Rational F1, F2, FR;
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
    F1.set_numerador((int)num_);
    F1.set_denominador((int)den_);
    cout<<"Informe a segunda fracao: "<<endl;
    cout<<"[a]  >> ";
    cin>>num_;
    cout<<"[b]  >> ";
    cin>>den_;
    //enviando dados para atribuir ao objeto
    F2.set_numerador((int)num_);
    F2.set_denominador((int)den_);
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
    if(oper == '/'){
        //caso o usuário informe o caracter '/' ele quer efetuar uma divisão de frações
        //Exibindo frações
        F1.Exibir(F1,F2,oper);
        FR = F1.Dividir(F1,F2);
    }else if(oper == '*'){
        //caso o usuário informe o caracter '*' ele quer  efetuar a multiplicação de frações
        F1.Exibir(F1,F2,oper);
        FR =  F1.Multiplicar(F1,F2);
    }
    //exibindo resultado
    FR.Exibir();
    //Mostrando ponto flutuante
    cout<<endl<<"Ponto flutuante: "
        <<fixed<<(double)FR.get_numerador()/FR.get_denominador()<<endl;
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
    //caso o usuário informe 1 ele quer ferchar o programa
    if(op == 1)
        return 0;
    //Limpando a tela
    //No windows o comando que limpa a tela do prompt de
    //comando e o cls no linux o comando que limpa a tela do terminal e clear
    system("cls");
    //caso contrário ele quer reiniciar
    main();
}
