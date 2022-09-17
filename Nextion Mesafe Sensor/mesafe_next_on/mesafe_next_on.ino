
#include "Nextion.h"
#include <SoftwareSerial.h>
SoftwareSerial HMISerial(10, 11);
#define echoPin 12
#define trigPin 13
long sure, uzaklik;

void n0PopCallback(void *ptr);
NexNumber n0 = NexNumber(0, 1, "n0");

NexTouch *nex_listen_list[] =
{
  &n0,
  NULL
};

void n0PopCallback(void *ptr)
{
  dbSerialPrintln("n0PopCallback");
}

void setup(void)
{
  //Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  nexInit();
  n0.attachPop(n0PopCallback);
  dbSerialPrintln("setup done");
}

void loop(void)
{
 digitalWrite(trigPin, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 sure = pulseIn(echoPin, HIGH);
 uzaklik = sure / 29.1 / 2;

 n0.setValue(uzaklik);
 delay(100);
    
}
