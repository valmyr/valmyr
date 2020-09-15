/*
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
    Laboratório Virtual de Programação 01
Escreva um programa que crie uma estrutura chamada Ponto, contendo 
apenas a posição x e y (inteiros) do ponto. Declare 2 pontos, leia 
a posição (coordenadas x e y) de cada um e calcule a distância entre
eles. Apresente no final a distância entre os dois pontos, com uma 
precisão de duas casas decimais.
*/
#include<iostream>
#include<cmath>
using namespace std;
struct ponto{
    int x, y;
};
float dist(ponto p1, ponto p2);
int main(){
    ponto c1, c2;
    cout.precision(2);
    cout<<"Informe as coordenadas: \n";
    cout<<"X1 >> ";
    cin>>c1.x;
    cout<<"X2 >> ";
    cin>>c2.x;
    cout<<"Y1 >> ";
    cin>>c1.y;
    cout<<"Y2 >> ";
    cin>>c2.y;
    cout<<fixed<<"A distancia entre os pontos digitados e "<<dist(c1, c2);
    return 0;
}

float dist(ponto p1, ponto p2){
    return (float)sqrt(pow(p1.x - p2.x, 2)+pow(p1.y - p2.y, 2));
}
