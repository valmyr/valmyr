//
// Created by valmyr on 01/10/2020.
//
#include "./Lista.h"
int Lista::quantidadeAtualDeNomes = 0;
Lista::Lista(){
    size = 0;
    listaNomes = NULL;
    fp = fopen("./lista.txt","w");
    rel = fopen("./listaOrdenada1.txt","r");
    fpp = fopen("./listaOrdenada.txt","w");
    if(fp == NULL)cout<<"Erro na leitura"<<endl;
    if(fpp == NULL)cout<<"Erro na leitura"<<endl;
    if(rel == NULL)cout<<"Erro na leitura"<<endl;
}
Lista::Lista(int size){
    this->size = size;
    alocarLista();
}
void Lista::alocarLista(){
    listaNomes = (string *) new string[size];
}
void Lista::setSize(int size) {
    this->size = size;
    alocarLista();
}
int Lista::getquantidadeAtualDeNomes(){
    return quantidadeAtualDeNomes;
}
bool Lista::inserirNome(string Nome) {
    if(quantidadeAtualDeNomes == size){
        cout<<"Lista cheia"<<endl;
        return false;
    }
    string *auxTemp = (string *)listaNomes;
    auxTemp[quantidadeAtualDeNomes] = Nome;
    auxTemp[quantidadeAtualDeNomes] = Nome;
    salvar(fp,auxTemp[quantidadeAtualDeNomes]);
    tratamentoNomes();
    quantidadeAtualDeNomes++;
    return true;
}
void Lista::imprimirLista() {
    cout.fill('0');
    if(quantidadeAtualDeNomes == 0){
        cout<<"Lista vazia"<<endl;
        return;
    }
    for(int i = 0; i < quantidadeAtualDeNomes; i++){
        cout<<"["<<setw(2)<<i+1<<"] "<< listaNomes[i]<<endl;
    }
}

void Lista::ordenarNomes(){
    for(int i = 0; i < quantidadeAtualDeNomes; i++){
        for(int j = i+1;j < quantidadeAtualDeNomes; j++){
            if(listaNomes[i][0] > listaNomes[j][0]){
                string tempNome = listaNomes[j];
                listaNomes[j]= listaNomes[i];
                listaNomes[i] = tempNome;
            }
        }
    }
    for(int i = 0; i < quantidadeAtualDeNomes; i++){
        salvar(fpp,listaNomes[i]);
    }
}
void Lista::tratamentoNomes(){
    listaNomes[quantidadeAtualDeNomes][0] = toupper((char)listaNomes[quantidadeAtualDeNomes][0]);
}
int Lista::menu(){
    int op;
    cout.fill('=');
    cout<<setw(40)<<" "<<endl;
    cout.fill(' ');
    cout<<setw(20)<<"DESEJA"<<endl;
    cout.fill('=');
    cout<<setw(40)<<" "<<endl;
    cout<<"[1] Adicionar"<<endl;
    cout<<"[2] Imprimir"<<endl;
    cout<<"[3] Ordenar"<<endl;
    cout<<"[4] Total"<<endl;
    cout<<"[5] limpar tela"<<endl;
    cout<<"[6] Sair"<<endl;
    cout<<setw(40)<<" "<<endl;
    cin>>op;
    validarRespostas(op);
    system("cls");
    return op;
}
void Lista::validarRespostas(int &op) {
    while(op > 6 or op < 1){
        cout<<"Opcao invalida"<<endl;
        cin>>op;
    }
}
Lista::~Lista(){
    fclose(fp);
    fclose(fpp);
   	delete listaNomes;
}
void Lista::salvar(FILE *fp, string a){
    int j = 0;
    while(a[j]!='\0'){
        fprintf(fp,"%c",a[j++]);
    }
    fprintf(fp,"%c",'\n');
}
void Lista::reload(){
    int i = 0,  j = 0;
    char *buffer = new char[100];
    do{
        buffer[i] = fgetc(rel);
        if(quantidadeAtualDeNomes == size)break;
        if(buffer[i] == '\n'){
            buffer[i] = '\0';
            listaNomes[quantidadeAtualDeNomes++] = buffer;
            i = -1;
        }
    }while(buffer[i++] != EOF);
    if(fclose(rel)){
        cout<<"Arquivo fechado"<<endl;
    }
   fpp = fopen("./listaOrdenada1.txt","w");

}

