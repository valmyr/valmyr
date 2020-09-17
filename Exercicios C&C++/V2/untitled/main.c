#include <stdio.h>
#include <string.h>

void Q_1();
void Q_2();
void Q_3();
void Q_4();
void Q_5();
void Q_6();
void Q_7();
void Q_8();
void Q_9();
int main() {
    return 0;
}
void Q_1(){
    char nome[10];
    printf("Informe um nome >> ");
    gets(nome);
    for(int i = 0; i < 4; i++){
        printf("%c",nome[i]);
    }
}
void Q_2(){
    char nome[10];
    printf("Informe um nome >> ");
    gets(nome);
    for(int i = 0; i < strlen(nome); i++){
        if(i % 2 != 0)
            printf("%c",nome[i]);
    }
}
void Q_3(){
    char nome[10];
    printf("Informe um nome >> ");
    gets(nome);
    for(int i = 0; i < strlen(nome); i++){
        if(i % 2 == 0)
            printf("%c",nome[i]);
    }
}

void Q_4(){
    char nome[10] = "Valmir";
    for(int i = 0; i < 10; i++){
        printf("%s",nome);
    }
}
void Q_5(){
    struct Dados{
        char nome[30];
        char endereco[10];
        int telefone;
    };
    struct Dados Informacoes;
    printf("Informe seu nome>>");
    gets(Informacoes.nome);
    printf("Informe seu endereço >>");
    gets(Informacoes.endereco);
    printf("Informe seu numero de telefone >>");
    printf("nome: %s\n",Informacoes.nome);
    printf("Endereco: %s\n",Informacoes.endereco);
    printf("Telefone: %d\n",Informacoes.telefone);
}
void Q_6(){
    struct Dados{
        char nome[30];
        char sexo;
        int idade;
    };
    struct Dados Informacoes;
    printf("Informe seu nome >> ");
    gets(Informacoes.nome);
    printf("Informe seu sexo >> M ou F");
    gets(Informacoes.sexo);
    printf("Informe sua Idade >>");
    scanf("%d",&Informacoes.idade);
    if(Informacoes.sexo == 'F'&& Informacoes.idade < 25){
        printf("Seu nome eh: %s\n",Informacoes.nome);
        printf("Idade %d\n",Informacoes.idade);
        printf("ACEITA\n");
    }
    else{
        printf("NAO ACEITA\n");
    }


}
void Q_7(){
    char nome[100];
    printf("Informe seu nome>>");
    gets(nome);
    int i = 0;
    while(*nome != NULL){
        i++;
    }
    printf("A quantidada de letras do seu nome eh %d",i);
}
void Q_8(){
    char nome[100];
    printf("Informe seu nome >>");
    gets(nome);
    int i  = 0;
    while (i < strlen(nome)){
        printf("%s",nome);
        i++;
    }
}
void Q_9(){
    char mensagem[1000];
    char Vogais[12]={"A","a","E","e","I","i","O","o","U","u"};

    int i = 0;
    printf("Informe a mensagem >>");
    gets(mensagem);
    while(i < strlen(mensagem)){
        
    }
}
