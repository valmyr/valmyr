#include <stdio.h>
#include <string.h>
void Exibir(char Nome[100], char Sexo, float Salario, int Matricula);
int main(){
    char Nome[100], Sexo;
    char Nome_Menor_Numero_de_Vendas[100], Sexo_Menor_Numero_de_Vendas;
    float Aux_Salario = 10000000;
    int Matricula;
    float Valor_Vendido_, Salario = 1034,cont = 0,Media_de_Vendas;
    do {
        printf("Informe seu Nome >>");
        scanf("%s", Nome);
        fflush(stdin);
        printf("Informe seu Sexo (F - Feminino) (M - Masculino) >> ");
        scanf("%c", &Sexo);
        printf("Informe sua Matricula >> ");
        scanf("%d", &Matricula);
        printf("Quanto voce vendeu no mes? >> ");
        scanf("%f", &Valor_Vendido_);

        if (Valor_Vendido_ < 5000) {
            Salario += Salario * (0.025);
        } else {
            if (Valor_Vendido_ <= 10000) {
                Salario += Salario * (0.05);
            } else {
                if (Valor_Vendido_ < 20000) {
                    Salario += Salario * (0.1);
                } else {
                    Salario += Salario * (0.15);
                }
            }
        }
        Exibir(Nome,Sexo,Salario,Matricula);
        if(Salario < Aux_Salario){//maior
            Aux_Salario = Salario;
            strcpy(&Nome_Menor_Numero_de_Vendas,&Nome);
            strcpy(&Sexo_Menor_Numero_de_Vendas,&Sexo);
            int Matricula_Maior_Numero_de_Vendas = Matricula;

        }
        cont++;
    }while(Valor_Vendido_ != 0);
    Media_de_Vendas /= cont;
    printf("O menor vendendor foi:");
    Exibir(Nome_Menor_Numero_de_Vendas,Sexo_Menor_Numero_de_Vendas,Aux_Salario,Sexo_Menor_Numero_de_Vendas);
    printf("Media de vendas = %f", Media_de_Vendas);



    return 0;
}
void Exibir(char Nome[100], char Sexo, float Salario, int Matricula){
        printf("Matricula: %d\n", Matricula);
        printf("Nome : %s\n", Nome);
        printf("Sexo : %c\n", Sexo);
        printf("Salario: %f\n", Salario);

}
