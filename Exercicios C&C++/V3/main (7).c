#include <iostream>
using namespace std;
int main(){
	int x,n,i = 0;float e_x = 0,j = 0,mult=1;
	float fat = i;
	cout<<"Informe o valor de x >>";
	cin>>x;
	cout<<"Informe o valor de n >>";
	cin>>n;
	while(i <= n){
		float res = 1;
		while(j < i){
			mult *= x;//x = 2, y =3, 2*2*2 = 8
			j++;
		}		
		fat = i;
		for(int k = 1;k < i;k++){
			fat*=k;//3! = 3*2*1 = 6
		}
		if(fat == 0){fat = 1;}//0! = 1
		e_x+= mult/fat;
		i+=1;
	}
	cout<<"e^("<<x<<") = "<<e_x;//  Solo para mostrar el valor igual a la calculadora
	return 0;
}