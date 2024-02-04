#include <Servo.h>
#include <Ultrasonic.h>

Servo myservo;  // Define um controle para o nosso servo 

long readUltrasonicDistance(int triggerPin, int echoPin)//Uma função que emite a onda e retorna o valor da distância
{
  pinMode(triggerPin, OUTPUT);  // Limpa o trigger 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Define o triggerPin para emitir ondas por 10 µs 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Lê o echoPin e retorna o valor da distância percorrida pela onda em µs
  return pulseIn(echoPin, HIGH);
}

void setup() {

  myservo.attach(9);    // Define o pino que será conectado ao
					    // Servo Motor
	Serial.begin(9600); // Perimite a leitura dos valores
}

void loop() {

Serial.println(0.01723 * readUltrasonicDistance(3, 2));
  if (0.01723 * readUltrasonicDistance(3, 2) < 20) { // Se houver um corpo a menos de 20 cm da leixeira, ela abrirá 
    myservo.write(90); //Faz o servo rotacionar 90 graus, abrindo a lixeira
	delay(5000); //Mantém a lixeira aberta por 5s, depois de ter detectado presença
  } else {
	myservo.write(0); //Caso não haja nada a 20 cm do sensor da lixeira, ela permanecerá fechada 
  }
  delay(10); // Para melhorar a performance do código                     
}