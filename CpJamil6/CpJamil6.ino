/* Código Copiado de Jamil Kalil Naufrau Júnior*/

//Definicoes e constantes
#define SentidoEntrada1 7
#define SentidoEntrada2 8
#define RotacaoMotor1 9
#define RotacaoMotor2 3
#define Controle A0

//Variaveis globais e objetos
int Rotacao = 0;

//Setup
void setup(){
   pinMode(SentidoEntrada1, OUTPUT);
   pinMode(SentidoEntrada2, OUTPUT);
   Serial.begin(9600);
}

//Loop
void loop(){
   Rotacao = analogRead(Controle);
   Rotacao = map(Rotacao, 0, 1023, 0, 255);
  
   Serial.println(Rotacao);
  
   //Controla rotacao dos motores
   analogWrite(RotacaoMotor1, Rotacao);
   analogWrite(RotacaoMotor2, Rotacao);

   //Sentido de rotacao
   //LOW-HIGH --> Horario
   //HIGH-LOW --> Anti-horario
   digitalWrite(SentidoEntrada1, LOW);
   digitalWrite(SentidoEntrada2, HIGH);
  
   delay(10);
}