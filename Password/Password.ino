String input;
#define led 13
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  Serial.println("Enter your Password:");
}

void loop() {
  if(Serial.available()>0){
  input = Serial.readString();
  input.trim();

  if(input=="Koushal"){
    digitalWrite(led, HIGH);
    
    Serial.println("Correct Password");
  }

  else{
    Serial.println("Incorrect Password");
    digitalWrite(led,LOW);
  }
  }
}
