// Defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

long duration;
int distance;
int safetyDistance;
bool obstacleDetected = false;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);

 
  distance = duration * 0.034 / 2;

  safetyDistance = distance;

  if (safetyDistance <= 30) {
    if (!obstacleDetected) {
      obstacleDetected = true; 
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin, HIGH);
      Serial.print("Obstacle detected at ");
      Serial.print(distance);
      Serial.println(" cm");
    }
  } else {
    obstacleDetected = false; 
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
  }
}
