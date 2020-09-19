#include<iostream>
#include<iomanip>
#include <cstdlib>
/*
Importante: Compilador usado Clion, C++17.
Sistema Operacional: Windowns 10
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
Professor: Marcus Salerno

    Laboratório Virtual de Programação 08
Crie uma classe denominada Elevador para armazenar as informações de um elevador dentro
de um prédio. Utilizando o Construtor, a classe deve armazenar o andar atual (0=térreo),
total de andares no prédio, excluindo o térreo, capacidade do elevador, e quantas pessoas
estão presentes nele.
A classe deve também disponibilizar os seguintes métodos:
·  inicializa: que deve receber como parâmetros a capacidade do elevador e o total de andares
no prédio (os elevadores sempre começam no térreo e vazios);
·  entra: para acrescentar uma pessoa no elevador (só deve acrescentar se ainda houver espaço);
·  sai: para remover uma pessoa do elevador (só deve remover se houver alguém dentro dele);
·  sobe: para subir um andar (não deve subir se já estiver no último andar);
·  desce: para descer um andar (não deve descer se já estiver no térreo);
.  set....: métodos para alterar cada um dos os dados armazenados.

*/
using namespace std;
//class
class Elevador{
private:
    //andar atual
    int andar_atual;
    //terreo
    int terreo;
    //total de andares
    int total_andares;
    //capacidade do elevador
    int capacidade;
    //quantidade atual de pessoas
    int q_pessoas;
public:
    //construtores sobrecarregados
    //construtor padrão
    Elevador();
    //construtor que recebe parametros do desenvolvedor
    Elevador(int, int, int, int);
    //atribuir o andar atual ao atributo da class
    void set_andar_atual(int);
    void set_terreo(int);
    //atribuir a quantidade de andares do prédio ao atributo da class
    void set_total_andares(int);
    //atribuir a capacidade de pessoas que o elevador suporta
    void set_capacidade(int);
    //atribuir a quantidade atual de pessoas no elevador
    void set_q_pessoas(int);

    //retorna o andar atual da class
    int get_andar_atual();
    //retorna o valor do térreo
    int get_terreo();
    //retorna o total de andares
    int get_total_andares();
    //retorna a capacidade do elevador
    int get_capacidade();
    //retorna a quantidade de pessoas atualmente no elevador
    int get_q_pessoas();

    //método entrar
    void entrar();
    //método sair
    void sair();
    //método subir
    void subir();
    //método descer
    void desce();

