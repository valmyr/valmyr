#include<iostream>

using namespace std;

int main (){
	
	int filas = 0;
	int columnas = 0;
	int matriz [200][200];
	int somatorio_matriz = 0, somatorio_transp = 0;
	
	//Ingreso de filas y coumnas deseadas
		cout<<"Ingrese el numero de filas que desea: ";
		cin>>filas;
		cout<<"Ingrese el numero de columnas que desea: ";
		cin>>columnas;
		
			//Relleno de matriz
			for (int i = 0; i < filas; i++){
				for(int j = 0; j < columnas; j++){
					cout<<"\n[ " << i << " - " << j << "] :";
					cin>>matriz[i][j];
					cout<<endl;
				}
			}
	
			//matriz normal
			cout<<"\nMatriz Normal: "<<endl;
	
					for (int i = 0; i < filas; i++){
						for(int j = 0; j < columnas; j++){
						cout<<matriz[i][j]<<" ";
					}
						cout<<endl;
					}
	
			//matriz tanspuesta
			cout<<"\nMatriz transpuesta: "<<endl;
			
				for (int i= 0; i < columnas; i++){
					for(int j = 0; j < filas; j++){
						cout<<matriz[j][i]<<" ";
					}
						cout<<endl;
				}
				
				for (int i = 0; i < columnas; i++)
					somatorio_matriz+=matriz[0][i];
				
			    for (int i = 0; i < filas; i++)
				   somatorio_transp+=matriz[i][0];
				cout<<endl;
				cout<<somatorio_matriz<<endl;
				cout<<somatorio_transp<<endl;
}
