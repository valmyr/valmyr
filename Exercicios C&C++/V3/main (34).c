#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void ler_matriz(char *m[], int linhas);
void  proc_nome(char *m[], int linhas);
void ordena_matriz(char *m[], int linhas);
int main(){
    char *nomes[60] = {
            "ALISSON GAMBETA\0",
            "ANDRE KARINE ESCARIAO DE MEDEIROS\0",
            "JOSEANE DOS SANTOS SILVA\0",
            "KARINE FELIX ARAUJO\0",
            "KLEITON OLIVEIRA SANTOS\0",
            "VALMIR FERREIRA DA SILVA\0",
            "LARISSA BARBOSA VIEIRA\0",
            "MIKAEL BRASILEIRO FERREIRA DE ALMEIDA AMARAL\0"
    };


    ler_matriz(nomes, 9);
    proc_nome(nomes, 9);
  //  ordena_matriz(nomes, 9);
    return 0;
}
void ler_matriz(char *m[],int linhas){
    int i = 0;
    while(i <= linhas){
        printf("%s\n",m[i]);
        i++;
    }
}
void  proc_nome(char *m[], int linhas) {
    char str[10];
    int i = 0, j = 0,cont = 0;
   printf("\n\nInforme o primeiro nome: ");
   gets(str);

    while (str[i] != '\0') {
        str[i] = toupper(str[i]);//fazer todas as letras ficarem maiusculas
        i++;
    }
    i = 0;
    while (str[j] != '\0'){
        while(str[j] == m[i][j]){
            j++;
        }
        if(strlen(str) == j) break;
        i++;
    }
        printf("\n%s", m[i ]);
}
//falta..
void ordena_matriz(char *m[], int linhas){
    char alfabeto = 'A';
    while(alfabeto <= 'Z') {
        for (int i = 0; i < linhas; i++) {
            if(m[i][0] == alfabeto){

            }
        }
    }
}