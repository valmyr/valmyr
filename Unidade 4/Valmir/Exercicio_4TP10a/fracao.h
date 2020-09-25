
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
	b) Dividir dois números Rational. Adicione à classe anterior chamada Rational as
seguintes funcionalidades:
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
#ifndef _FRACAO_H
#define _FRACAO_H
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
#endif //_FRACAO_H
