#define BLYNK_TEMPLATE_ID "TMPL3s1QeTRns"
#define BLYNK_TEMPLATE_NAME "nodemcu"
#define BLYNK_AUTH_TOKEN "HfGuld7PgKy-fXq84fThUok9FdCMyboB"

#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#define FASTLED_ESP8266_RAW_PIN_ORDER
#include "FastLED.h"
#define NUM_LEDS1 60
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds1[NUM_LEDS1];
char auth[] = "HfGuld7PgKy-fXq84fThUok9FdCMyboB";
char ssid[] = "jio";
char pass[] = "admin@12";
#define PIN1 D5
int data=255;
int r,g,b;
void setup()
{
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  FastLED.addLeds<LED_TYPE, PIN1, COLOR_ORDER>(leds1, NUM_LEDS1).setCorrection( TypicalLEDStrip );
}

BLYNK_WRITE(V0){
  int value = param.asInt();
  value ? digitalWrite(D1, HIGH) : digitalWrite(D1, LOW);
  }

BLYNK_WRITE(V1){
   int value = param.asInt();
   value ? digitalWrite(D2, HIGH) : digitalWrite(D2, LOW);
  }
  
BLYNK_WRITE(V2){
   int value = param.asInt();
   value ? digitalWrite(D3, HIGH) : digitalWrite(D3, LOW);
  }

BLYNK_WRITE(V3){
   int value = param.asInt();
   value ? digitalWrite(D4, HIGH) : digitalWrite(D4, LOW);
  }



BLYNK_WRITE(V5)
{
  r = param[0].asInt();
  g = param[1].asInt();
  b = param[2].asInt();

  static1(r, g, b,data);
}

void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V4)
{
data = param.asInt(); 
static1(r, g, b,data);
}
void static1(int r, int g, int b,int brightness)
{
  FastLED.setBrightness(brightness);
  for (int i = 0; i < NUM_LEDS1; i++ )
  {
    leds1[i] = CRGB(r, g, b);
  }
  FastLED.show();
}
 
