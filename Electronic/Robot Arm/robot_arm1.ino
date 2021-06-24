// C++ code
//
#include <Servo.h>

int sensorValue = 0;

int outputValue = 0;

Servo servo_1;

Servo servo_3;

Servo servo_5;

Servo servo_7;

Servo servo_9;

int counter;

void setup()
{
  pinMode(A0, INPUT);
  servo_1.attach(1, 500, 2500);

  pinMode(A1, INPUT);
  servo_3.attach(3, 500, 2500);

  pinMode(A2, INPUT);
  servo_5.attach(5, 500, 2500);

  pinMode(A3, INPUT);
  servo_7.attach(7, 500, 2500);

  pinMode(A4, INPUT);
  servo_9.attach(9, 500, 2500);

}

void loop()
{
  for (counter = 0; counter < 10; ++counter) {
    sensorValue = analogRead(A0);
    outputValue = map(sensorValue, 0, 1023, 0, 90);
    servo_1.write(outputValue);
    sensorValue = analogRead(A1);
    outputValue = map(sensorValue, 0, 1023, 0, 90);
    servo_3.write(outputValue);
    sensorValue = analogRead(A2);
    outputValue = map(sensorValue, 0, 1023, 0, 90);
    servo_5.write(outputValue);
    sensorValue = analogRead(A3);
    outputValue = map(sensorValue, 0, 1023, 0, 90);
    servo_7.write(outputValue);
    sensorValue = analogRead(A4);
    outputValue = map(sensorValue, 0, 1023, 0, 90);
    servo_9.write(outputValue);
  }
  delay(10); // Delay a little bit to improve simulation performance
}