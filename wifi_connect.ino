#include<ESP8266WiFi.h>


void setup() {
 
  Serial.begin(115200);
  Serial.println();
  WiFi.begin("AP1","sourabh@2123");
  Serial.print("connecting ");
  while(WiFi.status()!=WL_CONNECTED)
  { 
    delay(500);
    Serial.print(".");
    
  }
  Serial.println("connected");
  Serial.println(WiFi.localIP());      //ip address assigned to esp8266
  Serial.print(WiFi.RSSI());          //received  signal strength indication in dbm
  }



void loop() {

}
