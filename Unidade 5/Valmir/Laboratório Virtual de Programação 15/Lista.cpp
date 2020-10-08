//
// Created by valmyr on 01/10/2020.
//
#include "./Lista.h"
//iniciando atributo estático
int Lista::dNomes = 0;
Lista::Lista(){
    sizeL = 1;
    listaNomes = (string *)new string[sizeL];
}
Lista::Lista(int sizeL){
    this->sizeL = sizeL;
    //chamando a função para alocar a lista
    alocarLista();
}
void Lista::alocarLista(){
    //alocando a lista de nomes
    listaNomes = (string *) new string[sizeL];
}
//set do atributos sizeL
void Lista::setsizeL(int sizeL) {
    this->sizeL = sizeL;
    //chamando a função para alocar a lista
    alocarLista();
}
//get dNomes retorna a quantidade atual de nomes na lista
int Lista::getdNomes(){
    return dNomes;
}
//adiciona um nome a lista
bool Lista::inserirNome(string Nome) {
    //se dNomes == sizeL a lista esta cheia e o nome não e  adicionado a lista
    if(dNomes >= sizeL){
        cout<<"Lista cheia"<<endl;
        //retornando falso informando que o nome não foi adicionando a lista
        return false;
    }
    //caso contrário o nome e adicionado
    //variável auxiliar que tem como função preserva o primeiro endereço
    static string *auxTemp = (string *)listaNomes;
    *(auxTemp++) = Nome;
    //convertendo a primeira letra do nome para maiúsculo
    tratamentoNomes();
    //incrementando a quantidade atual de nomes
    dNomes++;
    //retornando verdadeiro informando que o nome foi adicionando com sucesso
    return true;
}
//mostra os nomes na tela
void Lista::imprimirLista() const {
    //caracter de preenchimento para a formatação dos indeces
    cout.fill('0');
    //se dNomes for igual a zero isso significa que a lista esta vazia
    if(dNomes == 0){
        cout<<"Lista vazia"<<endl;
        //sair da função
        return;
    }
    //caso contário mostra a listaa de nomes
    for(int i = 0; i < dNomes; i++)
        cout<<"["<<setw(2)<<i+1<<"] "<< listaNomes[i]<<endl;
}
//função responsável pela ordenação dos nomes
void Lista::ordenarNomes(){

    for(int i = 0; i < dNomes; i++){
        for(int j = i+1;j < dNomes; j++){
            //aplicação do algoritmo bubble sort para ordenação de caracteres.
            if(listaNomes[i][0] > listaNomes[j][0]){
                string tempNome = listaNomes[j];
                listaNomes[j]= listaNomes[i];
                listaNomes[i] = tempNome;
            }
        }
    }
}
void Lista::tratamentoNomes(){
    //converte a primeira letra de cada nome para maiúscula
    listaNomes[dNomes][0] = toupper((char)listaNomes[dNomes][0]);
}
int Lista::menu(){
    //interação com o usuário menu
    int op;
    cout.fill('=');
    cout<<setw(40)<<" "<<endl;
    cout.fill(' ');
    cout<<setw(20)<<"DESEJA"<<endl;
    cout.fill('=');
    cout<<setw(40)<<" "<<endl;
    //opção para adiconar nomes
    cout<<"[1] Adicionar"<<endl;
    //opção para imprimir nomes
    cout<<"[2] Imprimir"<<endl;
    //opção para ordenação nomes    cout<<"[3] Ordenar"<<endl;
    //opção para imprimir o total de nomes atualmente na lista
    cout<<"[4] Total"<<endl;
    //opção para limpar a tela
    cout<<"[5] limpar tela"<<endl;
    //fechar o programa
    cout<<"[6] Sair"<<endl;
    cout<<setw(40)<<" "<<endl;
    cin>>op;
    //valida as resposta dentro do limite de opções
    validarRespostas(op);
    //limpar a tela
    system("cls");
    //retorna a opção escolhida
    return op;
}
void Lista::validarRespostas(int &op) {
    //valida as resposta dentro do limite de opções
    while(op > 6 or op < 1){
        //caso a opção informanda seja maior que 6 ou menor que um o usuário recebe a mensagem que a opção e invalida
        cout<<"Opcao invalida: ";
        //é ele precisa informa uma nova opçãpara continuar
        cin>>op;
    }
}
Lista::~Lista(){
    //destruindo objeto lista e desalocando memória da heap
   	delete listaNomes;
}
