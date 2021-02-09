#include<iostream>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
int main(){
    map<string,int>mapa;map<string,int>::iterator it;
    cout.precision(4);
    float limite, total = 0;
    string str;
    cin>>limite;
    getchar();
    getchar();
    int con = 0;
    for (int i = 0; i < limite;i++){
            int con = 0;
        while(getline(cin,str)){
            if(str.empty())
                con+=1;
            if(str.empty() and con ==1)
                break;

            if(!str.empty()){
                total++;
                mapa[str]++;
            }
        }
        if(i > 0){
            cout<<endl;
        }
        for(it = mapa.begin(); it != mapa.end(); it++){
            cout<<it->first<<" "<<fixed<<float(it->second*100)/float(total)<<endl;
        }
        mapa.clear();
        total = 0;
    }

    return 0;
}
