#include <Servo.h>

const int trigPin = 5;
const int echoPin = 6;
const int servoPin = 7;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance <= 20) {
    myServo.write(18x0);
    delay(2000);
    myServo.write(0);
  }

  delay(100);
}
