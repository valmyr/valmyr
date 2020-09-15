/*
Importante: Compilador usado Clion, C++17.
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
    Laboratório Virtual de Programação 04
Crie uma classe Retangulo a partir da qual apenas as coordenadas cartesianas dos vértices
de suas instâncias são armazenadas (pix,piy, psx,psy). Para simplificar, considere os valores
dos vértices apenas como atributos da classe. O construtor deve chamar uma função-membro
que receba tais coordenadas e verifique se todas elas se encontram no primeiro quadrante,
sem que nenhum dos valores de x ou y seja maior do que 15,0 (ou seja, os valores do primeiro
quadrante devem ser positivos e menores que 15). Considere que as coordenadas fornecidas de
fato  especificam um retângulo.

Também deverão ser definidas funções-membros para calcular o comprimento, a largura, o
perímetro e a área do retângulo. O comprimento deverá ser o maior das duas dimensões.
Incluir uma função-predicado (função que retorna verdadeiro ou falso, de acordo com uma
verificação) denominada ehQuadrado.
*/
#include<iostream>
#include <cmath>
int main();//Protótipo da função main
using namespace std;
class Retangulo{
    //Atributos da class
    int pix, piy, psx, psy;
    //O construtor deve chamar uma função membro que receba tais coordenadas
    bool checar(int pix, int piy, int psx, int psy) ;//Equivalente a função checar do modelo
public:
    //Função setValores do modelo
    void setValores(int pix, int piy, int psx, int psy);
    //Construtor
    Retangulo();
    //Função membro para o cálculo da área
    int area();
    //Função membro para o cálculo do perímetro
    int perimetro();
    //Função membro para o cálculo do comprimento lembrando que deve ser o maior dos lados
    int comprimento();
    //Função membro para o cálculo da largura lembrando que deve ser o menor lado
    int largura();
    //Função para verificar se as coordenadas formam um quadrado equilavente a função ehquadrado
    bool ehquadrado();
    //Função opcional verificar retângulo
    bool ehRetangulo();
    //Função para validamento de respostas
    void valid_Resp();

};
int Retangulo::area(){
//Cálculo da área largura * comprimento
    return comprimento() * largura();
}
int Retangulo::comprimento() {
    //necessário usar a função modulo da biblioteca cmath para o calculo
    //Verificando o maior lado
    if(fabs(pix - psx) > fabs(piy - psy))
        return (int)fabs(pix - psx);//a função fabs retorna um double e um cast se faz necessário para a conversão para int
    return (int)fabs(piy - psy);
}
int Retangulo::perimetro(){
    //Cálculo do perímetro
    return 2*(comprimento() + largura());
}
int Retangulo::largura() {
    //necessário usar a função modulo da biblioteca cmath para o cálculo
    //Verificando o menor lado
    if(fabs(pix - psx) > fabs(piy - psy))
        return (int)fabs(piy - psy);
    return (int)fabs(pix - psx);
}
bool Retangulo::ehquadrado(){
    //se o comprimento for igual a largura as coordenadas digitadas formam um quadrado
    if(comprimento() == largura())
        return true;
    return false;
}
bool Retangulo::checar(int pix, int piy, int psx, int psy) {
    //Verificando se as coordenadas estão no primeiro quadrante e são menores que 15
    //caso sejam maiores que 15 ou menores que 0 retornarei false informando que as coordenadas estão inválidas
    if(pix < 0 or pix >= 15)
        return false;
    if(psx < 0 or psx >= 15)
        return false;
    if(piy < 0 or piy >= 15)
        return false;
    if(psy < 0 or psy >= 15)
        return false;
    return true;
}
void Retangulo::setValores(int pix, int piy, int psx, int psy){
    if(checar(pix,piy,psx,psy)){
        //Caso as coordeadas estejam no primeiro quadrante e sejam menores que 15 atribuirei as coordenadas aos atributos da class
        this->pix = pix;
        this->piy = piy;
        this->psx = psx;
        this->psy = psy;
        //Se for um quadrado str recebe "formam um quadrado" caso contrário "formam um retangulo"
        string str = ehRetangulo() ? "retangulo" :"quadrado";
        cout<<"As coordenadas informadas formam um"<<str<<endl;
    }else{
        cout<<"Coordenadas invalidas"<<endl;
        cout<<"Tentar novamente[1]"<<endl<<"Sair[0]"<<endl;
        valid_Resp();
    }

}
Retangulo::Retangulo(){
    //Iniciando atributos class
    pix = psx = piy = psy = 0;
}
//Função para verifcar se e um retangulo
bool Retangulo::ehRetangulo() {
    //Variável dedicada ao calculo da diagonal/hipotenusa do quadrado ou retangulo
    float hip = sqrt(pow(comprimento(), 2) + pow(largura(), 2));
    //Variável deidicada ao calculo do angulo alpha = arcsin(comprimento/hipotenusa)
    float alpha = asin(comprimento() / hip);
    //conversao para angulo
    alpha *=180.0 / M_PI;
    //Variável dedicada ao angulo beta = arcsin(largura/hipotenusa)
    float beta = asin(largura() / hip);
    //convertendo para angulo
    beta *=180.0 / M_PI;
    // Se alpha + beta forem iguais a 90 as coordenadas podem forma um retangulo ou quandrado
    // porém esta função retornar true se for um retângulo
    //usando a função ceil para o arredondamento
    if(ceil(beta + alpha) == 90 and not ehquadrado())
        return true;
    return false;
}
void Retangulo::valid_Resp(){
    //Validando respostas  se estão entre 0 e 1 caso contrário o usuário tem que digitar novamente
    int op;cout<<">>";cin>>op;
    while(op<0 || op >1){
        cout<<"Opcao invalida"<<endl;
        cout<<"Tente novamente: ";
        cin>>op;
    }
    if(op)
        //Reiniciar programa
        main();
    //fechar
    return ;
}
int main(){
    //Instânciando um objeto da class retangulo
    Retangulo *r1 = new Retangulo;
    //Variaveis pix, psx, piy, psy
    int pix,psx,piy,psy;
    //Coletando infomações do usuário
    cout<<"pix >> ";cin >> pix;
    cout<<"piy >> ";cin >> piy;
    cout<<"psx >> ";cin >> psx;
    cout<<"psy >> ";cin >> psy;
    //Enviando informações para os atributos da class
    r1->setValores(pix,piy,psx,psy);
    //Mostrando comprimento é calculando
    cout<<"Comprimento: "<<r1->comprimento()<<endl;
    //Mostrando largura e calculando
    cout<<"Largura: "<<r1->largura()<<endl;
    //Mostrando Área e calculando
    cout<<"Area: "<<r1->area()<<endl;
    //Mostrando Perímetro e calculando
    cout<<"Perimetro: "<<r1->perimetro()<<endl;
    //Se o usuário informar 0 o programa fecha caso contrário reinicia
    cout<<"Sair[0]"<<endl<<"Continuar[1]"<<endl;
    //Validando resposta
    r1->valid_Resp();
    return 0;
}
