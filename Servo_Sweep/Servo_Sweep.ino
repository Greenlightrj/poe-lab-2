/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <math.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

// Positions and Sweep and Angles (P.S. This doesn't work)
int letter = 100; // arbitrary value selected for the height of the letter.
int x = 50; // distance from the scanner to the letter in centimeters
int y = (letter/2);
int phi = atan2 (y,x); // angle that the scanner must sweep 
                                    // to see the top and bottom of the letter.

int offset = -15; //  The offset of our servo so that it is horizontal
int zero = 90; // Making the XY plane our zero
int pti = zero-phi+offset; // lowest point of scan
int ptf = zero+phi+offset; // highest point of scan
int pos_t = 0;    // variable to store the servo position
int pos_b = 0;



/////////////////////////////////////////////////////////////////////////////////

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
}

////////////////////////////////////////////////////////////////////////////////
void loop() {
// Sweep loop should move through 90 of visibility, 45º up and 45º down. 
// Degrees subject to change based on calibration

// Turns counter clockwise and down
  for (pos_t = pti; pos_t <= ptf; pos_t += 1) { 
    // in steps of 1 degree
    myservo1.write(pos_t);              
    myservo2.write(pos_b); // Will not move for the 2D scan
    Serial.print(0);     
    Serial.print(pos_t);
    Serial.println(pos_b); 
    delay(15);              
  }
  
// Turns clockwise and up
  for (pos_t = ptf; pos_t >= pti; pos_t -= 1) { 
    myservo1.write(pos_t);              
    myservo2.write(pos_b);
    Serial.print(0);     
    Serial.print(pos_t);
    Serial.println(pos_b); 
    delay(15);                    
  }
}

