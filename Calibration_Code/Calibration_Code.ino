// Initialization and position of Servos
#include <Servo.h>

Servo myservotop;  
Servo myservobottom;

int pos = 0;


void setup() {
  myservotop.attach(9);
  myservobottom.attach(10);

}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //myservobottom.write(pos);              // tell servo to go to position in variable 'pos'
    myservotop.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    //myservobottom.write(pos);              // tell servo to go to position in variable 'pos'
    myservotop.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
