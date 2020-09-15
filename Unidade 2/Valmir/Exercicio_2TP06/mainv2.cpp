
/*
Importante: Compilador usado Clion, C++17.
Aluno: Valmir Ferreira da Silva
Matrícula: 119211110
    Laboratório Virtual de Programação 06
Crie uma classe ContaBancaria que tenha como atributos o nome do titular,
numero da conta e saldo. Esta classe deve simular um acesso à conta com as
seguintes opções:

·        Realizar Saque (o saldo não pode ficar negativo);

·        Fazer Depósito (apenas aumenta o saldo da conta);

·        Consultar Saldo.

      No programa principal, crie 2 contas. Coloque R$ 20,00 na primeira e R$ 30,00 na segunda.
 Retire R$ 50,00 da primeira e R$ 10,00 da segunda. Exiba na tela o saldo de cada uma. Faça outros
 testes para verificar se o programa está testando todas as condições possíveis
*/
#include <iostream>
#include<iomanip>
int main();//protótipo da função main()
using namespace std;
//class
class contaBancaria{
    string nome;
    float saldo;
    int conta;
public:
    //construtor
    contaBancaria();
    //Função para a realização do saque
    void realizar_Saque();
    //Função para a realização do deposito
    void fazer_Deposito();
    //Função para consultar o saldo
    float consulta_saldo();

    //set nome
    void set_nome(string nome);
    //set saldo
    void set_saldo(float saldo);
    //set conta
    void set_conta(int conta);

    //get nome
    string get_nome();
    //get conta
    int get_conta();
    //Menu para interação com o usuário
    int menu();
    //Função para verficar se a conta existe
    bool verificar_Conta(int conta);


};
//----------------------construtores------------------------------
contaBancaria::contaBancaria() {
    nome = "\n";
    saldo = 0;
    conta = 0;
}
//-----------------------------------------------------------

//-----------------------------gets--------------------------
string contaBancaria::get_nome(){
    return nome;
}
int contaBancaria::get_conta(){
    return conta;
}
//-----------------------------------------------------------
//------------------------sets-------------------------------
void contaBancaria::set_conta(int conta) {
    this->conta = conta;
}
void contaBancaria::set_nome(string nome) {
    this->nome = nome;
}
void contaBancaria::set_saldo(float saldo) {
    this->saldo = saldo;
}

