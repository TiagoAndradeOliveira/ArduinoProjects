#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  //servo.attach(9);
  servo.write(50);
  delay(1000);
  //servo.detach();
  delay(1000);

  //servo.attach(9);
  servo.write(100);
  delay(1000);
  //servo.detach();
  delay(1000);
}