#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
class numeros{
	vector<int> n;
	public:
	numeros (){}
	void addnum(int nk){
		n.push_back(nk);
	}
	void salva(){
		fstream a;
		int i = 0;
		a.open("t.txt",ios::out|ios::binary);
		a.write(reinterpret_cast<char *>(&n),n.size()*sizeof(int));
		cout<<i<<endl;
		a.close();
	}

	void r(){
		fstream a;
		int i = 0;
		a.open("d.dat",ios::in|ios::binary);
		while(a.read(reinterpret_cast<char *>(n[i]),sizeof(n[i]))){
			i++;
		}
		a.close();
	}
	void im(){
		cout<<sizeof(n.size())<<endl<<endl;
		for(int i = 0;i < int(n.size());i++)
		     cout<<n[i]<<endl;
	}

};
int main(){
	srand(time(NULL));
	numeros n,y;
	for(int i = 0; i <109; i++)
	n.addnum(rand()%100);
	n.salva();
	n.im();

  return 0;
}
