#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid= "N1";
const char* password= "DON'TDOIT";

ESP8266WebServer server(80);

void handleRoot(){
  server.send(200, "text/plain", "Hello Brother.");
}

void setup() {
  
  WiFi.begin(ssid, password);
  server.on("/", handleRoot);
  
  Serial.println("Connnecting To N1");
  Serial.println(ssid);

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }

  Serial.println("Connected");
  Serial.print("Wifi Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("SERVER STARTED");
  
  
  // put your setup code here, to run once:
  

}

void loop() {

  server.handleClient();
  // put your main code here, to run repeatedly:

}
