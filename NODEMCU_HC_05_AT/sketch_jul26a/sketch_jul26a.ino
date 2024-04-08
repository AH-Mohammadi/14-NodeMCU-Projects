#include <SoftwareSerial.h>

#define keyPin 4
#define pin12 12;

SoftwareSerial BTSerial(2,3);

void setup() {

  Serial.begin(9600);

  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

  pinMode(keyPin, OUTPUT);
  digitalWrite(keyPin, HIGH);
  
  Serial.println("Enter AT commands:");

  BTSerial.begin(38400);

  
  // put your setup code here, to run once:
  
}

void loop() {

  if(BTSerial.available())
  Serial.write(BTSerial.read());

  if(Serial.available())
  BTSerial.write(Serial.read());

  

  


    
  // put your main code here, to run repeatedly:

}
