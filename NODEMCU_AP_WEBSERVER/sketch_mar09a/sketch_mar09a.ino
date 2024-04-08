#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


// Use node MCU as Access Poin (Wifi Master)

const char* ssid = "NodeWifi";
const char* pasw = "N1999N12";

ESP8266WebServer server(80); 

void handleRoot(){
  
  server.send(200, "text/plain", "Hello from NodeMCU!");
  
}

void setup() {
  Serial.begin(9600);
  
  Serial.println("Your Wifi started");
  WiFi.softAP(ssid, pasw);

  IPAddress IP = WiFi.softAPIP();
  Serial.println("YOuWifi IP IS");
  Serial.println(IP);
  server.begin();
  server.on("/", handleRoot);

  Serial.println("Your webserver Started");
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
