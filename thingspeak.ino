#include<ESP8266WiFi.h>
#define key "N9BGTP1V9THU6ALD"
const char* host="184.106.153.149";  //ip address of thingspeak server


void setup() {
  Serial.begin(115200);
  Serial.println();
  WiFi.begin("AP1","sourabh@2123");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  Serial.print(WiFi.SSID());
  Serial.println("connected");
  

}

void loop() {
  WiFiClient client;
  if(client.connect(host,80)){
    Serial.println("connected");
    Serial.println("sending request");
    client.print(String("GET /update?key=")+key+"&field1="+String(analogRead(2))+"\r\n\r\n\r\n");  //sending analog value at gpio2 to field1 of thingspeak
    Serial.println("response");
    while(client.connected()){
      if(client.available()){
        String line=client.readStringUntil('\n');         
        Serial.println(line);                      //response
      }
    }
    client.stop();                     //disconnect connection
    Serial.println("disconnected");
  }
  delay(6000);
}
