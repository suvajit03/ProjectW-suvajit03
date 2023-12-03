#define BLYNK_TEMPLATE_ID "Your Template ID"
#define BLYNK_DEVICE_NAME "Your Device Name"
#define BLYNK_AUTH_TOKEN "Your Auth Token"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "SSID";
char pass[] = "Password";

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0){
  int value = param.asInt();
  value ? digitalWrite(D1, HIGH) : digitalWrite(D1, LOW);
  }

BLYNK_WRITE(V1){
   int value = param.asInt();
   value ? digitalWrite(D4, HIGH) : digitalWrite(D4, LOW);
  }
  
BLYNK_WRITE(V2){
   int value = param.asInt();
   value ? digitalWrite(D8, HIGH) : digitalWrite(D8, LOW);
  }

void setup(){
  pinMode(D1, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D8, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
}
