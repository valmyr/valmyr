#include <stdio.h>
#include<math.h>
int Decimal_Binario(int n);
int main() {
    int n;
    printf("Informe um numero decimal para efetuar a conversao p/ binario: ");
    scanf("%d",&n);
    for(int i = 0; i <= n; i++)
        printf("\n%d(d) = %d(b)",i,Decimal_Binario(i));
    return 0;
}
int Decimal_Binario(int n){
    //10
    int bin = 0, i = 0;
    while(0 != n){
        bin += (n % 2)*pow(10,i);
        n /= 2;
        n = (int)(n);
        i++;

    }
    return bin;
}