#include <Servo.h>
#include <LiquidCrystal.h>

// ---------------- PIN CONFIGURATION ----------------

// HC-SR04 Ultrasonic Sensor
const int trigPin = 2;
const int echoPin = 3;

// Servo Motor
const int servoPin = 9;

// LED Indicator
const int ledPin = 13;

// 16x2 LCD
// RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 4, 5, 6, 10);

// Servo object
Servo radarServo;

// ---------------- VARIABLES ----------------

long duration;
float distance;
int servoAngle = 0;

// Detection threshold
const float detectionLimit = 10.0;

// ---------------- SETUP ----------------

void setup() {

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // LED
  pinMode(ledPin, OUTPUT);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.clear();

  // Attach servo
  radarServo.attach(servoPin);
  radarServo.write(servoAngle);

  // Startup message
  lcd.setCursor(0, 0);
  lcd.print("Ultrasonic");
  lcd.setCursor(0, 1);
  lcd.print("Radar System");

  delay(2000);
  lcd.clear();
}

// ---------------- MAIN LOOP ----------------

void loop() {

  // Generate ultrasonic trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Measure echo pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance = duration * 0.0343 / 2.0;

  // Display distance
  lcd.setCursor(0, 0);
  lcd.print("Distance:       ");

  lcd.setCursor(0, 0);
  lcd.print("Distance:");

  lcd.setCursor(0, 1);
  lcd.print(distance, 1);
  lcd.print(" cm     ");

  // Object detection
  if (distance > 0 && distance < detectionLimit) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  // Move servo
  radarServo.write(servoAngle);

  servoAngle++;

  if (servoAngle > 180) {
    servoAngle = 0;
  }

  // Delay between measurements
  delay(100);
}
