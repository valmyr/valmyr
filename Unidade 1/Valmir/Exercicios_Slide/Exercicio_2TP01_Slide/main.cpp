#include<iostream>
using namespace std;
struct fracao{
    int num;
    int den;
};
void mdc(fracao *n);
fracao Soma(fracao n1, fracao n2);
fracao Subtracao(fracao n1, fracao n2);
fracao Multiplicacao(fracao n1, fracao n2);
fracao Divisao(fracao n1, fracao n2);
int main(){
    fracao num1, num2,n3;
    cout<<"Numerador    1 >> ";
    cin>>num1.num;
    cout<<"Denominador  1 >> ";
    cin>>num1.den;
    cout<<"Numerador    2 >> ";
    cin>>num2.num;
    cout<<"Denominador  2 >> ";
    cin>>num2.den;
    cout<<"Soma:    ("<<(Soma(num1,num2).num)<<" / "<<Soma(num1,num2).den<<")"<<endl;
    cout<<"Subtracao:   ("<<(Subtracao(num1,num2).num)<<" / "<<Subtracao(num1,num2).den<<")"<<endl;
    cout<<"Multiplicacao:    ("<<(Multiplicacao(num1,num2).num)<<" / "<<Multiplicacao(num1,num2).den<<")"<<endl;
    cout<<"Divisao: ("<<(Divisao(num1,num2).num)<<" / "<<Divisao(num1,num2).den<<")"<<endl;
}
fracao Soma(fracao n1, fracao n2){
    fracao resp;
    int mmc = n1.den * n2.den;
    resp.num = (mmc/n1.den)*n1.num + (mmc/n2.den)*n2.num;
    resp.den = mmc;
    mdc(&resp);
    return resp;

}
fracao Subtracao(fracao n1, fracao n2){
    fracao resp;
    int mmc = n1.den * n2.den;
    resp.num = (mmc/n1.den)*n1.num - (mmc/n2.den)*n2.num;
    resp.den = mmc;
    mdc(&resp);
    return resp;
}

fracao Multiplicacao(fracao n1, fracao n2){
    fracao resp;
    resp.num = n1.num*n2.num;
    resp.den = n1.den*n2.den;
    if(resp.den < 0)
    mdc(&resp);
    return resp;
}
fracao Divisao(fracao n1, fracao n2){
    fracao resp;
    resp.num = n1.num*n2.den;
    resp.den = n1.den*n2.num;

    mdc(&resp);
    return resp;
}
void mdc(fracao *n){
    int r, n1, n2, temp;
    n1 = n->num;
    n2 = n->den;
    while(n2 != 0){
        r = n1 % n2;
        n1 = n2;
        n2 = r;
    }
    n ->den /= n1;
    n ->num /= n1;
    if(n->den < 0){
        n->den*=-1;
        n->num*=-1;
    }
}
