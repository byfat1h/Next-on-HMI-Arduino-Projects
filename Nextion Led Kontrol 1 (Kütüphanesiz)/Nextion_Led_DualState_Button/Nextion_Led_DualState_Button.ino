#define SWITCH_ON 1
#define SWITCH_OFF 0
const int led = 12;
byte received_data[4];
int  switch_pos;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("ready");
  pinMode(led,OUTPUT);
  digitalWrite(led, LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  int i;
  while (Serial.available() > 0) {
      switch_control();
  }
  
}
void switch_control() {
    int size = Serial.readBytesUntil('\n', received_data, 4);
    // First Byte has the switch position data 
    switch_pos = received_data[0];
    Serial.print("SWITCH:");
    if (switch_pos == SWITCH_ON) {
      Serial.println("ON");
      digitalWrite(led, HIGH);
    } else if (switch_pos == SWITCH_OFF) {
      Serial.println("OFF");
      digitalWrite(led, LOW);
    }
}
