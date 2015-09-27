//initialize variables up here so they can be used in everything
int dsense;

void setup() {
  // put your setup code here, to run once:
//initialize input pin
pinMode(A0, INPUT);
// begin serial so we can print values
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//read from distance sensor
dsense = analogRead(A0);
//print value
Serial.println(dsense, DEC);
}
