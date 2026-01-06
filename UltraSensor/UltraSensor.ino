int triPin = 10;
int echoPin = 9;
int ledPin =12;

long time;
int distance;

void setup() {
  pinMode(triPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(echoPin,INPUT);

  Serial.begin(9600);

}

void loop() {
  digitalWrite(triPin,LOW);
  delayMicroseconds(2);

digitalWrite(triPin,HIGH);
delayMicroseconds(10);
digitalWrite(triPin,LOW);

//Speed
time = pulseIn(echoPin,HIGH);

distance = time*0.034 / 2;

Serial.print("Distance:");
Serial.print(distance);
Serial.print("cm");
Serial.println("");

if(distance <= 10) {
  digitalWrite(ledPin, HIGH);

}
else {
  digitalWrite(ledPin,LOW);
}
delay(500);
}
