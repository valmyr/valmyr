#include <stdio.h>
int palidromos(int n);
int main(void) {
    printf("%d",palidromos(123));
}
int palidromos(int n){
    int Inver = 0, b = 10;
    while(n != 0){
        Inver *= (n % 10)*10;
        n /= 10;
    }
    return Inver;
}