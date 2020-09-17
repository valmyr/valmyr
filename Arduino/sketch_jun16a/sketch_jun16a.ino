int LED_RED = 9, LED_GREEN = 10, LED_YELLOW = 11;
void RED(int delay_);
void GREEN(int delay_);
void YELLOW(int delay_);
void setup(){
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
}
void loop(){
  RED(3000);
  GREEN(5000);
  YELLOW(1000);

}
void RED(int delay_){
  delay(delay_);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
}
void GREEN(int delay_){
  delay(delay_);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW, LOW);
}
void YELLOW(int delay_){
  delay(delay_);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  
}
