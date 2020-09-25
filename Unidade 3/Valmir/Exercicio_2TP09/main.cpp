  
#include<iostream>
#include<iomanip>
#include <cstdlib>
using namespace std;
/*
Importante: Compilador usado Clion, C++17.
Sistema Operacional: Windowns 10
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
Professor: Marcus Salerno
    Laboratório Virtual de Programação 09
    
1. Crie uma classe chamada Rational para realizar aritmética com frações.
Descrição: Utilize variáveis do tipo inteiro para representar os dados private
da classe – o numerador e o denominador. Forneça um construtor que permita que
um objeto dessa classe seja inicializado com valores quando ele for declarado.
O construtor deve conter valores-padrão no caso de nenhum inicializador ser fornecido.
 Forneça funções-membro public que realizam cada uma das tarefas a seguir:
	a) Multiplicar dois números Rational.
<<<<<<< Updated upstream
	b) Dividir dois números Rational. Adicione à classe anterior chamada Rational as 
seguintes funcionalidades:
=======
	b) Dividir dois números Rational.
Adicione à classe anterior chamada Rational as seguintes funcionalidades:
>>>>>>> Stashed changes
	a)Imprimir os números Rational na forma a/b, onde a é o numerador e b é o denominador.
	b)Imprimir os números Rational em formato de ponto flutuante.
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
int main();///protótipo da função main()
class Rational{
    int numerador;
    int denominador;
    //Metodo para o cálculo do máximo divisor comum
    void mdc(Rational &);
public:
    //construtor padrão
    Rational();
    //o construtor  que recebe os argumentos do desenvolvedor
    Rational(int , int);
    //método que efetuar a multiplicação das frações
    Rational multiplicar(Rational, Rational);
    //método que efetuar a divisão das frações
    Rational dividir(Rational, Rational);
    //atribuir valores aos atributos da class
    void set_denominador(int );
    void set_numerador(int);
    //retorna o numerador
    int get_numerador(void);
    //retorna o denominador
    int get_denominador(void);
    //exibir as frações na notação usual
    void exibir(Rational, Rational, char);
    //exibir o resultado
    void exibir(void);
    //método para inverter o sinal
    void sinal();

};
Rational::Rational(){
    //atribuição por padrão 1 no numerador e 1 no denominador
    set_numerador(1);
    set_denominador(1);

}
Rational::Rational(int numerador, int denominador){
    //atribuir os valores que o desenvolvedor passou como argumentos da função aos atributos da class
    set_numerador(numerador);
    set_denominador(denominador);
}
<<<<<<< Updated upstream
Rational Rational::dividir(Rational f1, Rational f2){
    //instaciando o objeto que receberar o resultado da divisão de f1/f2
    Rational fr;
    //Cálculo da divisão
    fr.numerador = f1.numerador * f2.denominador;
    fr.denominador = f1.denominador * f2.numerador;
    //simplificando divisão
    mdc(fr);
    //retornando objeto
    fr.sinal();
    return fr;
}
Rational Rational::multiplicar(Rational f1, Rational f2){
    //instaciando o objeto que receberar o resultado da multiplicação de f1*f2
    Rational fr;
    //Cálculo
    fr.numerador =f1.numerador * f2.numerador;
    fr.denominador = f1.denominador * f2.denominador;
    //simplificando
    //e passando por refêrencia o Objeto para que não precise usar return
    mdc(fr);
    //retonando objeto
    fr.sinal();
    return fr;
=======
Rational Rational::Dividir(Rational F1, Rational F2){
    //Instaciando o objeto que receberar o resultado da divisão de f1/f2
    Rational FR;
    //Cálculo da divisão
    FR.numerador = F1.numerador * F2.denominador;
    FR.denominador = F1.denominador * F2.numerador;
    //simplificando divisão
    MDC(FR);
    //retornando objeto
    FR.sinal();
    return FR;
}
Rational Rational::Multiplicar(Rational F1, Rational F2){
    //Instaciando o objeto que receberar o resultado da multiplicação de f1*f2
    Rational FR;
    //Cálculo
    FR.numerador = F1.numerador * F2.numerador;
    FR.denominador = F1.denominador * F2.denominador;
    //simplificando
    //e passando por refêrencia o Objeto para que não precise usar return
    MDC(FR);
    //retonando objeto
    FR.sinal();
    return FR;
>>>>>>> Stashed changes
}
void Rational::set_numerador(int numerador){
    //atribuindo valores ao atributo da class
    this->numerador = numerador;
}
void Rational::set_denominador(int denominador){
    //atribuindo valores ao atributo da class
    //caso o denominado informando pelo usuário seja igual a zero o usuário recebe a mensagem
    //"Fracoes invalido informe numeros diferente de zero"
    if(not(denominador) and not(numerador)){
        cout<<"Fracoes invalido informe numeros diferente de zero"<<endl;
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
void Rational::MDC(Rational &fr){
    //usando o algoritmo de Euclides para determinar o mdc
    int numAux = fr.numerador;
    int denAux = fr.denominador;
    while(denAux != 0){
        int temp = numAux % denAux;
        numAux = denAux;
        denAux = temp;
    }
    //como estou acessando diretamente o endereço da variável FR não preciso usar return
   fr.numerador /= numAux;
   fr.denominador /= numAux;
}
void Rational::exibir(Rational F1, Rational F2, char sinal){
    //Exibindo a fração
    cout<<"("<<F1.numerador<<" / "<<F1.denominador<<") "<<sinal<<" ("<<F2.numerador<<" / "<<F2.denominador<<") = ";
}
void Rational::exibir(void){
    //precisão 2 casas decimais após a vírgula
    cout.precision(2);
    //exibindo o resultado
    cout<<"("<<numerador<<" / "<<denominador<<")";
    //Mostrando ponto flutuante
    cout<<endl<<"Ponto flutuante: "
        <<fixed<<(double)numerador/denominador<<endl;

}
void Rational::sinal(){
    //invertendo o sinal do resultado caso o denominador seja negativo
    if(denominador < 0){
        numerador*=-1;
        denominador*=-1;
    }
}
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
        f1.exibir(f1,f2,oper);
        fr = f1.dividir(f1,f2);
    }else if(oper == '*'){
        //caso o usuário informe o caracter '*' ele deseja  efetuar a multiplicação de frações
        f1.exibir(f1,f2,oper);
        fr =  f1.multiplicar(f1,f2);
    }
    //exibindo resultado
<<<<<<< Updated upstream
    fr.exibir();
=======
    FR.Exibir();
>>>>>>> Stashed changes
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
