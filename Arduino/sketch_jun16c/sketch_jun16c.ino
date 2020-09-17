#define LED_8 8
#define Button_11 11
void On();
void setup() {
  pinMode(LED_8,1);
  pinMode(Button_11,0);
}
void loop() {
  if(digitalRead(Button_11)){
    On();
  }
}
void On(){
  digitalWrite(LED_8,1);
  if(!digitalRead(Button_11)){
    digitalWrite(LED_8,0);
  }
}
