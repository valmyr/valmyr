#define LDR A0
#define LED_13 13
int LDR_ = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LDR,0);
  pinMode(LED_13,1);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  LDR_ = analogRead(LDR);
  Serial.println(LDR_);
  if(LDR_ >= 500){
    digitalWrite(LED_13,1);
  }else{
    digitalWrite(LED_13,0);
  }
  delay(100);
}
