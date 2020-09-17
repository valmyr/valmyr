int Arrey[] = {4,5,6,7,2,3};
void setup(){
  for(int i = 0; i < 6; i++){
    pinMode(Arrey[i],HIGH);
  }
}
void loop(){
        digitalWrite(Arrey[4],1);
        digitalWrite(Arrey[5],1);
  int v[4], v2[4];
          int c = 0;
      for(int i = 0; i < 100; i++){
        int d = i%10;
        if(i > 9)c = (int)i/10;
        for(int j = 0; j< 4; j++){
            v[j] = d&1; 
           d/=2;
        }
        for(int k = 0; k< 4; k++){
            v2[k] = c&1; 
           c/=2;
        }
        digitalWrite(Arrey[4],0);
        digitalWrite(Arrey[5],1);
        digitalWrite(Arrey[3],v[0]);
        digitalWrite(Arrey[2],v[1]);
        digitalWrite(Arrey[1],v[2]);
        digitalWrite(Arrey[0],v[3]);
        delay(50);
        digitalWrite(Arrey[4],1);
        digitalWrite(Arrey[5],0);
        
        digitalWrite(Arrey[3],v2[0]);
        digitalWrite(Arrey[2],v2[1]);
        digitalWrite(Arrey[1],v2[2]);
        digitalWrite(Arrey[0],v2[3]);
        delay(50);
      }


}
