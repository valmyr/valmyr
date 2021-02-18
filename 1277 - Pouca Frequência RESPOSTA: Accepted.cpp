#include<iostream>
#include<vector>
using namespace std;
bool reprovou(string);
int main(){
    int numeroDeCasosDeTestes;
    int numeroDeEstudantesNaTurma;
    bool boolean = true;
    vector<string>estudantes;
    vector<string>reprovados;
    cin>>numeroDeCasosDeTestes;
    while(numeroDeCasosDeTestes--){
        if(boolean)boolean = false;
        else cout<<endl;
        cin>>numeroDeEstudantesNaTurma;
        for(int i = 0; i < numeroDeEstudantesNaTurma; i++){
            string estudante;
            cin>>estudante;
            estudantes.push_back(estudante);
        }
        for(int i = 0; i < numeroDeEstudantesNaTurma; i++){
            string registros;
            cin>>registros;
            if(reprovou(registros))
                reprovados.push_back(estudantes[i]);
        }
        if(reprovados.size() <= 0) {
            estudantes.clear();
            continue;
        }
            for (int i = 0; i < reprovados.size() - 1; i++)
                cout << reprovados[i] << " ";
            cout << reprovados[reprovados.size() - 1];
        reprovados.clear();
        estudantes.clear();
    }
    cout<<endl;
    return 0;
}
bool reprovou(string registros){
    float presente = 0, faltas = 0,aulas = 0;
    for(int j = 0; j < registros.size(); j++){
        if(registros[j] == 'M')
            continue;
        if(registros[j] == 'P')
            presente++;
        else
            faltas++;
        aulas++;
    }
    return (double(faltas/aulas) > .25);
}
