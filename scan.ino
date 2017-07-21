#include<ESP8266WiFi.h>

String ssid;
uint8_t encryptiontype;  //UNSIGNED INT OF WIDTH 8 BITS
int32_t rssi;
int32_t channel;
uint8_t* bssid;
bool ishidden;
void setup() {
 
Serial.begin(115200);
Serial.println();
WiFi.mode(WIFI_STA);
WiFi.disconnect();
delay(100);
int n=WiFi.scanNetworks(false,true);
for(int i=0;i<n;i++){
 
  WiFi.getNetworkInfo(i,ssid,encryptiontype,rssi,bssid,channel,ishidden);  //PARAMETERS ARE PASSED BY REFERENCE
  Serial.printf("%d:%s,ch:%d (%ddbm) %s %s\n",i+1,ssid.c_str(),channel,rssi,encryptiontype==ENC_TYPE_NONE?"OPEN":" ",ishidden?"hidden":" ");
}

}

void loop() {
  

}
