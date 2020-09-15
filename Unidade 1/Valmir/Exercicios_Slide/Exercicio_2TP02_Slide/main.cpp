#include <iostream>

using namespace std;
struct Num_C{
    int imag;
    int real;
};
Num_C Soma(Num_C n1, Num_C n2);
Num_C Multiplicacao(Num_C n1, Num_C n2);
int main(){
    Num_C N1,N2;
    cout<<"Real [1]:    ";
    cin>>N1.real;
    cout<<"Imaginario [1]:  ";
    cin>>N1.imag;
    cout<<"Real [2]:    ";
    cin>>N2.real;
    cout<<"Imaginario [2]:  ";
    cin>>N2.imag;
    cout<<"("<<N1.real<<" + "<<N1.imag<<"i) + ("<<N2.real<<" + "<<N2.imag<<"i) = "<<"("<<Soma(N1, N2).real<<" + "<<Soma(N1, N2).imag<<"i)"<<endl;
    cout<<"("<<N1.real<<" + "<<N1.imag<<"i) + ("<<N2.real<<" + "<<N2.imag<<"i) = "<<"("<<Multiplicacao(N1, N2).real<<" + "<<Multiplicacao(N1, N2).imag<<"i)"<<endl;

}

Num_C Soma(Num_C n1, Num_C n2){
    Num_C resp;
    resp.real = n1.real + n2.real;
    resp.imag = n1.imag + n2.imag;
    return resp;
}
Num_C Multiplicacao(Num_C n1, Num_C n2){
    Num_C resp;
    resp.real = (n1.real * n2.real - n1.imag* n2.imag);
    resp.imag = (n1.imag*n2.real +n1.real *n2.imag);
    return resp;
}
