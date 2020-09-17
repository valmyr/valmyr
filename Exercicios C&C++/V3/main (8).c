#include <stdio.h>
#include <math.h>
//diminuir a dimesao da matriz para fica mais bonito 
int main() {
    
float m[4][4];//4x4
int l= 0, c = 0;
    
for(l = 0; l < 4; l++) {
  for(c = 0; c < 4; c++) {
  		if (l < c){          
			m[l][c] = (2 * l) + (7 * c);
		} 		
		else{
			if (l == c){//problema antes estava l = c
				m[l][c] = (pow(l, 2) * 3)- 1;
		    }
			else{
					m[l][c] = (pow(l, 3) * 4) + (pow(c, 2) * 5);
			}
		}	
	}
 }
for(l = 0; l < 4; l++) {
	for(c = 0; c < 4; c++) {
		printf ("[%.2f]	", m[l][c]);
    }
    printf("\n");
}
return 0;
}