#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
float derivada(float n);
int main() {
    srand(time(NULL));
    float y = .2128,x = .01 ,w = (float)(rand()%101)/100,a,e;
    printf("%f\n\n\n",w);
    for(int i = 0; i <1000000; i++){
        a = (float)(exp(w * x) - exp(-w * x))/(exp(w*x)+exp(-x*w));
        e = y-a;//4x1
        w += x * derivada(e);//
                            //4x1
        printf("a = %.5f >> e = %.5f\n",a,e);
    }

    return 0;
}
float derivada(float n){
    return n *(1 - n);
}
