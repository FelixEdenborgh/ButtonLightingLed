#include <ESP8266WiFi.h>
#include <String.h>
#include <ESP8266WebServer.h>
#include "Functions.h"
#include "Config.h"
int LED_PIN = 16;


ESP8266WebServer myserver(80); // port 80 = HTTP, port 443 = HTTPS(Kräver SSL-certifikat)
void showText(){
  //200 = OK, 201 = Created, 403 = Forbidden, 404 = Not Found, 500 = Internal Server error, Status codes 
  myserver.send(200, "text/html", "<!DOCTYPE html><html><head lang='sv'><meta charset='utf-8'><link rel='Stylesheet' href='Stylesheet.css'><title>On/Off</title></head><body><h2>Button</h2><form id='buttonOn' action='LEDON'><input class='buttonOn' type='submit' value='LED ON' ></form> <form id='buttonOff' action='LEDOFF'><input class='buttonOff' type='submit' value='LED OFF' ></form> </body></html>");
}

String request = "";
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  initWifi(ssid, pass);
  myserver.on("/", showText); 
  myserver.begin();
  
  
}

void loop() {
  myserver.handleClient();
  ESP8266WebServer client = myserver.available();
  if(!client) { return; }

  

  if(request.indexof("LEDON") > 0){
    digitalWrite(LED_PIN, HIGH);
  }
  else if(request.indexof("LEDOFF") > 0){
    digitalWrite(LED_PIN, LOW);
  }
  delay(1000);








  
}
