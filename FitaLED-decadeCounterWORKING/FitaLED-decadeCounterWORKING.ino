#define button 2
#define clkpulse 3
#define clear 8

unsigned long clock;
unsigned long tempo;

bool estado=false;
bool ligar =false;

void setup() {

  pinMode(button ,INPUT);
  pinMode(clkpulse, OUTPUT);
  pinMode(clear, OUTPUT);

}

void loop() {

  clock = millis();

  if(digitalRead(button) == HIGH){
    ligar = !ligar;
    delay(230);
    digitalWrite(clear, HIGH); //Pequena coisinha pra limpar a memoria e começar a contar certo
    delay(70);
    digitalWrite(clear, LOW);
    tempo = clock;
  }

  if((ligar == true) && ((clock - tempo)>= 45)){ //Clock do decade counter, se estiver ligado, troca o estado a cada 45 ms
    estado = !estado;
    tempo = clock;
  }

  if((estado == true) && ligar == true){ //se o estado for true e tiver ligado, o HIGH no clckpulse faz o clock funcionar
    digitalWrite(clkpulse, HIGH);
  }
  else(
    digitalWrite(clkpulse, LOW) //se o estado for falso, colocar o clckpulse no low para que a transição LOW-HIGH(que ocorre quando o estado vai pra true) faça o decade counter contar 1
  );


}
