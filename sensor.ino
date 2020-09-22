#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
char auth[] = "u1LirHeZK8ojrV6SvGGpFYoFzboNrZqa";
char ssid[] = "iotlab";
char pass[] = "password12345";
#define DHTPIN 10
// D0
const int leftForward = 5; //SD3
const int leftBackward =4;//SD2
const int rightForward = 0;//d3
const int rightBackward = 2;//d4
BlynkTimer timer;
int outputpin = A0;
WidgetLCD lcd(V1);
//int pirValue; // Place to store read PIR Value
//int motionDetected = 0;
void setup()
{
dht.begin();
// Debug console
Serial.begin(9600);
pinMode(D5, INPUT);
pinMode(D6, INPUT);
pinMode(D7, INPUT);
pinMode(D8, INPUT);
pinMode(A0, INPUT);
pinMode(D0, OUTPUT);
pinMode(D1, INPUT);
// pinMode(leftForward,OUTPUT);
pinMode(leftBackward,OUTPUT);
pinMode(rightForward,OUTPUT);
pinMode(rightBackward,OUTPUT);
Blynk.begin(auth, ssid, pass);
timer.setInterval(1000L, sendSensor);
}
void loop()
{
Blynk.run();
timer.run();
getPirValue();
metal();
delay(1000);
fire();
delay(1000);
}
void fire(void)
{
if(digitalRead(D1)==HIGH)
{
digitalWrite(D0,HIGH);
Blynk.notify("T==> HUMAN DETECTED-SAFE AND RESCUE");
lcd.clear();
lcd.print(0, 0, "HUMAN DETECTED -BE HELP & RESCUE");
}
else
{
digitalWrite(D0,LOW);
lcd.clear();
lcd.print(0, 0, " SEARCHING HUMAN.........");
}
}
void metal(void)
{
if(digitalRead(D2)==HIGH)
{
digitalWrite(D0,HIGH);
Blynk.notify("T==> METAL DETECTED-SAFE AND RESCUE");
lcd.clear();
lcd.print(0, 0, "METAL DETECTED -BE HELP & RESCUE");
}
else
{
digitalWrite(D0,LOW);
lcd.clear();
lcd.print(0, 0, " SEARCHING HUMAN.........");
}
}
void getPirValue(void)
{
if (digitalRead(D5)==HIGH)
{
digitalWrite(leftForward,HIGH);
digitalWrite(leftBackward,LOW);
digitalWrite(rightForward,HIGH);
digitalWrite(rightBackward,LOW);
lcd.clear();
lcd.print(0, 0, "forward");
}
else if (digitalRead(D6)==HIGH)
{
digitalWrite(leftForward,LOW);
digitalWrite(leftBackward,LOW);
digitalWrite(rightForward,HIGH);
digitalWrite(rightBackward,LOW);
lcd.clear();
lcd.print(0, 0, "left");
}
else
{
if (digitalRead(D7)==HIGH)
digitalWrite(leftForward,HIGH);
digitalWrite(leftBackward,LOW);
digitalWrite(rightForward,LOW);
digitalWrite(rightBackward,LOW);
lcd.clear();
lcd.print(0, 0, "right");
}
else if (digitalRead(D8)==HIGH)
{
digitalWrite(leftForward,LOW);
digitalWrite(leftBackward,HIGH);
digitalWrite(rightForward,LOW);
digitalWrite(rightBackward,HIGH);
lcd.clear();
lcd.print(0, 0, "reverse");
}
else
{
digitalWrite(leftForward,LOW);
digitalWrite(leftBackward,LOW);
digitalWrite(rightForward,LOW);
digitalWrite(rightBackward,LOW);
lcd.clear();
lcd.print(0, 0, "MILITARY ROBOT -
}}
