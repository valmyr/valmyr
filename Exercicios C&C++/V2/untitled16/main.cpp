#include <iostream>
#include<string>
using namespace std;
string primeira(string palavra, int *p);
string segunda(string palavra, int tamanho);
string terceira(string palavra, int tamanho);
int main()
{   int i, n;
    cin>>n;
    cin.ignore();
    for(int ii = 0; ii < n; ii++){
        string palavra;
        getline(cin, palavra);
        palavra = primeira(palavra, &i);
        palavra = segunda(palavra, i+1);
        palavra = terceira(palavra, int(i/2));
        cout<<palavra<<endl;
    }
    return 0;
}

string primeira(string palavra, int *p){
    int i = 0;
    while(palavra[i] != '\0'){
        if((palavra[i] >= 97 && palavra[i] <= 122)
        || (palavra[i] >= 65 && palavra[i] <= 90)){
            palavra[i]=(char)palavra[i]+3;
        }
        i++;
    }
    *p = i;
    return palavra;
}
string segunda(string palavra, int tamanho){
    int aux;
    char buffer;
    aux = tamanho-2;
    for(int i = 0; i < (tamanho/2); i++){
        buffer = palavra[aux];
        palavra[aux] = palavra[i];
        palavra[i] = buffer;
        aux--;
    }
    return palavra;
}
string terceira(string palavra, int tamanho){
    while(palavra[tamanho] != '\0'){
        if(palavra[tamanho] != ' ')
            palavra[tamanho]=(char)palavra[tamanho]-1;
        tamanho++;
    }
    return palavra;

}