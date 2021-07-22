#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>  
byte ID = 0;  
int data = 0;
int data2 = 0;
int data3 = 0;  
   
 // You should get Auth Token in the Blynk App.  
 // Go to the Project Settings (nut icon).  
 char auth[] = "PpHrxMqcMd5Cz3WhAuQ__e9Q5hZ8hs5s";   
 char ssid[] = "DMNE123";  
 char pass[] = "palackal@not";  
   
 #define t V1  
 #define h V5  
 #define q V2  
   
 BlynkTimer timer;  
   
   
 BLYNK_CONNECTED() {  
   
  Blynk.syncAll();  
 }  
   
   
 void myTimerEvent()  
 {  
  if(Serial.available()>0)  
  {  
   ID = Serial.read();  
   data = Serial.read();  
   
   if(ID == 0x8)  
   {  
    Blynk.virtualWrite(t, data);  
   }  
     
   if(ID == 0x7)  
   {  
    Blynk.virtualWrite(h, data2); 
    
   }  
   
   if(ID == 0x6)  
   {  
      
    Blynk.virtualWrite(q, data3);  
   }  
     
   }  
   else  
   {  
    Blynk.virtualWrite(V1, 0);  
    Blynk.virtualWrite(V5, 0);  
    Blynk.virtualWrite(V2, 0);  
   }  
  }  
   
 void setup()  
 {  
  Serial.begin(115200);  
  Blynk.begin(auth, ssid, pass);  
  timer.setInterval(1000L, myTimerEvent);  
 }  
   
 void loop()  
 {      
  Blynk.run();  
  timer.run(); // Initiates BlynkTimer  
 }
