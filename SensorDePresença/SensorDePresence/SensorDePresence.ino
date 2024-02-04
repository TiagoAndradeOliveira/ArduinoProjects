#include <Ultrasonic.h>

#define delaytime 50
#define vermelho 10
#define amarelo 11
#define verde 12 // não usei o 13 por que choca com o LEDbuiltIN

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
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  Serial.begin(9600); // Perimite a leitura dos valores

}

void loop() {

Serial.println(0.01723 * readUltrasonicDistance(3, 2)); //a constante 001723 foi tirada do chatGPT, basicamente ele convertem um tempo em microsegundos para uma distância em centímetros

//delay(50);
if(0.01723 * readUltrasonicDistance(3, 2) < 30 ){ // Se tivermos uma detecção a menos de 30 centímetros
  //delay(delaytime);
  digitalWrite(verde, HIGH);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, LOW);
  //delay(delaytime);

  if(0.01723 * readUltrasonicDistance(3, 2) < 15 ){
    //delay(delaytime);
    digitalWrite(verde, HIGH);
    digitalWrite(amarelo, HIGH);
    digitalWrite(vermelho, LOW);
    //delay(delaytime);

    if(0.01723 * readUltrasonicDistance(3, 2) < 5 ){
      //delay(delaytime);
      digitalWrite(verde, HIGH);
      digitalWrite(amarelo, HIGH);
      digitalWrite(vermelho, HIGH);
      //delay(delaytime);
    }
  }
  }else{
    //delay(delaytime);
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);
    //delay(delaytime);
  }
}
