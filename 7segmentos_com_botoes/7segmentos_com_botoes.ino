#define dot 0
#define a 1
#define b 2 
#define c 3 
#define d 4
#define e 5
#define f 6
#define g 7

#define I0 8
#define I1 9
#define I2 10
#define I3 11
#define I4 12

bool E0 = false;
bool E1 = false;
bool E2 = false;
bool E3 = false;
bool E4 = false;
bool ligar = true;

/*
Esse programa permite controlar um visor de 7 segmentos usando 5 botões, dos quais I0 até I3 controlam, respectivamente, os bit 0,1,2,3 para poder formar os números de 0 a 9
em binário. Esse botões devem ser conectados na parte do mei da protoboard, com o fio de input no lado superior esquerdo, um resistor de 100k no lado inferior esquerdo, e um
fio de alimentação 5V no lado superior direito. Com todos os botões conectados dessa forma nas respectivas porta listadas acima, é só conectar, de acordo com as portas, do 
jeito correto o visor de 7 segmentos. o botão I4, ou o quinto botão, é responsável por ligar e desligar o visor.
*/
void setup() {
  
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);

}

void loop() {


  if(digitalRead(I0) == HIGH){ //BIT 0 do 7segment
    E0 = !E0;
    delay(150);
  }
  if(digitalRead(I1) == HIGH){ //BIT 1 do 7segment
    E1 = !E1;
    delay(150);
  }
  if(digitalRead(I2) == HIGH){ //BIT 2 do 7segment
    E2 = !E2;
    delay(150);
  }
  if(digitalRead(I3) == HIGH){ //BIT 3 do 7segment
    E3 = !E3;
    delay(150);
  }
  if(digitalRead(I4) == HIGH){ //botão liga/desliga
    E4 = !E4;
    delay(150);
  }

  //Análise individual de casos, convertendo binário para 7 segmentos
  //0
  if((E0 == false) && (E1 == false) && (E2 == false) && (E3 == false) && (ligar == true)){
    digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, LOW);
  }
  //1
  if((E0 == true) && (E1 == false) && (E2 == false) && (E3 == false) && (ligar == true)){
    digitalWrite(a, LOW);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);digitalWrite(g, LOW);
  }
  //2
  if((E0 == false) && (E1 == true) && (E2 == false) && (E3 == false) && (ligar == true)){
    digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, LOW);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, LOW);digitalWrite(g, HIGH);
  }
  //3
  if((E0 == true) && (E1 == true) && (E2 == false) && (E3 == false) && (ligar == true)){
    digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, LOW);digitalWrite(f, LOW);digitalWrite(g, HIGH);
  }
  //4
  if((E0 == false) && (E1 == false) && (E2 == true) && (E3 == false) && (ligar == true)){
    digitalWrite(a, LOW);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
  }
  //5
  if((E0 == true) && (E1 == false) && (E2 == true) && (E3 == false) && (ligar == true)){
    digitalWrite(a, HIGH);digitalWrite(b, LOW);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, LOW);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
  }
  //6
  if((E0 == false) && (E1 == true) && (E2 == true) && (E3 == false) && (ligar == true)){
    digitalWrite(a, HIGH);digitalWrite(b, LOW);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
  }
  //7
  if((E0 == true) && (E1 == true) && (E2 == true) && (E3 == false) && (ligar == true)){
    digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);digitalWrite(g, LOW);
  }
  //8
  if((E0 == false) && (E1 == false) && (E2 == false) && (E3 == true) && (ligar == true)){
    digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
  }
  //9
  if((E0 == true) && (E1 == false) && (E2 == false) && (E3 == true) && (ligar == true)){
    digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, LOW);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
  }
  if(ligar == false){
    digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, LOW);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);digitalWrite(g, LOW);
  }

  if(E4 == true){
    digitalWrite(dot, HIGH);
    ligar = false;E0 =false;E1 =false;E2 =false;E3 =false;
  }else{
    digitalWrite(dot, LOW);ligar = true;
  }

  

}
