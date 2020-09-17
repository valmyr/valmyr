#include <iostream>
using namespace std;
float fatorial(int n);
float pow_imp(int x,int y);
int main(){
	int x,n,i = 0;float e_x = 0;
	cout<<"Informe o valor de x >>";
	cin>>x;
	cout<<"Informe o valor de n >>";
	cin>>n;
	while(i <= n){
		e_x+= pow_imp(x,i)/fatorial(i);
		i+=1;
	}
	cout<<"e^("<<x<<") = "<<e_x;
}
float pow_imp(int x,int y){
	int i = 1;
	float res = 1;
	while(i < y){
		x *= x;
		i++;
	}
	return (float)x;
}
float fatorial(int n){
	float fat = n;
	if(n == 0){return 1;}
	for(int i = 1;i < n;i++){
		fat*=i;
	}
	return fat;
}