    //interação com o usuário
    int menu();
    //validar resposta
    void valrespo(int &);

};
Elevador::Elevador(){
    //Todos os valores são iniciados por padrão em zero
    set_andar_atual(0);
    set_terreo(0);
    set_total_andares(0);
    set_capacidade(0);
    set_q_pessoas(0);
}
int Elevador::get_andar_atual(){
    //retorna o andar atual
    return andar_atual;
}
int Elevador::get_terreo() {
    //retorna o terreo
    return terreo;
}
int Elevador::get_total_andares(){
    //retorna o total de andares
    return total_andares;
}
int Elevador::get_capacidade() {
    //retorna a capacidade do elevador
    return capacidade;
}
int Elevador::get_q_pessoas(){
    //retorna a quantidade de pessoas que estão no elevador
    return q_pessoas;
}
Elevador::Elevador(int andar_atual, int capacidade, int total_andares, int q_pessoas){
    //atribuindo os valores ao construtor
    set_andar_atual(andar_atual);
    set_capacidade(capacidade);
    set_total_andares(total_andares);
    set_q_pessoas(q_pessoas);
    set_terreo(0);
}
void Elevador::set_andar_atual(int andar_atual){
    //atribuindo os valores ao atributo da class
    this->andar_atual = andar_atual;
}
void Elevador::set_terreo(int terreo){
    //atribuindo os valores ao atributo da class
    this->terreo = terreo;
}
void Elevador::set_total_andares(int total_andares){
    //atribuindo os valores ao atributo da class
    this->total_andares = total_andares;
}
void Elevador::set_capacidade(int capacidade){
    //atribuindo os valores ao atributo da class
    this->capacidade = capacidade;
}
void Elevador::set_q_pessoas(int q_pessoas){
    //atribuindo os valores ao atributo da class
    this->q_pessoas = q_pessoas;
}
void Elevador::entrar(){
    //caso q_pessoas seja maior ou igual a capacidade o usuário recebe a mensagem "Ops, atingiu o limite da capacidade."
    //e o programa pausa
    if(q_pessoas >= capacidade) {
        cout << "Ops, atingiu o limite da capacidade." << endl;
        set_capacidade(capacidade);
        system("pause");
        return;
    }
    //caso contrário a quantidade de pessoas e incrementado em uma unidade
    ++q_pessoas;
}
void Elevador::sair(){
    //caso q_pessoas seja  menor ou igual a zero o usuário recebe a mensagem "Ops, o elevador esta vazio."
    //e o programa pausado
    if(q_pessoas <= 0){
        cout<<"Ops, o elevador esta vazio."<<endl;
        set_q_pessoas(0);
        system("pause");
        return ;
    }
    //caso contrário a quantidade de pessoas e decrementado uma unidade
    --q_pessoas;
}
void Elevador::subir(){
    //caso o andar atual seja maior ou igual ao total de andares o usuário recebe a mensagem "Ops, voce ja esta no ultimo andar."
    //e o programa e pausado
    if(andar_atual >= total_andares){
        cout<<"Ops, voce ja esta no ultimo andar."<<endl;
        set_andar_atual(andar_atual);
        system("pause");
    }
    //caso contrário a quantidade de andares e incrementado uma unidade
    ++andar_atual;
}
void Elevador::desce(){
    //caso o andar atual seja menor ou igual ao térreo o usuário recebe a mensagem "Ops, voce ja esta no terreo."
    if(andar_atual <= terreo) {
        cout << "Ops, voce ja esta no terreo." << endl;
        system("pause");
        set_andar_atual(terreo);
        return ;
    }
    //caso contrário decrementa do andar atual
    --andar_atual;
}
int Elevador::menu() {
    //variável que recebe a opção informada pelo usuário
    int op;
    //Caracter que vai ser repetido usando os setw
    cout.fill('=');
    //o caracter = vai se repetir 80 vezes
    cout<<setw(80)<<" ";
    cout.fill(' ');
    //imprimindo 40 espaços
    cout<<setw(40)<<endl<<"DESEJA";
    cout.fill('=');
    //o caracter = vai se repetir 80 vezes
    cout<<endl<<setw(80)<<" "<<endl;
    //ternário responsável pela a atualização do menu
    //opções
    (q_pessoas < capacidade)? cout<<"[1] entrarr || ": cout<<" ";
    (q_pessoas > 0)? cout<<"[2] Sair || ":cout<<" ";
    (andar_atual < total_andares)? cout<<"[3] Subir || ": cout<<" ";
    (andar_atual >  terreo)? cout<<"[4] Descer || ": cout<<" ";
    cout<<"[5] Fechar||";
    cout<<endl;
    cout<<setw(80)<<" "<<endl;
    cout<<">> ";
    cin>>op;
    //validando respostas
    // passagem de paramêtros por referencia ou seja se modificarmos o valor na função validar resposta aqui na fução menu e alterado também
    valrespo(op);
    //retornando a opção informada
    return op;
}

void Elevador::valrespo(int &op){
    //se op for menor que 1 ou op maior a opção e considerada invalida e o usuário recebe uma mensagem
    //"Opcão invalida" e "Informe uma opcao valida: "
    while(op < 1 || op > 4){
        cout<<"Opcão invalida"<<endl;
        cout<<"Informe uma opcao valida: ";
        cin>>op;
    }
}
int main() {
    //Instanciando objeto da class Elevador
    //andar_atual = 3, capacidade = 6, total_andares = 7, q_pessoas = 1;
    Elevador el1(3,6,7,1);
    //variável que recebe o valor informando pelo o usuário
    int op;
    while(true){
        //Mostrando o andar atual e a quantidade atual de pessoas no elevado
        cout<<"Andar Atual: "<<el1.get_andar_atual()<<
            endl<<"Quantidade de Pessoas: "<<el1.get_q_pessoas()<<
            endl;
        op = el1.menu();
        if(op < 5) {
            //se op for menor que 5 o usuário informou um opção diferente de fechar
            switch (op) {
                case 1:
                    //Caso o usuário escolha 1 ele entrar no elevador
                    el1.entrar();
                    break;
                case 2:
                    //Caso o usuário escolha 2 ele sairá no elevador
                    el1.sair();
                    break;
                case 3:
                    //Caso o usuário escolha 3 ele vai subir um andar
                    el1.subir();
                    break;
                case 4:
                    //caso o usuário escolha 4 ele vai descer um andar
                    el1.desce();
                default: ;

            }
        }else if(op > 4){
            //caso o usuário informou 5 ele optou por fechar o programa
            return 0;
        }
        //Limpando a tela
        //No windows o comando que limpa a tela do prompt de
        //comando e o cls no linux o comando que limpa a tela do terminal e clear
        system("CLS");
    }
}
