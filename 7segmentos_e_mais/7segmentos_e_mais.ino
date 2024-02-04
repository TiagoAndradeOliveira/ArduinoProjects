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
#define I5 12

//Infelizmente usar DIP switches não funciona muito bem, aí tem que usar o  BNG e 5V e trocar manualmente cada botão
//Conectar da maneira como está no define as portas e onde deve ir cada parte do circuito

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

// 0
if((digitalRead(I0) == LOW) && (digitalRead(I1) == LOW) && (digitalRead(I2) == LOW) && (digitalRead(I3) == LOW))
{
  digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, LOW);
}
else //1
if((digitalRead(I0) == HIGH) && (digitalRead(I1) == LOW) && (digitalRead(I2) == LOW) && (digitalRead(I3) == LOW))
{
  digitalWrite(a, LOW);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);digitalWrite(g, LOW);
}
else //2
if((digitalRead(I0) == LOW) && (digitalRead(I1) == HIGH) && (digitalRead(I2) == LOW) && (digitalRead(I3) == LOW))
{
  digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, LOW);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, LOW);digitalWrite(g, HIGH);
}
else //3
if((digitalRead(I0) == HIGH) && (digitalRead(I1) == HIGH) && (digitalRead(I2) == LOW) && (digitalRead(I3) == LOW))
{
  digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, LOW);digitalWrite(f, LOW);digitalWrite(g, HIGH);
}
else //4
if((digitalRead(I0) == LOW) && (digitalRead(I1) == LOW) && (digitalRead(I2) == HIGH) && (digitalRead(I3) == LOW))
{
  digitalWrite(a, LOW);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
}
else //5
if((digitalRead(I0) == HIGH) && (digitalRead(I1) == LOW) && (digitalRead(I2) == HIGH) && (digitalRead(I3) == LOW))
{
  digitalWrite(a, HIGH);digitalWrite(b, LOW);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, LOW);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
}
else //6
if((digitalRead(I0) == LOW) && (digitalRead(I1) == HIGH) && (digitalRead(I2) == HIGH) && (digitalRead(I3) == LOW))
{
  digitalWrite(a, HIGH);digitalWrite(b, LOW);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
}
else //7
if((digitalRead(I0) == HIGH) && (digitalRead(I1) == HIGH) && (digitalRead(I2) == HIGH) && (digitalRead(I3) == LOW))
{
  digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);digitalWrite(g, LOW);
}
else //8
if((digitalRead(I0) == LOW) && (digitalRead(I1) == LOW) && (digitalRead(I2) == LOW) && (digitalRead(I3) == HIGH))
{
  digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
}
else //9
if((digitalRead(I0) == HIGH) && (digitalRead(I1) == LOW) && (digitalRead(I2) == LOW) && (digitalRead(I3) == HIGH))
{
  digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, LOW);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
}
else 
 //10 = A
if((digitalRead(I0) == LOW) && (digitalRead(I1) == HIGH) && (digitalRead(I2) == LOW) && (digitalRead(I3) == HIGH))
{
  digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, LOW);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
}
else //11 = B
if((digitalRead(I0) == HIGH) && (digitalRead(I1) == HIGH) && (digitalRead(I2) == LOW) && (digitalRead(I3) == HIGH))
{
  digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
}
else //12 = c
if((digitalRead(I0) == LOW) && (digitalRead(I1) == LOW) && (digitalRead(I2) == HIGH) && (digitalRead(I3) == HIGH))
{
  digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, LOW);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, LOW);digitalWrite(g, HIGH);
}
else //13 = H
if((digitalRead(I0) == HIGH) && (digitalRead(I1) == LOW) && (digitalRead(I2) == HIGH) && (digitalRead(I3) == HIGH))
{
  digitalWrite(a, LOW);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, LOW);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
}
else //14 = o
if((digitalRead(I0) == LOW) && (digitalRead(I1) == HIGH) && (digitalRead(I2) == HIGH) && (digitalRead(I3) == HIGH))
{
  digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, LOW);digitalWrite(g, HIGH);
}
else //15 = F
if((digitalRead(I0) == HIGH) && (digitalRead(I1) == HIGH) && (digitalRead(I2) == HIGH) && (digitalRead(I3) == HIGH))
{
  digitalWrite(a, HIGH);digitalWrite(b, LOW);digitalWrite(c, LOW);digitalWrite(d, LOW);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);
}
//dot
  if(digitalRead(I5) == HIGH){
    digitalWrite(dot, HIGH);
  }else{digitalWrite(dot, LOW);}
}
