#include <SoftwareSerial.h> 
#include <gprs.h>
#define GSM_PORT mySerial
SoftwareSerial mySerial(6, 7); // RX, TX
GPRS gprs;

void KirimData()
{
  GSM_PORT.println("AT+CIPSEND");//begin send data to remote server
  delay(4500);
  GSM_PORT.print("POST /?id=123456789");//here is the feed you apply from pachube
      GSM_PORT.print("&lat=");
      GSM_PORT.print("-6.027786");
      GSM_PORT.print("&lon=");
      GSM_PORT.print("106.539520");
      GSM_PORT.print("&timestamp=20");
      GSM_PORT.print("2017");  
      GSM_PORT.print("-");  
      GSM_PORT.print("9"); 
      GSM_PORT.print("-");  
      GSM_PORT.print("23");     
      GSM_PORT.print("T");    
      GSM_PORT.print("18");     
      GSM_PORT.print("%3A");  
      GSM_PORT.print("58"); 
      GSM_PORT.print("%3A");  
      GSM_PORT.print("30");  
      GSM_PORT.print("Z");
      GSM_PORT.print("&hdop="); 
      GSM_PORT.print("1580");     
      GSM_PORT.print("&altitude=");
      GSM_PORT.print("709.60");
      GSM_PORT.print("&speed=");   
      GSM_PORT.print("0.14"); 
      GSM_PORT.print("&heading=");  
      GSM_PORT.print("0.00");               
  GSM_PORT.print(" HTTP/1.1\r\n"); 
  GSM_PORT.print("Host: www.webkudonk.com:6055\r\n");
  GSM_PORT.print("Accept: */*\r\n");
  GSM_PORT.print("Connection: Keep-Alive\r\n");
  GSM_PORT.print("Content-Type: application/x-www-form-urlencoded\r\n");
  GSM_PORT.print("User-Agent: beryindo\r\n");
  GSM_PORT.print("Content-Length: 0\r\n");
  GSM_PORT.print("\r\n");
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  gprs.preInit();
  Serial.println("Lagi Test Post TCP...");
  
  delay(15000);
  while(0 != gprs.init()) {
     delay(1000);
     Serial.println("init error");
  }  
  while(!gprs.join("internet")) {  //change "cmnet" to your own APN
      Serial.println("gprs join network error");
      delay(2000);
  }  
  Serial.print("IP Address is ");
  Serial.println(gprs.getIPAddress());  

  if(0 == gprs.connectTCP("www.gpsindo.web.id", 5055)) {
      Serial.println("connect www.gpsindo.web.id success");
  }else{
      Serial.println("connect error");
      while(1);
  }
  Serial.println("waiting to fetch...");
  KirimData();   
}

void loop() {
  //  KirimData
}
