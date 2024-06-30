#define BLYNK_TEMPLATE_ID "TMPL6RLrKPvFT"
#define BLYNK_TEMPLATE_NAME "fishh"
#define BLYNK_AUTH_TOKEN "siBmNZ-1haI9R8Fh9ZwHifV8uGUfyQA8"

#include <ESP32Servo.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#define BLYNK_PRINT Serial

char ssid[] = "Hoàng Tử Hà Thành";
char pass[] = "22222222";

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
Servo motor;

void runMotor() {
  motor.write(90);
  delay(1000); 

  motor.write(120);
  delay(1000); 
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  motor.attach(5);

  // Register a Virtual Pin for the switch
  Blynk.virtualWrite(V1, LOW);
}


void loop() {
  Blynk.run();
  timer.run();
}

BLYNK_WRITE(V1) {
  int switchState = param.asInt(); 
  
  if (switchState == HIGH) {
    motor.write(80);
    delay(1000);

    motor.write(100);
    delay(1000);
     motor.write(80);
  }
  else{
    motor.write(80);
    delay(1000);
  }
}