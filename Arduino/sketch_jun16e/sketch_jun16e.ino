int Array[7] = {2,3,4,5,6,7};
void acender(int x);
void setup(){
  for(int i = 0; i < 6; i++){
    pinMode(Array[i],1);
  }
  pinMode(A1,0);
}
void acender(int x){
  for(int i = 0; i < x; i++){
    digitalWrite(Array[i],1);
  }
  for(int i = x; i < 6; i++){
    digitalWrite(Array[i],0);
  }
}
void loop(){
  int a = analogRead(A1);
  acender(map(a,0,1023,0,6));
}
