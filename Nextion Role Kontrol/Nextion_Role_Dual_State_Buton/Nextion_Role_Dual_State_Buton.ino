
#include "Nextion.h"
#include <SoftwareSerial.h>

#define role1 5
#define role2 6

SoftwareSerial HMISerial(10, 11);
NexDSButton bt0 = NexDSButton(0, 1, "bt0");
uint32_t butondurum1 = 0;
NexDSButton bt1 = NexDSButton(0, 2, "bt1");
uint32_t butondurum2 = 0;

void setup(void)
{
  
  dbSerialPrintln("setup begin");
  nexInit();
  dbSerialPrintln("setup done");
  
  pinMode(role1, OUTPUT);
  pinMode(role2, OUTPUT);
}

void loop(void)
{

  bt0.getValue(&butondurum1);
  delay(200);
  
  if (butondurum1 == 1)
  {
    digitalWrite(role1, HIGH);
   
  }
  else if (butondurum1 == 0)
  {
    digitalWrite(role1, LOW); 
   
  }

bt1.getValue(&butondurum2);
  delay(200);
  
  if (butondurum2 == 1)
  {
    digitalWrite(role2, HIGH);
    
  }
  else if (butondurum2 == 0)
  {
    digitalWrite(role2, LOW); 
    
  }


}
