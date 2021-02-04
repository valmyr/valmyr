#include<iostream>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
int main(){
    cout.precision(4);
    map<string,int>mapa;map<string,int>::iterator it;
    float limite, total = 1;
    string str;
    cin>>limite;
    char c;
    cin>>c;
    cin.ignore(256,'\n');
    for (int i = 0; i < limite;i++){
        while(getline(cin,str)){
            if(str.empty())
                break;
            total+=1;
            try{
                mapa[str]++;
            }catch(const char &e){
                mapa[str] = 1;
            }
        }
        if(i > 1){
            cout<<"\n";
        }
        for(it = mapa.begin(); it != mapa.end(); it++){
            cout<<it->first<<" "<<fixed<<float(it->second*100)/float(total)<<endl;
        }
        mapa.clear();
        total = 0;
    }

    return 0;
}
