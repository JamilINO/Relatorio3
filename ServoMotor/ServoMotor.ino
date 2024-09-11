#include<Servo.h> /* Importa o Headerfile Servo.h para controlar o Servo Motor */


Servo servoMotor; /* Instancia a classe Servo declarada na biblioteca */

int pinPot = 0; /* Porta do Potênciometro A0*/
int valPot = 0; /* Declara variavel que armazenará o valor do potênciometro */
int angulo = 0;  /* Declara variavel que armazenará o ângulo do potênciometro */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); /* Incia uma comunicação serial com uma velocidade de 9600 bps */
  servoMotor.attach(7); /* Indica o motor na porta 7 PWM */
}

void loop() {
  // put your main code here, to run repeatedly:

  valPot = analogRead(pinPot);  /* Lê o Valor do potênciometro */
  angulo = map(valPot, 0, 1023, 0, 180); /* Converte o valor para o intervalo de graus */
  servoMotor.write(angulo); /* Envia ao servo motor o novo ângulo desejado */
  //Serial.print("Angulo")
  Serial.print(angulo); /* Imprime o valor do ângulo */
  delay(1000);   /* Espera um segundo */
}
