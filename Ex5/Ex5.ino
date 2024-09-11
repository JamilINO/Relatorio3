#include<Servo.h> /* Importa o Headerfile Servo.h para controlar o Servo Motor */

Servo servoMotor; /* Instancia a classe Servo declarada na biblioteca */

int pinPot = 0; /* Porta do Potênciometro A0*/
int valPot = 0; /* Declara variavel que armazenará o valor do potênciometro */
int angulo = 0; /* Declara variavel que armazenará o ângulo do potênciometro */
int ledPin = 2; /* Pino do LED D2 */

void setup() {
  Serial.begin(9600); /* Incia uma comunicação serial com uma velocidade de 9600 bps */
  servoMotor.attach(7); /* Indica o motor na porta 7 PWM */
  pinMode(ledPin, OUTPUT); /* Indica o modo de saída de dados (OUTPUT) para a porta do LED (D2) */
}

void loop() {
  valPot = analogRead(pinPot); /* Lê o Valor do potênciometro */
  angulo = map(valPot, 0, 1023, 0, 180); /* Converte o valor para o intervalo de graus */
  servoMotor.write(angulo);     /* Envia ao servo motor o novo ângulo desejado */
  Serial.print("Ângulo em graus: "); /* Manda para o USB uma mensagem construindo uma string contendo o novo ângulo do acelerômetro */
  Serial.print(angulo); 
  delay(1000);      /* Espera um segundo */

  /* Se o novo ângulo for maior que 90 graus liga o LED caso o contrario desliga */
  if(angulo >= 90){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

}
