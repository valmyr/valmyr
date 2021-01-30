class Ultrasonic{
   private:
      int trig;
      int echo;
    public:
      Ultrasonic(int trig = 0, int echo = 0);
      float distanciaEmCM();
};
Ultrasonic::Ultrasonic(int trig, int echo){
  this->trig = trig;
    this->echo = echo;
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    digitalWrite(this->trig,LOW);
}
float Ultrasonic::distanciaEmCM(){
    digitalWrite(this->trig,HIGH);
    delayMicroseconds(10);
  	digitalWrite(this->trig,LOW);
    return (pulseIn(this->echo,HIGH)/2)*0.034;
}
Ultrasonic sensorDePresenca(13,12);
void setup(){
    Serial.begin(9600);
}
void loop(){
  Serial.println(sensorDePresenca.distanciaEmCM());
}
