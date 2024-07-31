const int trigPin = A0;
const int echoPin = A1;

long duration;
int distance;

void setup() {
  // Initialize the Serial Monitor
  Serial.begin(9600);
  // Set the trigPin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  // Set the echoPin as an INPUT
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Wait for a second before the next loop
}
