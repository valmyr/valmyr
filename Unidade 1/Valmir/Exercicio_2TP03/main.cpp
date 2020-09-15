  
/*
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
    Laboratório Virtual de Programação 03
        Escreva um programa que converte certa temperatura de graus Celsius para Fahrenheit e 
vice-versa, utilizando union. Crie uma union com os atributos Celsius e Fahrenheit 
(float). Pergunte ao usuário qual das conversões ele deseja fazer (se é de Celsius-Fahrenheit
ou Fahrenheit-Celsius), dependendo de sua resposta, insira o valor para a conversão e imprima 
o resultado convertido com aproximação de duas casas decimais.
*/
#include <iostream>
using namespace std;
union conversao{
    float Celsius;
    float Fahrenheit;
};
float Celsius2Fahrenheit(conversao d);
float Fahrenheit2Celsius(conversao d);
int main(){
    conversao dados;
    cout.precision(2);
    int op;
    while(true){
        cout<<"[1] Celsius-Fahrenheit\n[2] Fahrenheit-Celsius\n";
        cin>>op;
        if(op > 0 && op < 3)break;
    }
    if(op == 1){
        cin>>dados.Celsius;
        cout<<fixed<<Celsius2Fahrenheit(dados);
    }else{
        cin>>dados.Fahrenheit;
        cout<<fixed<<Fahrenheit2Celsius(dados);
    }
}
float Celsius2Fahrenheit(conversao d){
    return (d.Celsius*9/5)+32;
}
float Fahrenheit2Celsius(conversao d){
    return (d.Fahrenheit - 32)*5/9;
}
