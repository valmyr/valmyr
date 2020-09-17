#include <iostream>
using namespace std;

double fatorial(double n);
int main() {
    double n,m;
    while(cin>>n && cin>>m){
        cin.precision(.1);
        cout.precision(.1);
          cout<<fixed<<fatorial(m)+fatorial(n)<<endl;
    }
    return 0;
}
double fatorial(double n){
    double fat = 1;
    for(double i = 1; i <= n; i++){
        fat*=i;
    }
    return fat;
}