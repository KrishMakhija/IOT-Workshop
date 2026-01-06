int ledPin=11; // PWM Pin
void setup() {
pinMode(11,OUTPUT);
}

void loop() {
  for(int brightness=0;brightness<=255;brightness++){
    analogWrite(ledPin,brightness); //PWM Output
    delay(10);   //Speed Control
  }
  for(int brightness=255;brightness>=0;brightness--){
    analogWrite(ledPin,brightness); //PWM Output
    delay(10);   //Speed Control
  }

}
