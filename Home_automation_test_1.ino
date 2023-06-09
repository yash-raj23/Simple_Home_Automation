// wifi controlled home automation using Blynk App & ESP8266
#define BLYNK_TEMPLATE_ID "TMPL34ok-Mse_" //blynk template ID
#define BLYNK_TEMPLATE_NAME "smart home" //blynk template  name
#define BLYNK_AUTH_TOKEN "XkgQ7bK3S0lg3bAlL9I7tkFJ7MDaU2gL" // enter your blynk auth token
 
#define BLYNK_PRINT Serial
#include <gpio.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = BLYNK_AUTH_TOKEN; 
char ssid[] = "YASH RAJ"; // Your Wifi Name
char pass[] = "yash2301"; // Your Wifi Password
 
//in the below code, we have set all values reverse
//For value==1, digitalWrite is "LOW" as the realy module is active "LOW" to turn device ON.
//For value==0, digitalWrite is "HIGH" as Optocoupler based relay is turned OFF when HIGH Input is given
BLYNK_WRITE(V1)
{
  int value=param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D0,HIGH); 
    Serial.println("LED ON"); //Setting Digital PIN as LOW to turn ON Device if relay module is "active low"
  }
  if(value == 0)
  {
     digitalWrite(D0,LOW);
     Serial.println("LED OFF");//Setting Digital PIN as HIGH to turn OFF Device if relay module is "active low"
  }
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT); //GPIO 16 (equivalent to PIN 16 of Arduino)
}
 
void loop()
{
  Blynk.run();
}