//-------------------------------------------------------------
float contaBancaria::consulta_saldo() {
    //Retornando para a função o saldo
    return saldo;
}
void contaBancaria::fazer_Deposito() {
    float Deposito, op;
    cout<<"Informe o Valor do Deposito: ";cin>>Deposito;
    if(Deposito < 0) {
        //Se o deposito for menor que que zero o usuário recebe a mensagem "Deposito não autorizado"  e tem duas opções para escolher
        //[1] Sair [2] Tentar novamente
        cout << "Deposito não autorizado\n";
        cout << "Deseja: "<<endl<<" [1] Sair"<<" [2] Tentar novamente"<<endl;
        cin >> op;
        while (op < 1 || op > 2) {
            //Caso seja maior que 2 ou menor que 1 o usuário recebe a mensagem "Opção invalida" e "Tente novamenete"
            cout << "Opcao invalida\n";
            cout << "Tente Novamente: ";
            cin >> op;
        }
        if (op == 2) {
            //Caso o usuário digite 2 ele vai digitar novamente o valor do deposito
            fazer_Deposito();
        }
    }else{

        //Se o deposito for menor que zero o usuário recebe a mensagem "Deposto aceito" e o valor e somado á conta dele.
        cout<<"Deposito aceito.\n";
        saldo+=Deposito;
    }
}
void contaBancaria::realizar_Saque() {
    float Saque = 0; int  op = 0;
    cout<<"Informe o Valor do Saque: ";cin>>Saque;
    if(Saque > saldo) {
        //Se o saque for maior que o saldo o usuário recebe a mensagem "Saque não autorizado"
        cout << "Saque nao autorizado\n";
        //o Usuário esta limitado a duas opções
        //[1] Sair [2] Tentar novamente
        cout << "Deseja: "<<endl<<" [1] Sair"<<" [2] Tentar novamente"<<endl;
        cin>>op;
        while(op < 1|| op > 2){
            //Caso seja maior que 2 ou menor que 1 o usuário recebe a mensagem "Opção invalida" e "Tente novamenete"
            cout<<"Opcao invalida\n";
            cout<<"Tente Novamente: ";cin>>op;
        }
        if(op == 2) {
            //Caso o usuário digite 2 ele vai digitar novamente o valor do saque
            realizar_Saque();
        }
        //Caso contráio o programa fecha
        return;
    }
    else {
        cout << "Saque autorizado.\n";
        //Se o saque for menor que saldo o usuário recebe a mensagem "Saque autorizado" e o valor e descontado da conta dele
        saldo -= Saque;
    }
}
int contaBancaria::menu(){
    int op;
    //O manipulador paramétrico cout.fill também pode ser usado para definir o caractere de preenchimento.
    cout.fill('=');
    //o caracter de preenchimento vai se repetir 50-strlen(DESEJA) vezes
    cout<<setw(25)<<"DESEJA"<<setw(25);
    cout<<"\n";
    cout<<"[1]  Sacar\n[2]  Depositar\n[3]  Saldo\n[4]  Sair\n";
    //o caracter de preenchimento vai se repetir 50 vezes
    cout<<setw(50)<<""<<endl;
    cout<<">> ";
    cin>>op;
    while(op < 1 or op > 4){
        //Caso o usuário digite algo maior que 4 ou algo menor que 1 ele recebe a mensagem "Opção invalida"
        cout<<"Opcao invalida"<<endl;
        cout<<"Tente novamente: ";
        cin>>op;
    }
    return op;
}
bool contaBancaria::verificar_Conta(int conta){
    while(conta < 1 or conta > 2){
        cout<<"Conta invalida\n";
        cout<<"Tente novamente: ";
        cin>>conta;
    }
    return true;

}
int main() {
    //Instanciando objetos da class contaBancaria
    contaBancaria *c1 = new contaBancaria[2];//Professor solicitou o uso de apenas duas contas
    int conta;//Conta
    //Atribuindo valores as instâncias
    c1[0].set_nome("Valmir");
    c1[0].set_conta(1);
    c1[0].set_saldo(20);
    c1[1].set_nome("Stephaine");
    c1[1].set_conta(2);
    c1[1].set_saldo(30);

    while(true){
        //A variável op recebe a opção que o usuário digitou. O usuário esta limitado a 4 opções
        int op = c1->menu();
        if (op < 4) {
            //Se for menor que 4 o usuário vai informar a conta
            cout << "Conta: ";
            cin >> conta;
            //Verificando se a conta existe
            //Existe apenas duas contas cadastradas
            c1->verificar_Conta(conta);
            //Mostrando o nome do titular e a conta
            cout << "Titular: " << c1[conta - 1].get_nome() <<"\nConta: "<<c1[conta-1].get_conta()<<endl;
            switch (op) {
                case 1:
                    //caso op == 1 ele escolheu realizar saque
                    c1[conta - 1].realizar_Saque();
                    break;
                case 2:
                    //caso op == 2 ele escolheu realizar deposito
                    c1[conta - 1].fazer_Deposito();
                    break;
                case 3:
                    //caso op == 3 ele escolheu consultar saldo
                    cout << "Saldo atual: " << c1[conta - 1].consulta_saldo() << endl;
                    break;
                default:
                    //Esta opção não vai acontece pois o usuário esta limitado a escolha de 1 até 3
                    cout << "impossivel";
            }
        }else
        //caso op == 4 o programa fechar
            return 0;
    }
}
