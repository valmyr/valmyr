#include<iostream>
#include<math.h>
using namespace std;
int main(){
    char c = 'A';
    cout<<(int)'S'<<endl;
    int i = 0, pos;
    string str;
    cin >> str;
    cin >> pos;
    while(str[i] != '\0'){
        int aux = str[i] - pos;
        cout<<aux<<" "<<str[i]<< endl;
        if(aux>c){
            str[i]-=pos;
            cout<<"1 ";
        }else{
            cout<<"2 ";
            //cout << (char) (90 - pos+1)<<endl;
            if(str[i] == c) {
                str[i] = (char) (90 - pos + 1);
            }else{
                str[i]=(int)fabs(((pos+str[i])));
            }
            cout<<(int)str[i]<<endl;
        }
        i++;
   }
    cout<<str<<endl;
}