#include <Wire.h>
int pinLed=13;
int x =0;

int counter;

void setup(){
  Wire.begin(2); //Slave
  Wire.onReceive(receiveEvent); 
  pinMode(pinLed, OUTPUT);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop(){
  delay(100);
}

void receiveEvent(int howMany){
  x = Wire.read();
  
  if (x == 1) {
    digitalWrite(pinLed, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else {
      digitalWrite(pinLed, LOW);
    if (digitalRead(2) == HIGH) {
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
    }
    if (digitalRead(3) == HIGH) {
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
    }
  }
}