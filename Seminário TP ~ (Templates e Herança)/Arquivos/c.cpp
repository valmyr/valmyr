#include<iostream>
using namespace std;
int main(){
    int a[] ={9,8,7,6,5,4,3};

    int i, j ;
    for(i=1; i<7; i++){
       int aux=a[i];
      j=i;
      while(j>0&&a[j-1]>aux) a[j]=a[--j];
      a[j]=aux;
    }
    for(int i = 0; i < 7; i++)
        cout<<a[i];
    return 0;
}