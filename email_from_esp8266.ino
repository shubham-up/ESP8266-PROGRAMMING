#include<ESP8266WiFi.h>

const char* host="152.163.0.69";           //ip adress of aol server
WiFiClient client;

void setup() {
  Serial.begin(115200);
  Serial.println();
  WiFi.begin("AP1","sourabh@2123");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print(WiFi.SSID());
  Serial.println("connected");
  

}

void loop() {
  
  if(client.connect(host,587)){
    Serial.println("connected");
    Serial.println("sending helo");
    client.println("HELO 192.168.43.243");
    response();
    Serial.println("sending auth login");
    client.println("AUTH LOGIN");
    response();
    client.println("c2FjaGluX3VwYWRoeWF5QGFvbC5jb20=");  //aol username
    response();
    client.println("U2h1YmhhbV8xMjM0");                //aol password
    response();
    client.println("MAIL FROM:<sachin_upadhyay@aol.com>");
    response();
    client.println("RCPT TO:<upadhyaysachin92@gmail.com>");
    response();
    Serial.print("sending data");
    client.println("DATA");
    response();
    client.println("From: sachin_upadhyay@aol.com <sachin_upadhyay@aol.com>");
    response();
    client.println("To: upadhyaysachin92@gmail.com <upadhyaysachin@gmail.com>");
    response();
    client.println("Subject: analog");
    response();
    client.printf("analog input:%d\n",analogRead(2));
    client.println(".");
    response();
    client.println("QUIT");
    response();
    client.stop();
    Serial.println("disconnected");
  }
  delay(6000);
}

void response(){
 
    while(client.available()){
      String line=client.readStringUntil('\n');
      Serial.println(line);
    }
  }


