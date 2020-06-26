/* Code:
https://github.com/djayor/TimeLapse_Sony_DSC-W80
3D Print Parts:
https://www.thingiverse.com/thing:4498410
*/

#include <Servo.h>
Servo myservo;

#define pintime 0 // Analog A0 - potentiometer
#define pinServo 9 // Digital Pin 9 - servo motor

void setup() {
  myservo.attach(pinServo);
  Serial.begin(9600);       // use the serial port to debug
}

void loop() {
  int ptime = analogRead(pintime);
  ptime = map(ptime, 0, 1023, 0, 5); // 5 time stages
  int seconds=0; //seconds between shots

  Serial.print("Read position in potentiometer: ");
  Serial.println(ptime); 

  switch (ptime) {
    case 1:
      seconds = 3000; // 3 seconds till next photo
      Serial.println("Time Lapse with 3 seconds! ");
      break;
    case 2:
      seconds = 5000; // 5 seconds till next photo
      Serial.println("Time Lapse with 5 seconds! ");
      break;
    case 3:
      seconds = 10000; // 10 seconds till next photo
      Serial.println("Time Lapse with 10 seconds! ");
      break;
    case 4:
      seconds = 30000; // 30 seconds till next photo
      Serial.println("Time Lapse with 30 seconds! ");
      break;
    default:
      //or case 0 = turn off the servo
      break;
  }

  myservo.write(74); // sets the servo resting position 
  delay(seconds); // 5 secounds till next photo


  if(ptime > 0){
    myservo.write(100); // servo shoot position - You can calibrate this value
    delay(1000); // 1 secound to have sure that is in focus
  }
}
