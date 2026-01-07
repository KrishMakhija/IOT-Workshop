int ir = 7;
int led = 13 ;
int buz = 12;
int x ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(ir);
  Serial.println(x);
  delay(200);
  if(x==1)
  {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
  }
  else
  {
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
  }
}
