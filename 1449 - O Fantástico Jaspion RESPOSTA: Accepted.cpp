#include<iostream>
#include<map>
#include<vector>
#include <sstream>
using namespace std;
vector<string>customSplit(string);
int main(){
    int t, m, n;
    string portugues, japones;
    map<string,string>dicionario;
    map<string,string>::iterator it;

    string traducao ="";
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>m>>n;
        cin.ignore();
        if(i > 0)
            cout<<endl;        
        for(int j = 0; j < m; j++){
            getline(cin,japones);
            getline(cin,portugues);
            dicionario[japones] = portugues;
        }
        for(int k = 0 ; k < n; k++){
            getline(cin,japones);
            vector<string>v = customSplit(japones);
            int sizeV = v.size();
            for(int i = 0; i < sizeV-1; i++){
                auto res = dicionario.find(v[i]);
                if(res == dicionario.end())
                    cout<<v[i]<<" ";
                else
                    cout<<dicionario[v[i]]<<" ";
            }
            auto  res = dicionario.find(v[v.size()-1]);
            if(res == dicionario.end())
                   cout<<v[v.size()-1]<<endl;
            else
                   cout<<dicionario[v[v.size()-1]]<<endl;
            v.clear();        
        }
        dicionario.clear();

    }
    cout<<endl;
    return 0;
}
vector<string>customSplit(string str){
    stringstream s(str);
    string temp;
    vector<string>v;
    while(getline(s,temp,' ')){
        v.push_back(temp);
    }
    return v;
}
