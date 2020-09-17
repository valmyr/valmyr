#include<iostream>
#include <cmath>
int main();//protótipo a função main
using namespace std;
class Retangulo{
    int x1, y1, x2, y2;
    //O construtor deve chamar uma função membro que receba tais coordenadas
    bool verificar_Coordenadas(int x1, int y1, int x2, int y2) ;//Equivalente a função checar do modelo
public:
    //função setValores do modelo
    setValores(int x1, int y1, int x2, int y2);
    Retangulo();
    //função membro para o calculo da área
    int area();
    //função membro para o calculo do perímetro
    int perimetro();
    //função membro para o calculo do comprimento lembrando que deve ser o maior dos lados
    int comprimento();
    //função membro para o calculo da largura lembrando que deve ser o menor lado
    int largura();
    //função para verificar se as coordenas formam um quadrado equilavente a função ehQuadrado
    bool verificar_Quadrado();
    //função opcional verificar retangulo
    bool verificar_Retangulo();
    //função para validamento de respostas
    void valid_Resp(void);

};
int Retangulo::area(){
    return comprimento() * largura();
}
int Retangulo::comprimento() {
    //necessário usar a função modulo da biblioteca cmath para o calculo
    //Verificando o maior lado
    if(fabs(x1 - x2) > fabs(y1 - y2))
        return (int)fabs(x1 - x2);//a função fabs retorna um double e um cast se faz necessário para a conversão para int
    return (int)fabs(y1 - y2);
}
int Retangulo::perimetro(){
    return 2*(comprimento() + largura());
}
int Retangulo::largura() {
    if(fabs(x1 - x2) > fabs(y1 - y2))
        return (int)fabs(y1 - y2);
    return (int)fabs(x1 - x2);
}
bool Retangulo::verificar_Quadrado(){
    //se o comprimento for igual a largura as coordenadas digitadas formam um quadrado

    if(comprimento() == largura())
        return true;
    return false;
}
bool Retangulo::verificar_Coordenadas(int x1, int y1, int x2, int y2) {
    bool opcao = true;
    //Verificando se as coordenadas estão no primeiro quadrante e são menores que 15
    //caso sejam maiores que 15 ou menores que zero irei retorna false informando que as coordenadas estão invalidas
    if(x1 < 0 or x1 >= 15)
        opcao = false;
    if(x2 < 0 or x2 >= 15)
        opcao = false;
    if(y1 < 0 or y1 >= 15)
        opcao = false;
    if(y2 < 0 or y2 >= 15)
        opcao = false;
    return opcao;
}
Retangulo::setValores(int x1, int y1, int x2, int y2){
    int op;//opção
    if(verificar_Coordenadas(x1,y1,x2,y2)){
        //caso as coordeadas estejam no primeiro quadrante e sejam menores que 15 atribuirei as coordenadas aos atributos da class
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        string str = verificar_Retangulo() ? "formam um retangulo" : verificar_Quadrado() ? "formam um quadrado": "não formam nem um quadrado nem um retangulo";
        cout<<"As coordenadas informadas "<<str;cout<<endl;
    }else{
        cout<<"Coordenadas invalidas\n";
        cout<<"Tentar novamente[1]\nSair[0]\n";
        valid_Resp();
    }

}
Retangulo::Retangulo(){
    x1 = x2 = y1 = y2 = 0;
}
bool Retangulo::verificar_Retangulo() {
    //Primeiro metodo que pensei
    //Variável dedicada ao calculo da diagonal/hipotenusa do quadrado ou retangulo
    float hip = sqrt(pow(comprimento(), 2) + pow(largura(), 2));
    //Variável deidicada ao calculo do angulo alpha = arcsin(comprimento/hipotenusa)
    float alpha = asin(comprimento() / hip);
    //conversao para angulo
    alpha = alpha * 180.0 / M_PI;
    //Variável dedicada ao angulo beta = arcsin(largura/hipotenusa)
    float beta = asin(largura() / hip);
    //convertendo para angulo
    beta = beta * 180.0 / M_PI;
    // Se alpha + beta forem iguais a 90 as coordenadas podem forma um retangulo ou quandrado
    // porém esta função so vai retornar true se for um retangulo
    if(ceil(beta + alpha) == 90 and not verificar_Quadrado())
        return true;
    return false;
}
void Retangulo::valid_Resp(void){
    int op;cout<<">>";cin>>op;
    while(op<0 || op >1){
        cout<<"Opcao invalida";
        cout<<"Tente novamente: ";
        cin>>op;
    }
    if(op)
        main();
    return ;
}
int main(){
    Retangulo *r1 = new Retangulo;
    int x1,x2,y1,y2;
    cout<<"x1 >> ";cin >> x1;
    cout<<"y1 >> ";cin >> y1;
    cout<<"x2 >> ";cin >> x2;
    cout<<"y2 >> ";cin >> y2;
    r1->setValores(x1,y1,x2,y2);
    cout<<"Comprimento: "<<r1->comprimento()<<endl;
    cout<<"Largura: "<<r1->largura()<<endl;
    cout<<"Area: "<<r1->area()<<endl;
    cout<<"Perimetro: "<<r1->perimetro()<<endl;
    cout<<"Sair[0]\nContinuar[1]\n";
    r1->valid_Resp();



    return 0;
}