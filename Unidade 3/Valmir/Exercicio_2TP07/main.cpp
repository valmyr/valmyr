/*
Importante: Compilador usado Clion, C++17.
Sistema Operacional: Windowns 10
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
Professor: Marcus Salerno

    Laboratório Virtual de Programação 07
	Implemente uma televisão. A televisão tem um controle de volume do som e um controle 
de seleção de canal. O controle de volume permite aumentar ou diminuir a potência do
volume de som em uma unidade de cada vez. O controle de canal também permite aumentar
e diminuir o número do canal em uma unidade, porém, também possibilita trocar para um
canal indicado. Lembrem-se de verificar o limite (superior e inferior) do som e do canal.
Também devem existir métodos para consultar o valor do volume de som e o canal selecionado.
	Pelas informações fornecidas no problema, os métodos a serem definidos são:
- Um construtor que inicializa (por default) o volume e o canal da TV
- Um método para aumentar o volume e um método para abaixar o volume
- Um método para aumentar o número do canal e outro método para diminuir
- Um método para trocar de canal
- Um método para informar o número do canal atual e o volume atual
No programa principal, crie um objeto televisão. Você pode usar um menu para selecionar as 
opções do usuário. 

Faça alguns testes para verificar se o programa está funcionando corretamente. Não esqueça de
 testar os limites. Lembre-se, o método não irá fazer nada se o valor já estiver no limite. 
*/
#include <iostream>
#include<iomanip>
using namespace std;
//Class
class Televisao{
private:
    //limite de canais
    int cmaximo;
    //limte de volume
    int vmaximo;
    //número volume
    int volume;
    //número canais
    int canal;
public:
    //construtor sobrecarregado
    //inicializa os valores por padrão
    Televisao();
    //inicializa os valores dos atributos com os valore que o desenvolvedor informou
    Televisao(int, int, int, int);
    //atribuindo ao atributo volume da class o valor passado por paramêtro 
    void set_volume(int );
    //atribuindo ao atributo canal da class o valor passado por paramêtro 
    void set_canal(int );
    // retorna o valor do atributo volume
    int get_volume();
    // retorna o valor do atributo canal
    int get_canal();
    //atribuindo ao atributo vmaximo da class o valor passado por paramêtro 
    void set_vmaximo(int vmaximo);
    //atribuindo ao atributo cmaximo da class o valor passado por paramêtro 
    void set_cmaximo(int cmaximo);
    //Método responsável pelo aumento do volume
    void aumenta_volume();
    //Método responsável pelo diminuição  do volume
    void diminuir_volume();
    //Método responsável pela troca de canais
    void trocar_de_canal(int canal);
    //Método responsável pela troca de canais
    void proximo_de_canal();
    //Método responsável pela troca de canais
    void anterior_de_canal();
    //Método que valida as respostas do menu
    void val_resp(int &);
    //Método responsável pela interação com o usuário
    int menu();
};
Televisao::Televisao() {
    //por padrão o volume e o canal e iniciado em 1
    set_canal(1);
    set_volume(1);
}
Televisao::Televisao(int volume, int canal, int vmaximo, int cmaximo) {
    //atribuindo os valores recebidos aos atributos
    set_canal(canal);
    set_volume(volume);
    set_cmaximo(cmaximo);
    set_vmaximo(vmaximo);
}
void Televisao::set_vmaximo(int vmaximo) {
    //atribuindo o valor passado por paramêntro ao atributo da class
    this->vmaximo = vmaximo;
}
void Televisao::set_canal(int canal) {
    //atribuindo o valor passado por paramêntro ao atributo da class
    this->canal = canal;
}
void Televisao::set_volume(int volume) {
    //atribuindo o valor passado por paramêntro ao atributo da class
    this->volume = volume;
}
int Televisao::get_canal(){
    //retornando o canal atual
    return canal;
}
int Televisao::get_volume() {
    //retornando o volume atual
    return volume;
}
void Televisao::set_cmaximo(int cmaximo){
    //atribuindo o valor passado por paramêntro ao atributo da class
    this->cmaximo = cmaximo;
}
void Televisao::aumenta_volume() {
    //Se o volume for maior que o volume maximo o usuário receber a mensagem "Ops, Volume maximo."
    //e o programa faz uma pausa
    if(volume >= vmaximo){
        cout<<"Ops, Volume maximo."<<endl;
        system("pause");
        return;
    }
    //caso contrário o volume e incrementado em uma unidade
    ++volume;
}
void Televisao::diminuir_volume() {
    //se o volume for menor ou igual a zero o usuário recebe a mensagem "Ops, Volume minimo."
    //e o programa faz uma pausa
    if(volume <= 0){
        cout<<"Ops, Volume minimo."<<endl;
        system("pause");
        return;
    }
    //caso contrário o volume e decrementado em uma unidade
    --volume;
}
void Televisao::proximo_de_canal() {
    // se o número de canais for maior ou igual a limite de canais o usuário recebe a mensagem "Esse canal nao existe"
    //e o programa faz uma pausa
    if(canal >= cmaximo){
        cout<<"Esse canal nao existe"<<endl;
        system("pause");
        return;
    }
    //caso contrário o número de canais e incrementado em uma unidade
    ++canal;
}
void Televisao::anterior_de_canal() {
    // se o número de canais for menor ou igual a zero  o usuário recebe a mensagem "Esse canal nao existe"
    //e o programa faz uma pausa
    if(canal <= 0){
        cout<<"Esse canal nao existe"<<endl;
        system("pause");
        return;
    }
    //caso contrário o número de canais e decrementado em uma unidade
    --canal;
}
void Televisao::trocar_de_canal(int canal) {
    //Se o canal informado pelo usuário for maior ou igual limite de volume o usuário recebe a mensagem "Esse canal nao existe"
    if(canal >= cmaximo){
        cout<<"Esse canal nao existe"<<endl;
        system("pause");
        return;
    }
    //Caso contrário  o canal informado e a tribuido ao atributo da class
    set_canal(canal);
}
int Televisao:: menu(){
    //Variável responsável pelo recebimento da opção escolhida pelo o usuário
    int op;
    //Caracter a ser repetido
    cout.fill('=');
    //o caracter será repetido 60 vezes na tela do usuário
    cout<<setw(60)<<" "<<endl;
    cout.fill(' ');
    cout<<setw(30)<<"DESEJA"<<endl;
    cout.fill('=');
    cout<<setw(60)<<" "<<endl;
    //Tenário responsável pela atualização das opções do menu
    (canal+1 <= cmaximo)? cout<<"[1] Proximo Canal"<<endl:cout<<"";
    (canal != 0)? cout<<"[2] Canal Anterior"<<endl: cout<<"";
    cout.fill(' ');
    cout<<"[3] Canal "<<setw(28)<<"Volume: "<<get_volume()<<endl;
    (volume+1 <= vmaximo)? cout<<"[4] Aumetar Volume": cout<<setw(17)<<"";cout<<setw(19)<<"Canal: "<<get_canal()<<endl;
    (volume != 0)?cout<<"[5] Diminuir Volume"<<endl:cout<<"";
    cout<<"[6] Desligar"<<endl;
    cout.fill('=');
    cout<<setw(60)<<" "<<endl;
    cin>>op;
    //Validador de respostas caso o usuário informe uma opção invalida nessa propria função o valor e alterado e atualidado
    // na função menu pois estou passando a variável op por referência
    val_resp(op);
    //retornando a opção informada
    return op;
}
void Televisao::val_resp(int &op){
    //como a função val_resp recebe o endereço da varável passada por paramêtro se modificarmos nesta
    // função o valor de op o valor e alterado na função em que val_resp foi chamada
    while(op > 6 or op < 1){
        //caso o usuário informe um número maior que 6 ou menor que zero ele recebera a mensagem "Informe uma opcao valida: "
        cout<<"Informe uma opcao valida: ";
        cin>>op;
    }
}
int main() {
    //instânciando um objeto da class Televisão
    //este objeto será iniciado: Volume = 0, canal = 1, Vmaximo = 15 e Cmaximo = 15
    Televisao t1(0,1,15,15);
    while(true) {
        //op recebe a opção informada pelo o usuário
        int op = t1.menu(), canal;
        //se op for menor 6 o usuário escolheu um opção diferente de desligar
        if (op < 6) {
            switch (op) {
                case 1:
                    //Caso o usuário informe 1 ele escolheu ir para o próximo canal
                    t1.proximo_de_canal();
                    break;
                    //Caso o usuário informe 2 ele escolheu ir para o canal anterior canal
                case 2:
                    t1.anterior_de_canal();
                    break;
                case 3:
                    //Caso o usuário informe 3 ele escolheu informa um canal
                    cout << "Informe um canal: " << endl;
                    cin >> canal;
                    t1.trocar_de_canal(canal);
                    break;
                case 4:
                    //Caso o usuário informe 4 ele escolheu aumentar o volume
                    t1.aumenta_volume();
                    break;
                case 5:
                    //Caso o usuário informe 4 ele escolheu aumentar o diminuir o volume
                    t1.diminuir_volume();
                    break;
                default:
                    cout << "Teste";
                    break;
            }
        } else
            //caso o usuário informe 6 o programa e finalizado
            return 0;
        //Limpando a tela
	//No windows o comando que limpa a tela do prompt de 
	//comando e o cls no linux o comando que limpa a tela do terminal e clear
        system("CLS");
    }
}
