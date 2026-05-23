#include <Servo.h>

int distance;
int trig_pin = 8;
int echo_pin = 10;

Servo mithun;

void setup() {
  Serial.begin(9600);
  mithun.attach(9);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void ultrasonicServo() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH);
  distance = (duration * 0.034) / 2;
  //Serial.println(distance);
}

void ServoRadarMovement(int Start_angle, int end_angle, int speed) {
  if (Start_angle < end_angle) {
   for (int i = Start_angle; i <= end_angle; i++) {
    mithun.write(i);
    //Serial.println("servo moved");
    ultrasonicServo();
    //Serial.println("ultrasonic sensor sensed");
    delay(speed);
    Serial.print(i);
    Serial.print(",");
    Serial.println(distance);
   }
   for (int i = end_angle; i >= Start_angle; i--) {
    mithun.write(i);
    //Serial.println("servo moved");
    ultrasonicServo();
    //Serial.println("ultrasonic sensor sensed");
    delay(speed);
    Serial.print(i);
    Serial.print(",");
    Serial.println(distance);
   }
  }
  else if (Start_angle > end_angle) {
    for (int i = Start_angle; i >= end_angle; i--) {
      mithun.write(i);
      //Serial.println("servo moved");
      ultrasonicServo();
      //Serial.println("ultrasonic sensor sensed");
      delay(speed);
      Serial.print(i);
      Serial.print(",");
      Serial.println(distance);
    }
    for(int i = end_angle; i <= Start_angle; i++) {
      mithun.write(i);
      //Serial.println("servo moved");
      ultrasonicServo();
      //Serial.println("ultrasonic sensor sensed");
      delay(speed);
      Serial.print(i);
      Serial.print(",");
      Serial.println(distance);
    }
  }
}

void loop() {
  ServoRadarMovement(180, 0, 20);
}
