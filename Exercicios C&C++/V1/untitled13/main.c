#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define GNUPLOT "gnuplot --persist"
int main() {
    srand(time(NULL));
    FILE *fp;
    fp = fopen("oba.txt","w");
    float x, y, N_Chutes = 10,raio, m = 0,pi;
/*    printf("Informe a quantidade de pontos aleatorios>>");
    scanf("%f",&N_Chutes);*/
    for(int i = 0; i <= N_Chutes; i++){
        x = (float)(rand()%101)/100;
        y = (float)(rand()%101)/100;
        raio = sqrt(pow(x,2) + pow(y,2));
        m += raio <=1? 1 : 0;
        pi = 4 * m/N_Chutes;
        fprintf(fp,"x y pi");
    }
    printf("%f",pi);
    fclose(fp);
    return 0;
}
