
int pin_motor = 3; /* Pino do Motor */

float motor; /* Declaração de um valor que será enviado */

void setup(){
    Serial.begin(9600); /* Incia comunicação serial */
}

void loop(){
    motor = analogRead(A0) / 4; /* Le da porta analógica A0 */
 
    analogWrite(pin_motor, motor); /* Escreve o valor do potenciometro no motor */

    Serial.print("Motor ");
    Serial.print(motor); /* Envia uma mensagem com valor pelo serial */
}