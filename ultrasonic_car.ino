#include <Servo.h>
#define trigPin 12
#define echoPin 13

Servo left_servo;    // continuous servo
Servo right_servo;   // continuous servo
Servo sensor_servo;  // 180° limited servo

int distance;
int duration;
int cm;
int distance_left;
int distance_right;
int difference;


void setup() {

  Serial.begin(9600);
  // Declaration of pins used for servo control
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // declaring pins used for servo control to be compatible with servo library
  left_servo.attach(8);
  right_servo.attach(9);
  sensor_servo.attach(10);
}

void loop() {
    Serial.println("LOOP");
    LookAhead(0);
    MoveForward(0);
    distance = PingDistance();
    delay(100);
    Serial.println(distance);
    if (distance <= 30) {
        MoveStop(50);
        LookLeft(300);
        distance_left = PingDistance();
        delay(100);
        LookAhead(200);
        LookRight(300);
        distance_right = PingDistance();
        delay(100);
        difference = distance_left - distance_right; // - means object to left, + object to right
        LookAhead(200);
        if (distance < abs(difference)) {
            MoveBackward(600);
        }
        if (difference < 5) {
            MoveBackward(600);
        }
        if (difference < 0) {
            MoveStop(100);
            MoveBackward(300);
            MoveRight(500);
        } else {
            MoveStop(100);
            MoveBackward(300);
            MoveLeft(500);
        }
    }
}

int PingDistance() {
  // PingDistance will return the approximate distance in cm of an object
  // in front of the ultrasonic sensor.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // pulseIn will count in μs how long until the echo pin turns from high to low.
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // 0.034 is the speed of sound in cm/μs;
  if (distance > 200) {
      distance = 200;
  }
  return distance;
}

void LookLeft(int ms) {
  sensor_servo.write(180);
  delay(ms);
}

void LookRight(int ms) {
  sensor_servo.write(0);
  delay(ms);
}

void LookAhead(int ms) {
  sensor_servo.write(90);
  delay(ms);
}

void MoveForward(int ms) {
  left_servo.write(180);
  right_servo.write(0);
  delay(ms);
}

void MoveBackward(int ms) {
  left_servo.write(0);
  right_servo.write(180);
  delay(ms);
}

void MoveRight(int ms) {
  left_servo.write(180);
  right_servo.write(180);
  delay(ms);
}

void MoveLeft(int ms) {
  left_servo.write(0);
  right_servo.write(0);
  delay(ms);
}

void MoveStop(int ms) {
  left_servo.write(90);
  right_servo.write(90);
  delay(ms);
}
