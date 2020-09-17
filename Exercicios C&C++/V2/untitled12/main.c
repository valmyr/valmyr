#include <stdio.h>
int main(){
    char Nome[100], Sexo;
    int Matricula;
    float Valor_Vendido_, Salario = 1034;
    printf("Informe seu Nome >>");scanf("%s",Nome);
    fflush(stdin);
    printf("Informe seu Sexo (F - Feminino) (M - Masculino) >> ");scanf("%c",&Sexo);
    printf("Informe sua Matricula >> ");scanf("%d",&Matricula);
    printf("Quanto voce vendeu no mes? >> ");scanf("%f",&Valor_Vendido_);

    if(Valor_Vendido_ < 5000){
        Salario += Salario*(2.5/100);
    }else{
        if(Valor_Vendido_ <= 10000){
            Salario += Salario*(5/100);
        }
        else{
            if(Valor_Vendido_ < 20000){
                Salario += (float)Salario*(10/100);
            }else{
                Salario += (float)Salario*(15/100);
            }
        }
    }
    printf("Matricula: %d\n",Matricula);
    printf("Nome : %s\n",Nome);
    printf("Sexo : %c\n",Sexo);
    printf("Salario: %f\n",Salario);



    return 0;
}
