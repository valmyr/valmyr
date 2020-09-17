#include<iostream>
#include<stdlib.h>
using namespace std;
class Alunos{
public:
    void get_Nome(string Nome);
    string set_nome();

    void get_Matricula(int Matricula);
    int set_Matricula();

    void get_Notas(float *Notas);
    float *set_Notas();

private:
    string Nome;
    int Matricula;
    float *Notas;
};
void Alunos::get_Nome(string Nome){
    this -> Nome = Nome;
}
string Alunos::set_nome(){
    return Nome;
}
void Alunos::get_Matricula(int Matricula){
    this -> Matricula = Matricula;
}
int Alunos::set_Matricula() {
    return Matricula;
}
void Alunos::get_Notas(float *Notas) {
    this -> Notas = Notas;
}
float *Alunos::set_Notas() {
    return Notas;
}

int main(){
    struct Alunos *Dados;
    Dados = (Alunos *)malloc(sizeof(struct Alunos)*2);
    string Nomes;
    float *Notas;
    int Matricula;
    int q_notas;
    cout<<"Entradas...\n";
    for(int i = 0; i < 2; i++){
        cout <<"Informe o nome ["<<i+1<<"] >>";
        getline(cin,Nomes);
        Dados[i].get_Nome(Nomes) ;
        cout<<"Informe a matricula ["<<i+1<<"] >>";
        cin >>Matricula;
        Dados[i].get_Matricula(Matricula);
        cout<<"Informe a quantidade de notas>>";
        cin >>q_notas;
        Notas = (float*)malloc(sizeof(float)*q_notas+1);
        cout<<"Informe as notas ["<<i+1<<"]:\n";
            for(int j = 0; j < q_notas-1; j++){
                cout<<"Nota["<<i+1<<"]x["<<j<<"]>>";
                cin >>Notas[j];
                Notas[q_notas] += Notas[j];
            }
        Dados[i].get_Notas(Notas);
            fflush(stdin);
        cout<<"\n";
    }
    cout <<"Saidas...\n";
    for(int i = 0; i < 2; i++){
        cout<<"Aluno["<<i+1<<"]: "<<Dados[i].set_nome();
        cout<<"\nMatricula["<<i+1<<"]: "<<Dados[i].set_Matricula();
            for(int j = 0; j < q_notas - 1; j++){
                cout<<"\nNotas["<<i+1<<"]x["<<j+1<<"] = "<<Dados[i].set_Notas()[j];
            }
        cout<<"\nMedia["<<i+1<<"] = "<<Dados[i].set_Notas()[q_notas];
    }

}