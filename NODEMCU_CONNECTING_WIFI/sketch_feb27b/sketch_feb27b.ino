#include <ESP8266WiFi.h>

const char* ssid = "N1";
const char* password = "DON'TDOIT";

  char ledPIN = 16;


void setup() {


  pinMode(ledPIN, OUTPUT);
  
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  
  Serial.print("Conneting To wifi ");
  Serial.print(ssid);

  while(WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }

  Serial.println("Connected");

  Serial.println(WiFi.localIP());

  
  
  // put your setup code here, to run once:

}

void loop() {

  if(WiFi.status()== WL_CONNECTED){
    delay(500);
    digitalWrite(ledPIN, HIGH);
    delay(500);

    digitalWrite(ledPIN, LOW);
    
  }

  else{
    delay(100);
    digitalWrite(ledPIN, HIGH);
    delay(100);

    digitalWrite(ledPIN, LOW);
  }
  // put your main code here, to run repeatedly:

  
}
