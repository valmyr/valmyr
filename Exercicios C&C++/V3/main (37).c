#include<iostream>
#include<iomanip>
using namespace std;
void salario(double h, double valorh, double *salario);
int main(){
	double n, h_main, valorh_main,salario_main;
  cin >>n;
  cin >>h_main;
  cin >>valorh_main;

	salario(h_main, valorh_main, &salario_main);

	cout << fixed << setprecision(2);
	cout << "NUMBER = " << n << endl << "SALARY = U$ " << salario_main << endl;

return 0;
}
void salario(double h, double valorh, double *salario){
  *salario = (h * valorh);
}