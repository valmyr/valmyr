#include <stdio.h>
#include <stdlib.h>
struct Aluno{
    char Nome[40];
    char Matricula[10];
    char Curso[30];
};
int main() {
    struct Aluno *Dados;
    Dados = malloc(sizeof(struct Aluno) * 1);
    printf("Informe o seu nome:");gets(Dados[0].Nome);
    printf("Informe o sua matricula:");gets(Dados[0].Matricula);
    printf("Informe o seu curso:");gets(Dados[0].Curso);
    for(int i = 0; i <= 100; i++)
        printf("_");
    printf("\n%s | %s | %s",Dados[0].Nome,Dados[0].Matricula,Dados[0].Curso);

    return 0;
}
