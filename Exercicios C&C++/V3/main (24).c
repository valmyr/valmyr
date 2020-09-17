#include <iostream>
using namespace std;
float proxima_parcela_financiamento(float *S, float J);
void Quest_1();
void Quest_2();
void Quest_3();
void Quest_4();
struct Emprestimo{
public:
    float N;
    float S;
    float J;
};
float p(Emprestimo *A);
int main(){
    int op;
    cout<<"informe a questao >>";
    cin>>op;
    switch(op){
        case 1:
            Quest_1();
            break;
        case 2:
            Quest_2();
            break;
        case 3:
            Quest_3();
            break;
        case 4:
            Quest_4();
            break;
    }
}
void Quest_1(){
    float S = 200, J = 1, N =5;
    for(int i = 1; i <= N; i++){
        S += (S * (J/100));
        cout<<S<<endl;
    }
}
void Quest_2(){
    float S = 200, J = 1;
    cout<<proxima_parcela_financiamento(&S,J);
}
void Quest_3(){
    float S = 200, J = 1;
    for(int i = 0; i < 10; i++)
        cout<<proxima_parcela_financiamento(&S,J)<<endl;
}
void Quest_4(){
    Emprestimo Em;
    Em.J = 1.0;
    Em.S = 200;
    Em.N= 5;
    for(int i = 1; i < Em.N; i++){
    cout<<p(&Em)<<endl;

     }
}
float proxima_parcela_financiamento(float *S, float J){
    *S += (*S * J/100);
    return *S;
}
float p(Emprestimo *A){
    A->S += A->S*(A->J/100);
    return A->S;
}
//alguém pode da uma olhada e explica a questão 5 tbm....