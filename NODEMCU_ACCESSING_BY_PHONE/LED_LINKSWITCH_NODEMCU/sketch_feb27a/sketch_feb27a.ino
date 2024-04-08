#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h>
//  Program That Switch An LED With A button from a web page
ESP8266WebServer server(80);

  int8_t LEDPIN = D5;
  bool LEDSTATUS= LOW;
  const char* ssid = "N1";
  const char* password = "DON'TDOIT";

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
void handleRoot() {
  server.send(200, "text/html", prepareHTML()); // Send a simple response
}

void switchLED(){
   LEDSTATUS = !LEDSTATUS;
   digitalWrite(LEDPIN, LEDSTATUS);
   server.send(200, "text/html", prepareHTML());
}
void setup() {

  pinMode(LEDPIN, OUTPUT);
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
  server.on("/", handleRoot);
  server.on("/toggleLED", switchLED);

  
  server.begin();
  Serial.println("Server Started");
  }

bool isWifiConnected(){
  return WiFi.status() == WL_CONNECTED;
}


void loop() {
server.handleClient();


}
