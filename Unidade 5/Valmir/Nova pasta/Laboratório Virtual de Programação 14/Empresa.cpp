//
// Created by valmy on 01/10/2020.
//

#include "./Empresa.h"

//retornando quantidade atual da lista de funcionários
int Empresa::getqFuncionarios(){
    return qFuncionario;
}
//construtor default
Empresa::Empresa() {
    nomeEmpresa = "\n\0";
    sizeF = 1;
    CNPJ = "\n\0";
    qFuncionario= 0;
}
//construtor com parâmetros
Empresa::Empresa(Funcionario F, string nomeEmpresa, string CNPJ, int sizeF) {
    //iniciando atributos da class empresa
    this->F = &F;
    this->CNPJ = CNPJ;
    this->nomeEmpresa = nomeEmpresa;
    this->sizeF = sizeF;
    qFuncionario= 0;
}
//-------------------setEmpresa------------------------------------------
void Empresa::setCNPJ(string CNPJ) {
    this->CNPJ = CNPJ;
}

void Empresa::setnomeEmpresa(string nomeEmpresa) {
    this->nomeEmpresa = nomeEmpresa;
}
void Empresa::setSize(int sizeF) {
    this->sizeF = sizeF;
    //chamando a função para alocar a memória
    alocarFuncionarios();
}
//------------------------getEmpresa----------------------------------------
string Empresa::getCNPJ() const{
    return CNPJ;
}
string Empresa::getnomeEmpresa() const {
    return nomeEmpresa;
}
//--------------------------------------------------------------------------
//inserir funcionários
void Empresa::inserirFuncionario(Funcionario auxF) {
    //verifica se a lista de funcionarios esta cheia
    if(qFuncionario >= sizeF){
        cout<<"Lista cheia";
        return;
    }
    //caso contrário adiciona o funcionário a lista e incrementa a quantidade de funcionarios
    F[qFuncionario++] = auxF;
}
//alocação de memória
void Empresa::alocarFuncionarios() {
    //aloca dinâmicamente um quantidade 'sizeF' de pessoas na memória heap
    this->F = (Funcionario *)new Funcionario[sizeF];
}
//interção com o usuário
int Empresa::menu(){
    //interação com o usuário
    int op;
    cout.fill('=');
    cout<<setw(100)<<" "<<endl;
    cout.fill(' ');
    cout<<setw(50)<<"BEM VINDOS AO SISTEMA DA EMPRESA "<<nomeEmpresa<<endl;
    cout.fill('=');
    cout<<setw(100)<<" "<<endl;
    //opção para efetuar o cadastro de funcionários
    cout<<"[1] Cadastrar novo funcionario"<<endl;
    //opção para imprimir os funcionários cadastrados
    cout<<"[2] Mostrar funcionarios cadastrados"<<endl;
    //opção para efetuar o aumento por departamento
    cout<<"[3] Aumentar salario de um departamento"<<endl;
    //opção para limpar a tela
    cout<<"[4] Limpar tela"<<endl;
    //opção para fechar o programa
    cout<<"[5] Sair"<<endl;
    cout<<setw(100)<<" "<<endl;
    cin>>op;
    //validação de resposta informadas
    validacao_de_respostas(op);
    //limpando a tela do menu
    system("cls");
    //retornando a opção infomada
    return op;
}
//imprimir lista de funcionários
void Empresa::imprimirNomes() const{
    //se quantidade de funcionarios for zero e o usuário tentar imprimir recebe a mensagem
    //"Lista vazia
    if (not(qFuncionario)){
        cout << "Lista vazia" << endl;
        //sair da função
        return;
    }
    cout.fill('=');
    cout<<setw(100)<<" "<<endl;
    cout.fill(' ');
    //imprimir o nome, salário é o departamento
    for(int i = 0; i < qFuncionario;  i++){
        cout<<"|Nome["<<i+1<<"]: "<<setw(10)
        <<F[i].getNome()<<"|Salario:   "<<setw(5)
        <<F[i].getSalario()<<"|Departamento:   "<<setw(5)
        <<F[i].getDepartamento()<<endl;
    }
    cout.fill('=');
    cout<<setw(100)<<" "<<endl;
}
void Empresa::aumentoSalarioPorderpartamento(int departamento, float porcentagem){
    //variável com a função de verificar se o aumento foi feito com sucesso
    bool sucesso = false;
    for(int i = 0;i < qFuncionario; i++){
        //caso o departemento informando estiver na lista de cadastro o valor do salário de todas as pessoas e aumentado
        if(departamento == F[i].getDepartamento()){
            F[i].setSalario(F[i].getSalario() + (F[i].getSalario()*(porcentagem/100)));
            //caso entre no if o valor da variável sucesso e alterado para verdadeiro
            sucesso = true;
        }
    }
    //se sucesso for igual a true o aumeto foi realizado
    if(sucesso){
        cout<<"Aumento realizado com sucesso"<<endl;
        return;
    }
    //caso contrário o departamento não existe
    cout<<"Departamento não encontrado"<<endl;
    return;
}
Empresa::~Empresa(){
    cout<<"Liberando heap"<<endl;
    delete F;
}
void Empresa::validacao_de_respostas(int & op){
    //se op for maior que 5 e menor que 1 o usuário recebe a mensagem opção invalida
    //e ele precisa informa um nova opção para continuar
    while(op < 1 or op > 5){
        cout<<"opcao invalida: ";cin>>op;
    }
}
