#include <Wire.h>
int pinLed=13;
int x =0;

#include <Servo.h>
int sensorValue = 0;
int outputValue = 0;
Servo servo_1;
Servo servo_3;
Servo servo_5;
Servo servo_7;
Servo servo_9;
int counter;



void setup(){
  Wire.begin(1); //Slave
  Wire.onReceive(receiveEvent); 
  pinMode(pinLed, OUTPUT);
  
  pinMode(A0, INPUT);
  servo_1.attach(1, 500, 2500);
  servo_3.attach(3, 500, 2500);
  servo_5.attach(5, 500, 2500);
  servo_7.attach(7, 500, 2500);
  servo_9.attach(9, 500, 2500);
}



void loop(){
  
  delay(100);
}



void receiveEvent(int howMany){
  x = Wire.read();
  
  if (x == 1){
    digitalWrite(pinLed,HIGH);
    
    sensorValue = analogRead(A0);
    outputValue = map(sensorValue, 0, 1023, 0, 90);
    servo_1.write(outputValue);
    servo_3.write(outputValue);
    servo_5.write(outputValue);
    servo_7.write(outputValue);
    servo_9.write(outputValue);
  }
  
  else {
    digitalWrite(pinLed,LOW);
    
    sensorValue = 0;
    outputValue = map(sensorValue, 0, 1023, 0, 90);
    servo_1.write(outputValue);
    servo_3.write(outputValue);
    servo_5.write(outputValue);
    servo_7.write(outputValue);
    servo_9.write(outputValue);
  }
}