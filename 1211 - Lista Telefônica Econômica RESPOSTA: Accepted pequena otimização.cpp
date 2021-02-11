#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;
int main(){
    int n, cont;
    string str1,str2;
    vector<string>s;
    while(cin>>n) {
        cont = 0;
        for(int i = 0; i < n; i++) {
            cin>>str1;
            s.push_back(str1);
        }
        sort(s.begin(),s.end());
        // for(auto i: s){
        //     cout<<i<<endl;
        // }
        str1 = s[0];
        int c = 0;
        for (int j = 1; j < s.size(); j++) {
            for(int k = 0; k < s[j].size(); k++){
                if (s[j][k] == str1[k]) {
                    cont += 1;
                    c++;
                } else {
                        if (str1[c] != s[j][c]){
                            str1 = s[j];
                            break;
                        }
                    break;
                }
            }
            c = 0;
        }
        s.clear();
        cout << cont << endl;
    }
    return 0;
}

