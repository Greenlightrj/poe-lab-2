#include <Servo.h>
#include <Math.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

int dsense;

// Positions and Sweep and Angles
int phi = 13;

int theta_offset = 95; // For squaring the bottom Servo position with the base
int offset = -15; //  The offset of our servo so that it is horizontal
int zero = 90; // Making the XY plane our zero
//int ppi = zero - phi + offset; // lowest point of scan
//int ppf = zero + phi + offset; // highest point of scan
int ppi = 30;
int ppf = 100;
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
    //  for (pos_p = ppi; pos_t = pti; pos_p <= ppf; pos_t< = ptf; pos_p += 1; pos_t += 1) {
    myservo1.write(pos_p);
    myservo2.write(theta_offset); // Will not move for the 2D scan
    dsense = analogRead(A0); //read from distance sensor

    //print values
      Serial.print(dsense);
      Serial.print(',');
      Serial.print(pos_p);
      Serial.print(',');
      Serial.println(pos_t);
      delay(15);
  }

  // Turns clockwise and up
  for (pos_p = ppf; pos_p >= ppi; pos_p -= 1) {
    // 3D scan potentially
    //  for (pos_p = ppf; pos_t = ptf; pos_p >= ppi; pos_t >= pti; pos_p -= 1; pos_t -= 1) {
    myservo1.write(pos_p);
    myservo2.write(theta_offset);
    dsense = analogRead(A0); //read from distance sensor

    //print values
      Serial.print(dsense);
      Serial.print(',');
      Serial.print(pos_p);
      Serial.print(',');
      Serial.println(pos_t);
      delay(15);
  }
}


