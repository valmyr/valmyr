#include <stdio.h>

int main(void) {

  int n, i = 1, seq_0 = 2, seq_1 = 7, seq_2 = 3;
  printf("Informe o valor de n >> ");
  scanf("%d",&n);
  while(i <= n/3){
    printf("%d, ",seq_0);
    printf("%d, ",seq_1);
    printf("%d",seq_2);
    if(i <= (n/3)-1){
      printf(", ");
    }
    i++;
    seq_0*=2;
    seq_1*=3;
    seq_2*=4;
  }
  printf(".");


  return 0;
}