#include <ESP8266WiFi.h> 
  
  const char* ssid = "N1";
  const char* password = "DON'TDOIT";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  Serial.print("Connecting To ");

  Serial.print(ssid);

  while(WiFi.status() != WL_CONNECTED){ 
       Serial.print(".");
       delay(1000);
       
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());
  }

bool isWifiConnected(){
  return WiFi.status() == WL_CONNECTED;
}


void loop() {
  
  if(isWifiConnected()){
    delay(200);
    Serial.println("YOU ARE CONNECTED TO THE INTERNET");
  }
  else {

        delay(200);

        Serial.println("YOU ARE NOT CONNECTED TO THE INTERNET");

    
  }

}
