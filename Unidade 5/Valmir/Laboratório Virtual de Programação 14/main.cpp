#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "./Empresa.cpp"
#include "./Funcionario.cpp"
int main() {
    //intanciando objeto da class Empresa
    Empresa Vtech;
    //intanciando objeto auxiliar da class funcionário
    Funcionario temP;
    //variáveis auxiliares
    string CNPJ, nomeEmpresa;
    string nomeAux, dataAdamissaoAux;
    float porcentagem = 0;
    float salario;
    int sizeAux, i = 0,departamentoAux;
    //---------------------------------------------------------//
    //solicitando dados da empresa ao usuário
    cout<<"Informe o nome da empresa: ";cin>>nomeEmpresa;
    cout<<"Informe o CNPJ: ";cin>>CNPJ;
    cout<<"Informe a quantidade de funcionarios: ";cin>>sizeAux;
    //enviando dados para serem atribuidos
    Vtech.setSize(sizeAux);
    Vtech.setCNPJ(CNPJ);
    Vtech.setnomeEmpresa(nomeEmpresa);
    //loop
    while(true){
        //quantidade atual de funcionários
        cout<<"Total de funcionarios: "<<Empresa::getqFuncionarios()<<endl;
        //variável auxiliar que recebe a opção informada pelo usuário na função menu
        int op = Vtech.menu();
        switch(op) {
            case 1:
                //caso o usuário informe 1 ele escolheu cadastrar um novo funcionário
                cin.ignore();
                //solicitando dados do funcionario da empresa
                cout << "Nome[" << Empresa::getqFuncionarios() + 1 << "]: ";
                getline(cin, nomeAux);
                cout << "Departamento[" << Empresa::getqFuncionarios() + 1 << "]: ";
                cin>> departamentoAux;
                //iginorando o cararcter '\n'
                cin.ignore();                //iginorando o cararcter '\n'
                cout << "Data de Admissao[" << Empresa::getqFuncionarios() + 1 << "]: ";
                getline(cin, dataAdamissaoAux);
                cout << "Salario[" << Empresa::getqFuncionarios() + 1 << "]: ";
                cin >> salario;
                //enviando dados para serem atribuidos aos atributos
                temP.setNome(nomeAux);
                temP.setDepartamento(departamentoAux);
                temP.setDataAdmissao(dataAdamissaoAux);
                temP.setSalario(salario);
                Vtech.inserirFuncionario(temP);
                //imprimindo uma mensagem informando que o funicionário foi cadastrado
                cout << "Funcionario cadastrado!!!" << endl;
                break;
            case 2:
                //caso o usuário informe 2 ele escolheu imprimir a lista de funcionário cadastrados
                Vtech.imprimirNomes();
                break;
            case 3:
                //caso o usuário informe 3 ele escolheu aumentar o salário de um departamento
                //solicitando departamento e porcentagem de aumento
                cout<<"Informe o departamento: ";cin>>departamentoAux;
                cout<<"Informe a procentagem do aumento: ";cin>>porcentagem;
                Vtech.aumentoSalarioPorderpartamento(departamentoAux, porcentagem);
                break;
            case 4:
                //caso o usuário informe 4 ele escolheu limpar a tela
                system("cls");
                break;
            default :
                //caso o usuário informe 4 fechar
                return 0;
        }

    }
}
