#include <iostream>

using namespace std;

int main() {

    {
        int n = 1, k = 1, j = 0, *v;
        cin>>n;
        cin>>k;
        k--;
        j = k;
        cout<<j<<endl;
        v = (int*)malloc(sizeof(int)*n);
        for(int i = 1; i <= n; i++){
            v[i-1] = i;
        }
        for(int i = 0; i < n; i++){
            if(v[k]){
                v[k] = 0;
            }
            cout<<v[i]<<" ";
            if(k > 5)k = j;

        }
        for(int i = 0; i < n; i++){
            if(v[i]){
                cout<<"\n"<<v[i]<<" ";
            }
        }
    }

    return 0;
}