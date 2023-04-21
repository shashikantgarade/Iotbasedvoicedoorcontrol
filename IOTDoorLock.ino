#include <HID.h>
#include <SoftwareSerial.h>
int Relay1 = 7;
String data;
SoftwareSerial wifiSerial(10, 11);
void setup() 
{
  Serial.begin(9600);
  wifiSerial.begin(115200);
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, HIGH);
}

void loop() 
{
    Serial.println("Hello");
    data=wifiSerial.readString();
    Serial.println(data);
    if(data.startsWith("1"))
    {
      digitalWrite(Relay1, LOW);
      Serial.println("Switch1 : ON");
    }
    else if(data.startsWith("2"))
    {
      digitalWrite(Relay1, HIGH);
      Serial.println("Switch1 : OFF");
    }
    delay(100);
}
