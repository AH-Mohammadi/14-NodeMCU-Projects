#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


ESP8266WebServer server(80);

const char* ssid = "N1";
const char* password ="DON'TDOIT";

int8_t LEDPIN = D7;

String prepareHTML(){
  String html = "<!DOCTYPE html>"
                "<html>"
                "<head>"
                 "<title>Toggle LED</title>"
                "</head>"
                "<body>"
                "<a href='/toggleLED'><button>Toggle LED</button></a>"
                "</body>"
                "</html>";

  return html;
                
  }
//void handleRoot(){
//  server.send(200, "text/html", "HH");
//  
//}

void setup() {

//  server.on("/", handleRoot);
  
  
  WiFi.begin(ssid, password);

  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());
//
//  server.begin();
//  Serial.println("Server Started");
  
}

void loop() {
//  server.handleClient();
  // put your main code here, to run repeatedly:

}
