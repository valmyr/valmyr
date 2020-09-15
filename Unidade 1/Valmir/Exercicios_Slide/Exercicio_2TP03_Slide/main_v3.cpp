#include <iostream>
#include <stdlib.h>
using namespace std;
struct Banco{
	float saldo;
	long conta;
	
};
void preencher_conta(Banco *b);
void  preencher_saldo(Banco *b);//preencher o saldo das vite pessoas aleatoriamente
bool v_conta(Banco *b, long ndig);
void deposito(Banco *b, long ndig, float v_deposito);
void saque(Banco *b, long ndig, float v_saque);
int main(){
	srand(time(NULL));
	cout.precision(2);
	long num_conta;float v_saque;
	Banco *usuarios = (Banco*)malloc(sizeof(Banco)*20);//vetor alocado dinamicamente na memoria heap
	preencher_conta(usuarios);
	preencher_saldo(usuarios);
	char op;
	char op1;
	do{
    	cout<<"Deseja sacar/depositar/ver saldo? [S/D/V]";
    	cin>>op;
    	op = toupper(op);
    if(op == 'S' || op =='D'|| op == 'V')break;
    }while(true);
    do{
    	cout<<"Informe sua conta: ";
    	cin>>num_conta;
    	if(v_conta(usuarios, num_conta))break;
    	else cout<<"Conta invalida"<<endl;
    }while(true);
    if(op == 'S'){
    	cout<<fixed<<"Saldo atual: R$"<<usuarios[num_conta-1].saldo<<endl;
    	do{
    		cout<<"Valor do saque: R$";
    		cin>>v_saque;
    		if(v_saque<=usuarios[num_conta-1].saldo)break;
    		else{
    			cout<<"Saque nao autorizado"<<endl;
    			do{
    				cout<<"Novo valor/Cancelar [N/C]: ";
    				cin>>op1;
    				op1 = toupper(op1);
    				if(op1 == 'N' || op1 == 'C')break;   				
    			}while(true);
    		}
    		if(op1=='C')break;
    	}while(true);
    	if(op1 == 'N'){
          	cout<<"Saque autorizado"<<endl;
    	     saque(usuarios,num_conta,v_saque);
    	     cout<<fixed<<"Saldo atual: R$"<<usuarios[num_conta-1].saldo<<endl;
    	}
    }else if(op == 'D'){
    	float v_deposito;
    	cout<<fixed<<"Saldo atual: R$"<<usuarios[num_conta-1].saldo<<endl;
    	cout<<"Valor do deposito R$"; cin>>v_deposito;
    	deposito(usuarios,num_conta,v_deposito);
    	cout<<"Deposito finalizado."<<endl;
    	cout<<fixed<<"Saldo atual: R$"<<usuarios[num_conta-1].saldo<<endl;
    	
    }else{
    	cout<<fixed<<"Saldo atual: R$"<<usuarios[num_conta-1].saldo<<endl;
    }
    return 0;
}


void  preencher_saldo(Banco *b){
	for(int i =0;i < 20;i++)
		b[i].saldo = rand()%10001;
}
void preencher_conta(Banco *b){
	for(int i =0;i < 20;i++)
		b[i].conta = i+1;
}
bool v_conta(Banco *b, long ndig){
	for(int i = 0; i < 20;i++)
		if(b[i].conta == ndig)
			return 1;
	return 0;
}
void deposito(Banco *b, long ndig, float v_deposito){
	b[ndig-1].saldo+=v_deposito;
}
void saque(Banco *b, long ndig, float v_saque){
		b[ndig-1].saldo-=v_saque;
}
