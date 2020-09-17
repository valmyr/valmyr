int portas_iniciadas[] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,A5};

void setup() {
  for(int i = 0; i < 15; i++){
    pinMode(portas_iniciadas[i],OUTPUT);
    digitalWrite(portas_iniciadas[i],LOW);
  }

}
void acender(int n , int k, int delay_){
  int temp = n;
  for(int i = 0; i < k; i++){
    digitalWrite(portas_iniciadas[n],HIGH);
    n++;
  }
  delay(delay_);
    for(int i = 0; i < k; i++){
    digitalWrite(portas_iniciadas[temp],LOW);
    temp++;
  }
  delay(delay_);
}

void loop() {
  int k = 0, i = 1;
  while(k < 15){
    for(int i = 0; i < 15-k; i++){
      acender(i,k+1,25*(k+1));
    }
    for(int i = 14-k; i >= 0; i--){
      acender(i,k+1,25*(k+1));
    }
    k++;
  }

}
