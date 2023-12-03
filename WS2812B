#define BLYNK_TEMPLATE_ID           "auto generated"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "auto generated"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Your SSID";
char pass[] = "Password";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  if(value == 1){
    digitalWrite(D1, HIGH);
  }else{
   digitalWrite(D1, LOW);
  }
  }
  
void setup()
{
  pinMode(D1, OUTPUT);
 
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();

}
