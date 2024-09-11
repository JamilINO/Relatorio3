#include<Servo.h>

Servo servoMotor;

int pinPot = 0;
int valPot = 0;
int angulo = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoMotor.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:

  valPot = analogRead(pinPot);
  angulo = map(valPot, 0, 1023, 0, 180);
  servoMotor.write(angulo);
  //Serial.print("Angulo")
  Serial.print(angulo);
  delay(1000);
}
