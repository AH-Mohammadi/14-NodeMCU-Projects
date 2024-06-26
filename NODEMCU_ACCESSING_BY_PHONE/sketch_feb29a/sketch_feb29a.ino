#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "N1";
const char* password ="DON'TDOIT";

uint8_t LEDPIN = D7;
bool LEDStatus = LOW;

uint8_t BUZZPIN = D1;
bool buzzStatus = LOW;

String prepareHTML() {
  String html  = "<!DOCTYPE html>"
                 "<html>"
                 "<head>"
                 "<meta charset=\"UTF-8\">"
                 "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
                 "<title>NodeMCU ESP8266 Web Server</title>"
                 "<style>"
                 "/* Copyright 2014 Owen Versteeg; MIT licensed */body,textarea,input,select{background:0;border-radius:0;font:16px sans-serif;margin:0}.smooth{transition:all .2s}.btn,.nav a{text-decoration:none}.container{margin:0 20px;width:auto}label>*{display:inline}form>*{display:block;margin-bottom:10px}.btn{background:#999;border-radius:6px;border:0;color:#fff;cursor:pointer;display:inline-block;margin:2px 0;padding:12px 30px 14px}.btn:hover{background:#888}.btn:active,.btn:focus{background:#777}.btn-a{background:#0ae}.btn-a:hover{background:#09d}.btn-a:active,.btn-a:focus{background:#08b}.btn-b{background:#3c5}.btn-b:hover{background:#2b4}.btn-b:active,.btn-b:focus{background:#2a4}.btn-c{background:#d33}.btn-c:hover{background:#c22}.btn-c:active,.btn-c:focus{background:#b22}.btn-sm{border-radius:4px;padding:10px 14px 11px}.row{margin:1% 0;overflow:auto}.col{float:left}.table,.c12{width:100%}.c11{width:91.66%}.c10{width:83.33%}.c9{width:75%}.c8{width:66.66%}.c7{width:58.33%}.c6{width:50%}.c5{width:41.66%}.c4{width:33.33%}.c3{width:25%}.c2{width:16.66%}.c1{width:8.33%}h1{font-size:3em}.btn,h2{font-size:2em}.ico{font:33px Arial Unicode MS,Lucida Sans Unicode}.addon,.btn-sm,.nav,textarea,input,select{outline:0;font-size:14px}textarea,input,select{padding:8px;border:1px solid #ccc}textarea:focus,input:focus,select:focus{border-color:#5ab}textarea,input[type=text]{-webkit-appearance:none;width:13em}.addon{padding:8px 12px;box-shadow:0 0 0 1px #ccc}.nav,.nav .current,.nav a:hover{background:#000;color:#fff}.nav{height:24px;padding:11px 0 15px}.nav a{color:#aaa;padding-right:1em;position:relative;top:-1px}.nav .pagename{font-size:22px;top:1px}.btn.btn-close{background:#000;float:right;font-size:25px;margin:-54px 7px;display:none}@media(min-width:1310px){.container{margin:auto;width:1270px}}@media(max-width:870px){.row .col{width:100%}}@media(max-width:500px){.btn.btn-close{display:block}.nav{overflow:hidden}.pagename{margin-top:-11px}.nav:active,.nav:focus{height:auto}.nav div:before{background:#000;border-bottom:10px double;border-top:3px solid;content:'';float:right;height:4px;position:relative;right:3px;top:14px;width:20px}.nav a{padding:.5em 0;display:block;width:50%}}.table th,.table td{padding:.5em;text-align:left}.table tbody>:nth-child(2n-1){background:#ddd}.msg{padding:1.5em;background:#def;border-left:5px solid #59d}"
                 ".hero {"
                 "background: #eee;"
                 "padding: 20px;"
                 "border-radius: 10px;"
                 "margin-top: 1em;"
                 "}"
                 ".hero h1 {"
                 "margin-top: 0;"
                 "margin-bottom: 0.3em;"
                 "}"
                 ".c4 {"
                 "padding: 10px;"
                 "box-sizing: border-box;"
                 "}"
                 ".c4 h3 {"
                 "margin-top: 0;"
                 "}"
                 ""
                 "// Code from https://proto.io/freebies/onoff/"
                 ".c4 a {"
                 "margin-top: 10px;"
                 "display: inline-block;"
                 "}"
                 ""
                 ".onoffswitch {"
                 "position: relative; width: 90px;"
                 "-webkit-user-select:none; -moz-user-select:none; -ms-user-select: none;"
                 "}"
                 ".onoffswitch-checkbox {"
                 "position: absolute;"
                 "opacity: 0;"
                 "pointer-events: none;"
                 "}"
                 ".onoffswitch-label {"
                 "display: block; overflow: hidden; cursor: pointer;"
                 "border: 2px solid #999999; border-radius: 20px;"
                 "}"
                 ".onoffswitch-inner {"
                 "display: block; width: 200%; margin-left: -100%;"
                 "transition: margin 0.3s ease-in 0s;"
                 "}"
                 ".onoffswitch-inner:before, .onoffswitch-inner:after {"
                 "display: block; float: left; width: 50%; height: 30px; padding: 0; line-height: 30px;"
                 "font-size: 14px; color: white; font-family: Trebuchet, Arial, sans-serif; font-weight: bold;"
                 "box-sizing: border-box;"
                 "}"
                 ".onoffswitch-inner:before {"
                 "content: \"ON\";"
                 "padding-left: 10px;"
                 "background-color: #34A7C1; color: #FFFFFF;"
                 "}"
                 ".onoffswitch-inner:after {"
                 "content: \"OFF\";"
                 "padding-right: 10px;"
                 "background-color: #EEEEEE; color: #999999;"
                 "text-align: right;"
                 "}"
                 ".onoffswitch-switch {"
                 "display: block; width: 18px; margin: 6px;"
                 "background: #FFFFFF;"
                 "position: absolute; top: 0; bottom: 0;"
                 "right: 56px;"
                 "border: 2px solid #999999; border-radius: 20px;"
                 "transition: all 0.3s ease-in 0s;"
                 "}"
                 ".onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-inner {"
                 "margin-left: 0;"
                 "}"
                 ".onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-switch {"
                 "right: 0px;"
                 "}"
                 ""
                 ".grid-container {"
                 "display: grid;"
                 "grid-template-columns: 1fr 1fr;"
                 "grid-gap: 20px;"
                 "}"
                 ""
                 ".flex-container {"
                 "display: flex;"
                 "margin-top: 40px;"
                 "}"
                 ".flex-child {"
                 "flex: 1;"
                 "//border: 2px solid yellow;"
                 "}"
                 ".flex-child:first-child {"
                 "margin-right: 20px;"
                 "}"
                 ""
                 ".component-label{"
                 "float: right;"
                 "font-weight: bold;"
                 "font-size: 25px;"
                 "}"
                 "</style>"
                 "</head>"
                 "<body>"
                 "<nav class=\"nav\" tabindex=\"-1\" onclick=\"this.focus()\">"
                 "<div class=\"container\">"
                 "<a class=\"pagename current\" href=\"#\">Amir</a>"
                 "</div>"
                 "</nav>"
                 ""
                 "<div class=\"container\">"
                 "<div class=\"hero\">"
                 "<h1>NodeMCU ESP8266 Web Server</h1>"
                 "<div class=\"flex-container\">"
                 "  <div class=\"flex-child magenta\">"
                 "<span class=\"component-label\">LED</span>"
                 "  </div>"
                 "  <div class=\"flex-child green\">"
                 "<div class=\"grid-child green\">"
                 "<div style=\"display: inline\">"
                 "<div class=\"onoffswitch\">";
  if (LEDStatus)
    html = html + "<input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"ledSwitch\" tabindex=\"0\" checked onclick=\"window.location.href='toggleLED'\">";
  else
    html = html + "<input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"ledSwitch\" tabindex=\"0\" onclick=\"window.location.href='toggleLED'\">";

  html = html +
         "<label class=\"onoffswitch-label\" for=\"ledSwitch\">"
         "<span class=\"onoffswitch-inner\"></span>"
         "<span class=\"onoffswitch-switch\"></span>"
         "</label>"
         "</div>"
         "</div>"
         "</div>"
         "  </div>"
         "</div>"
         "<div class=\"flex-container\">"
         "  <div class=\"flex-child magenta\">"
         "<span class=\"component-label\">Buzzer</span>"
         "  </div>"
         "  <div class=\"flex-child green\">"
         "<div class=\"grid-child green\">"
         "<div style=\"display: inline\">"
         "<div class=\"onoffswitch\">";
  if (buzzStatus)
    html = html + "<input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"buzzerSwitch\" tabindex=\"0\" checked onclick=\"window.location.href='toggleBuzzer'\">";
  else
    html = html +     "<input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"buzzerSwitch\" tabindex=\"0\" onclick=\"window.location.href='toggleBuzzer'\">";

  html = html +
         "<label class=\"onoffswitch-label\" for=\"buzzerSwitch\">"
         "<span class=\"onoffswitch-inner\"></span>"
         "<span class=\"onoffswitch-switch\"></span>"
         "</label>"
         "</div>"
         "</div>"
         "</div>"
         "  </div>"
         "</div>"
         "</div>"
         "</div>"
         "</body>"
         "</html>";

  return html;
}


void handleRoot() {
    server.send(200, "text/html", prepareHTML());
  
}

void updateLED(){
  Serial.println("Updating LED Status");
  LEDStatus = !LEDStatus;
  digitalWrite(LEDPIN, LEDStatus);
  server.send(200, "text/html", prepareHTML());
  
}

void updateBuzzerSound(){
  Serial.println("Updating Buzzer Sound");

  buzzStatus = !buzzStatus;
  digitalWrite(BUZZPIN, buzzStatus);
  server.send(200, "text/html", prepareHTML());
  
}

void handleNotFound() {
  server.send(200, "text/plain" "404");
  
}





void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZPIN, OUTPUT);

  
  // put your setup code here, to run once:
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
    
  }

  Serial.println("Connected to");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/toggleLED", updateLED);
  server.on("/toggleBuzzer", updateBuzzerSound);

  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Server Started");
}



void loop() {
  server.handleClient();
  // put your main code here, to run repeatedly:

}
