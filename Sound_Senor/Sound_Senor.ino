#define MicA0 8
int ledPin =13;
int clap =0;
long detection_range =0;
long detection_range_start =0;
boolean status_lights = false;
void setup(){
  pinMode(MicA0,INPUT);
  pinMode(ledPin,OUTPUT);

}

void loop(){
  int status_MicA0 = digitalRead(MicA0);
  if(status_MicA0== 0){
    if(clap ==0){
      detection_range_start= detection_range = millis();
      clap++;
    }
    else if(clap>0 && millis()-detection_range>=50){
      detection_range =millis();
      clap++;
    }
  }
  if(millis()-detection_range_start >=100){
    if(clap==2){
      if(!status_lights){
        status_lights = true;
        digitalWrite(ledPin, HIGH);
        delay(1000);
      }
      else if (status_lights){
        status_lights = false;
        digitalWrite(ledPin,LOW);
      }
    }
    clap =0;

  }
}