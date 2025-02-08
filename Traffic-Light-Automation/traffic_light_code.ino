int trigPin = 2;
int echoPin = 3;
int lightSensorPin = A0;
int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;

const int ANALOG_THRESHOLD = 500;
int analogValue;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(lightSensorPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  Serial.begin(9600);
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

  analogValue = analogRead(lightSensorPin);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Light Sensor Value: ");
  Serial.println(analogValue);

  if (distance <= 10 && analogValue < ANALOG_THRESHOLD) {
    Serial.println("LEDs ON");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  } else {
    Serial.println("LEDs OFF");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  delay(500);
}
