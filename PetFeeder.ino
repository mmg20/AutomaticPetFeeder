#include <Stepper.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <TimeLib.h>

#define BLYNK_PRINT Serial

BlynkTimer timer;


const int stepsPerRevolution = 200;
char auth[] = "xxx";
char ssid[] = "xxx";
char pass[] = "xxx";


Stepper myStepper(stepsPerRevolution, D1, D2, D3, D4);

BLYNK_WRITE(V0)
{
  if(param.asInt() == 1) {
    doFeed();
    
  }
}


BLYNK_WRITE(V2)
{
  if(param.asInt() == 1) {
    doFeed();
  }
}

BLYNK_WRITE(V3)
{
  if(param.asInt() == 1) {
    doFeed();
  }
}


void doFeed() 
 {

  myStepper.step(180);
 myStepper.step(-180);
  
 
   
   
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  
  

   Blynk.virtualWrite(V1, 1000);
   
 }



 
void setup() {
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
myStepper.setSpeed(60);




}

void loop() {
  
  Blynk.run();
  timer.run();
}
