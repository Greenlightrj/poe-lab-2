#include <Servo.h>
#include <Math.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;

int dsense; // sensor output

//// Positions and Sweep and Angles (P.S. This doesn't work)
int offset = -15; //  The offset of our servo so that it is horizontal
int zero = 90; // Making the XY plane our zero
int ppi = 30; // lowest point of scan
int ppf = 100; // highest point of scan
int pti = 65; // rightmost point of scan
int ptf = 125; // leftmost point of scan
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
  // Turns counter clockwise and down
  for (pos_t = pti; pos_t <= ptf; pos_t += 5) {
    for (pos_p = ppi; pos_p <= ppf; pos_p += 1) {
      myservo1.write(pos_p);
      myservo2.write(pos_t); 
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

}


