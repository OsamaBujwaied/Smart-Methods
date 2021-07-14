


#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

#include <Wire.h>



void setup() {
	lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
  
    Wire.begin();	// Master
}



void loop() {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distanceCm= duration*0.034/2;
	distanceInch = duration*0.0133/2;
	lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
	lcd.print("Distance: "); // Prints string "Distance" on the LCD
	lcd.print(distanceCm); // Prints the distance value from the sensor
	lcd.print(" cm");
	delay(10);
	lcd.setCursor(0,1);
	lcd.print("Distance: ");
	lcd.print(distanceInch);
	lcd.print(" inch");
  
  	if(distanceCm < 100){
  		Wire.beginTransmission(1);
   		Wire.write(1);
   		Wire.endTransmission();
        Wire.beginTransmission(2);
   		Wire.write(1);
   		Wire.endTransmission();
    }
    else {
  		Wire.beginTransmission(1);
   		Wire.write(0);
   		Wire.endTransmission();
        Wire.beginTransmission(2);
   		Wire.write(0);
   		Wire.endTransmission();
    }
  
  	delay(100);
}