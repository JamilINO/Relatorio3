#include<Servo.h>

Servo servoMotor;

int pinPot = 0;
int valPot = 0;
int angulo = 0;
int ledPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoMotor.attach(7);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  valPot = analogRead(pinPot);
  angulo = map(valPot, 0, 1023, 0, 180);
  servoMotor.write(angulo);
  Serial.print("Ângulo em graus: ");
  Serial.print(angulo);
  delay(1000);

  if(angulo >= 90){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

}
