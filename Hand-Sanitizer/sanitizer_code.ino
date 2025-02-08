#include <Servo.h>

int trigPin = 2;
int echoPin = 3;
int servoPin = 4;
int ledpin =6;
int servopin2=5;

Servo myServo;
Servo myServo2;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
pinMode(ledpin, OUTPUT);
  myServo.attach(servoPin);
  myServo2.attach(servopin2);
  myServo.write(0); 
  myServo2.write(0);// Initial position of the servo
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance <= 10) {
      myServo.write(120); 
      myServo2.write(120);
      digitalWrite(ledpin,HIGH);
      // Move servo to 90 degrees
    // Hold for 2 seconds
   // Move servo back to 0 degrees
  }
  else {
    myServo.write(0); 
    myServo2.write(0);
    digitalWrite(ledpin,LOW); 
    
  }
  // Small delay before the next loop
  Serial.print(distance);
}














