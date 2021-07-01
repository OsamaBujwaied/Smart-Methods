// C++ code
//
int Motor = 0;

int counter;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  for (counter = 0; counter < 10; ++counter) {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
  }
  delay(10); // Delay a little bit to improve simulation performance
}