void red();
void green();
void blue();
void setup() {
  pinMode(13,1);
  pinMode(12,1);
  pinMode(11,1);
  pinMode(8,0);
}
int botao, cont = 0;
void loop() {
  delay(250);
  if(digitalRead(8)){
    cont++;
      delay(250);
  }
  switch(cont){
    case 1:
      red();
      break;
    case 2:
      green();
      break;
    case 3:
      blue();
      break;
    default:
      cont = 1;
      break;   
  }
}

void red(){
      digitalWrite(13,1);
      digitalWrite(12,0);
      digitalWrite(11,0);
}
void green(){
      digitalWrite(13,0);
      digitalWrite(12,1);
      digitalWrite(11,0);  
}
void blue(){
      digitalWrite(13,0);
      digitalWrite(12,0);
      digitalWrite(11,1); 
}
