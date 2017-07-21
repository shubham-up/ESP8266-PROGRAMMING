
#include<ESP8266WiFi.h>

WiFiServer server(80);      //WiFiserver object->server ,port is 80
                                 

void setup() {
Serial.begin(115200);
Serial.println();
WiFi.begin("AP1","sourabh@2123");
Serial.print("connecting");
while(WiFi.status()!=WL_CONNECTED){

  delay(500);
  Serial.print(".");
  
}
Serial.println();
server.begin();
Serial.printf("server is started ,open %s in browser/n",WiFi.localIP().toString().c_str());   

}



String htmlpage(){
  String html= String("HTTP/1.1 200 0K\r\n")+"Content-Type:text/html\r\n"+"Connection: close\r\n"+"Refresh:5\r\n"+"\r\n"
              +"<html>"
              +"digital value:"+String(digitalRead(2))+
              "</html>";
   return html;          
  
}

void loop() {
 WiFiClient client=server.available();
 if (client){

   Serial.println("connected");
   while(client.connected()){

        if(client.available()){
            String line=client.readStringUntil('\r');
            Serial.print(line);
            if(line.length()==1&&line[0]=='\n'){
              client.println(htmlpage());
              break;
            }
                
              
        }
   }
   delay(10);
   client.stop();
   Serial.println("disconnected");
 }
 
 
}
