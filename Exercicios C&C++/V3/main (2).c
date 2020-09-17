#include <stdio.h>
float Exibir(float Emprestimo);
int main(void) {
    float Divida, Soma_Dividas;
    int i = 0;
    printf("Quanto voce que de emprestimo?\n");
    do{
        printf(">> ");
        scanf("%f",&Divida);
        Soma_Dividas+= Divida;
        i++;
        if(Divida == 0){
            i--;
        }
    }while(Divida != 0);

    printf("Foram digitados %d dividas\n",i);
    printf("Relatorio\n\n");
    Exibir(Soma_Dividas);
    return 0;
}
float Exibir(float Emprestimo){

    printf("|Valor Inicial|  Divida + Juros| Juros|  Quantidade de Parcelas| Valor da parcela|\n");
    float Divida_com_juros = 0, Juros = 2.5/100;
    int j = 0, temp = 1;
    for(int i = 1; i < 12; i++){
        Divida_com_juros += Emprestimo * Juros;//
        if(i % 2 == 0 && i >= 4 || i == 1) {
            printf("\n|%.2f      |%.2f         |%.2f |  %.d                       |%.2f           |\n", Emprestimo,Divida_com_juros + Emprestimo, Divida_com_juros, temp, (Divida_com_juros + Emprestimo) / (temp));
            temp = 3+j*3;
            if(temp != 1){
                j++;
            }
        }
    }
}