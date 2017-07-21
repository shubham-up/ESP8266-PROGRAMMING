#include<ESP8266WiFi.h>
#include<ESP8266WiFiMulti.h>
ESP8266WiFiMulti wifimulti;
boolean connctionwasalive=true;


void setup() {
  
  Serial.begin(115200);
  Serial.println();
  wifimulti.addAP("AP1","sourabh@2123");        //SSID1,PASSWORD1
  wifimulti.addAP("AP2","sachin@123");          //SSID2,PASSWORD2

}

void loop() {
  
  if(wifimulti.run()!=WL_CONNECTED)          //IF NO NETWORK IS  CONNECTED
      Serial.println("waiting for AP");
  else if(wifimulti.run()==WL_CONNECTED)
      Serial.println(WiFi.SSID());   

}
