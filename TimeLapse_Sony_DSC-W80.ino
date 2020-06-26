#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  myservo.write(74); // sets the servo resting position 
  delay(5000); // 5 secounds till next photo
  
  myservo.write(100); // servo shoot position - You can calibrate this value
  delay(1000); // 1 secound to have sure that is in focus
}
