/***************
*  Aluno: Arthur Henrique R. Alves           *
*  Matrícula: 119211079                      *
*  Unidade 3:Laboratório 7.                  *
*  Professor: Marcus Salerno                 *
****************/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale>
using namespace std;

class Televisao{
private:
    int vol;//vol de volume, atributo que servirá como tecla/botão controlador para aumenta ou diminuir volume.
    int can;//can de canal, atributo que servirá como telca/botão para mudar de canal
public:
    Televisao();//Declarando o construtor
    void setvol(int);
    void setcan(int);
    int getvol();
    int getcan();
    int aumenta_volume();//Método aumenta volume
    int diminui_volume();//Método diminui volume
    int aumenta_canal();//Método aumenta canal
    int diminui_canal();//Método diminui canal
    // void troca_canal();//Método troca canal
    void volume_canalatual();//Método para informar o número do canal atual e o volume atual
    int Menu();//Método para Menu.
};
Televisao::Televisao(){
    vol=0;//Número mínimo do som
    can=1;//Número mínimo de canais
}
//  SETTERS
void Televisao::setvol(int vol ){//Serve para você passar/atribui um valor para uma variável privado da classe no qual você não tem acesso
    this-> vol = vol ;//Faz com que o parametro e o atributo sejam diferenciados.
}
void Televisao::setcan(int can ){
    this-> can = can ;
}
// GETTERS
int Televisao::getvol(){//Get serve para você retornar o valor de do atributo atribuido ao set.
    return getvol();
}
int Televisao::getcan(){
    return getcan();
}
int Televisao::aumenta_volume(){
    int max=100,cont=0;
    int v, va;//variável para a variação do volume
    cout << "Qual o volume atual?" << endl;
    cin >> va;//recebe o volume atual, será somado com a quantidade de unidades de volume dadas pelo usuário
    cout << "Pressione (1) para cada uma unidade de volume que você deseja aumentar e qualquer outro número para permanecer no volume somado" << endl;
    for (int i=0;i<=100; i++){
        cin >> v;
        if(v == 1){
            cont+=1;
            if(cont==max){
                cout << "Você está no volume 100 e este é o máximo." << endl;
                break;
            }
        }else{
            cont+=va;
            cout << "Você chegou até o volume " << cont << endl;//imprime o atual número do volume após o acréscimo
        }
    }
}
int Televisao::diminui_volume(){
    int min=0;
    int v, va;//variável para a variação do volume
    cout << "Qual o volume atual?" << endl;
    cin >> va;//recebe o valor atual que será subtraido
    cout << "Pressione (2) para cada uma unidade de volume que você deseja diminuir e qualquer outro número para permanecer no volume subtraido." << endl;
    for (int i=100;i>=0; i--){
        cin >> v;
        if(v == 2){
            va-=1;
            if(va==min){
                cout << "Você está no volume 0 e este é o minimo." << endl;
                break;
            }
        }else{
            if(va<0) break;
            cout << "Você chegou até o volume " << va << endl;//imprime o atual número do volume após o decréscimo
        }
    }
}
int Televisao::aumenta_canal(){
    int max=30,cont=0;
    int c, can;//variável para a variação do volume
    cout << "Qual o canal atual?" << endl;
    cin >> can;//recebe o canal atual, será somado com a quantidade de unidades de volume dadas pelo usuário
    cout << "Pressione (3) para cada uma unidade de canal que você deseja aumentar e qualquer outro número para permanecer no canal." << endl;
    for (int i=0;i<=100; i++){
        cin >> c;
        if(c == 3){
            cont+=1;
            if(cont==max){
                cout << "Você está no canal 30 e este é o último canal" << endl;
                break;
            }
        }else{
            cont+=can;
            cout << "O canal atual é " << cont << endl;//imprime o canal atual após o acréscimo
        }
    }
}
int Televisao::diminui_canal(){
    int min=1;
    int c, can;//variável para a variação do canal
    cout << "Qual o canal atual?" << endl;
    cin >> can;//recebe o valor atual que será subtraido
    cout << "Pressione (4) para cada uma unidade de volume que você deseja diminuir e qualquer outro número para permanecer no canal subtraido." << endl;
    for (int i=100;i>=0; i--){
        cin >> c;
        if(c == 4){
            can-=1;
            if(can==min){
                cout << "Você está no canal 1 e este é o primeiro canal" << endl;
                break;
            }
        }else{
            if(can<min) break;
            cout << "O canal agora é " << can << endl;//imprime o atual número do canal após o decréscimo
        }
    }
}
/*void Televisao::troca_canal(){
   int can,t;//c de canal, variável responsável por receber os valores par a mudança de canal
    cout << "Em que canal você está? " << endl;
    cin >> t;
    cout << "Digite o canal que você quer ir: " << endl;
    cin >> can;

    if (can <= getcan() && can > 0){
        setcan(can);
        cout << "Agora você está no canal " << t.getcan() << endl;
  }else{
        cout << "Canal inexistente." << endl;
  }
}*/
int main(){
    Televisao t;//objeto
    int d;//d de decisão
    int c,p;
    setlocale(LC_ALL, "portuguese");
    cout << "(1) Para aumentar o volume." << endl;
    cout << "(2) Para diminuir o volume"  << endl;
    cout << "(3) Para aumentar o canal" << endl;
    cout << "(4) Para diminuir o canal" << endl;
    cout << "(5) Para trocar de canal" << endl;
    cout << "(6) Finalizar" << endl;
    cin >> d;
    if(d == 1){
        t.aumenta_volume();
    } else if(d == 2){
        t.diminui_volume();
    } else if(d == 3){
        t.aumenta_canal();
    } else if(d == 4){
        t.diminui_canal();
    } else if(d == 5){
        cout << "Em que canal você está? " << endl;
        cin >> p;
        cout << "Digite o canal que você quer ir: " << endl;
        cin >> c;
        if (c <= t.getcan() && c > 0){
            t.setcan(c);
            cout << "Agora você está no canal " << t.getcan() << endl;
        }} else if(d==6){
        return 0;
    }

    return 0;
}