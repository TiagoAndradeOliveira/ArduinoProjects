#include <Servo.h>
#include <Ultrasonic.h>

#define verde 12
#define vermelho 10 

Servo myservo;  // Define um controle para o nosso servo 

unsigned long TempoAtual;
unsigned long Clock;
bool open = 0;

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
  pinMode(verde, OUTPUT);pinMode(vermelho, OUTPUT);
}

void loop() {

TempoAtual = millis();

Serial.println(0.01723 * readUltrasonicDistance(3, 2));
  if(0.01723 * readUltrasonicDistance(3, 2) < 20 && open == 0) { // Se houver um corpo a menos de 20 cm da leixeira, ela abrirá
    
    digitalWrite(verde, LOW);digitalWrite(vermelho, HIGH);
     //myservo.attach(9);
     delay(10);
    for(int pos = 0; pos < 90; pos+=2){
      myservo.write(pos); //Faz o servo rotacionar 90 graus, abrindo a lixeira
      delay(10);
    }
    //myservo.detach(); 
    open = !open;
    //Clock = TempoAtual;
	  delay(3000); //Mantém a lixeira aberta por 3s, depois de ter detectado presença
    
  }
  if(open == 1)
  {
    digitalWrite(verde, HIGH);digitalWrite(vermelho, LOW);
    myservo.write(0);
    delay(30);
    open = !open;
  }
  else{digitalWrite(verde, HIGH);digitalWrite(vermelho, LOW);delay(500);}

  /*if(TempoAtual - Clock <= 4500)
  {
    digitalWrite(verde, HIGH);digitalWrite(vermelho, LOW);
    myservo.attach(9);
    delay(10);
    myservo.write(0);
    delay(15);
    myservo.detach(); 
  }
  else{};*/

  

                       
}