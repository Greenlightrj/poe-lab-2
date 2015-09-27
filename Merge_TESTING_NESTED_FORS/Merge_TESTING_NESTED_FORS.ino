#include <Servo.h>
#include <Math.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

int dsense;

//// Positions and Sweep and Angles (P.S. This doesn't work)
//int letterh = 20; // height of the letter, in this case height of the scanner so that
                    // all of the letter is detected
//int letterw = 11; // width of the letter
//int x = 45; // distance from the scanner to the letter in centimeters
//int yh = (letterh / 2); // centering the letter
//int yw = letterw / 2; // centering the letter
//int phi = atan2 (yh,x); // angle that the scanner must sweep
//into theta = atan2 (yw,x);
//// to see the top and bottom of the letter.
int phi = 10; // roughly atan(7/45)
int theta = 7; // roughly atan(5.5/45)

//int angle = 45;

int offset = -15; //  The offset of our servo so that it is horizontal
int zero = 90; // Making the XY plane our zero
int ppi = zero - phi + offset; // lowest point of scan
int ppf = zero + phi + offset; // highest point of scan
int pti = zero - theta; // rightmost point of scan
int ptf = zero + theta; // leftmost point of scan
int pos_p = 0;    // variable to store the servo position
int pos_t = 0;


/////////////////////////////////////////////////////////////////////////////////

void setup() {
  // Servo Pins on digital 9 and 10
  myservo1.attach(9);  
  myservo2.attach(10);
  // Analog scanner on A0
  pinMode(A0, INPUT);
  // begin serial so we can print values
  Serial.begin(9600);
}

////////////////////////////////////////////////////////////////////////////////
void loop() {
  // Sweep loop should move through 90 of visibility, 45º up and 45º down.
  // Degrees subject to change based on calibration

  // Turns counter clockwise and down
  for (pos_p = ppi; pos_p <= ppf; pos_p += 1) {
    // 3D scan potentially
    for (pos_t = pti; pos_t <= ptf; pos_t += 1) {
      myservo1.write(pos_p);
      myservo2.write(pos_t); // Will not move for the 2D scan
      dsense = analogRead(A0); //read from distance sensor

      //print values
      Serial.println(dsense);
      Serial.print(pos_p);
      Serial.println(pos_t);
      delay(15);
    }
  }

  // Turns clockwise and up
//  for (pos_p = ppf; pos_p >= ppi; pos_p -= 1) {
//    // 3D scan potentially
//    //  for (pos_p = ppf; pos_t = ptf; pos_p >= ppi; pos_t >= pti; pos_p -= 1; pos_t -= 1) {
//    myservo1.write(pos_p);
//    myservo2.write(pos_t);
//    dsense = analogRead(A0); //read from distance sensor
//
//    //print values
//    Serial.println(dsense);
//    Serial.print(pos_p);
//    Serial.println(pos_t);
//    delay(15);
//  }
}

