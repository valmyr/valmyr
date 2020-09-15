#include <iostream>

using namespace std;
union Interger{
    char caracter1;
    short short1;
    int integer1;
    long long1;

};
void barra();
int main()
{   Interger v1;
    cout<<"Informe um caracter: ";
    cin >>v1.caracter1;
    cout<<"Informe um inteiro: ";
    cin >>v1.integer1;
    cout<<"Informe um long: ";
    cin >>v1.long1;
    cout<<"Informe um short: ";
    cin >>v1.short1;
    barra();
    cout<<"Tipo char";
    barra();
    cout<<endl;
    cout<<"(char) -> (char): "<<(char)(char)v1.caracter1<<endl;
    cout<<"(short) -> (char): "<<(char)(short)v1.short1<<endl;
    cout<<"(int) -> (char): "<<(char)(int)v1.integer1<<endl;
    cout<<"(long) -> (char): "<<(char)(long)v1.short1<<endl;
    barra();
    cout<<"Tipo int";
    barra();
    cout<<endl;
    cout<<"(char) -> (int): "<<(int)(char)v1.caracter1<<endl;
    cout<<"(short) -> (int): "<<(int)(short)v1.short1<<endl;
    cout<<"(int) -> (int): "<<(int)(int)v1.integer1<<endl;
    cout<<"(long) -> (int): "<<(int)(long)v1.short1<<endl;
    barra();
    cout<<"Tipo short";
    barra();
    cout<<endl;
    cout<<"(char) -> (short): "<<(short)(char)v1.caracter1<<endl;
    cout<<"(short) -> (short): "<<(short)(short)v1.short1<<endl;
    cout<<"(int) -> (short): "<<(short)(int)v1.integer1<<endl;
    cout<<"(long) -> (short): "<<(short)(long)v1.short1<<endl;
    barra();
    cout<<"Tipo long";
    barra();
    cout<<endl;
    cout<<"(char) -> (long): "<<(long)(char)v1.caracter1<<endl;
    cout<<"(short) -> (long): "<<(long)(short)v1.short1<<endl;
    cout<<"(int) -> (long): "<<(long)(int)v1.integer1<<endl;
    cout<<"(long) -> (long): "<<(long)(long)v1.short1<<endl;
    return 0;
}
void barra(){
    for(int i = 0; i <= 5; i++)cout<<"=-";
}
