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
        str1 = s[0];
        for (int j = 1; j < s.size(); j++) {
            for(int k = 0; k < s[j].size(); k++){
                if (s[j][k] == str1[k]) {
                    cont += 1;
                } else {
                    for(int l = 0; l <= cont; l++)
                        if (str1[l] != s[j][l]){
                            str1 = s[j];
                            break;
                        }
                    break;
                }
            }
        }
        s.clear();
        cout << cont << endl;
    }
    return 0;
}

