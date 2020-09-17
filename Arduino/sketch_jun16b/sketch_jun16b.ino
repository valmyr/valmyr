#define LED_11 11
#define Max_ 255
#define Min_ 0
#define Delay_ 10


void setup() {
  pinMode(LED_11, 1);
}

void loop() {
  for(int i = Min_; i <= Max_; i++){
    delay(Delay_);
    analogWrite(LED_11,i);
  }

}
