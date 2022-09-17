
#include "Nextion.h"
#include <SoftwareSerial.h>
SoftwareSerial HMISerial(10, 11);

int32_t deger;
int motorpin = 5;
NexSlider h0 = NexSlider(0, 1, "h0");
NexTouch *nex_listen_list[] =
{
  &h0,
  NULL
};

void h0PopCallback(void *ptr)
{
  dbSerialPrintln("h0PopCallback");
}

void setup(void)
{
  nexInit();
  h0.attachPop(h0PopCallback);
  dbSerialPrintln("setup done");
  Serial.begin(9600);
  pinMode(motorpin, OUTPUT);
}

void loop(void)
{

  nexLoop(nex_listen_list);

  h0.getValue(&deger);       
  delay(5);
  Serial.print("deger :"); 
  delay(5);
  Serial.println(deger);   
  delay(5);
  delay(50);
  analogWrite(motorpin, deger);

}
