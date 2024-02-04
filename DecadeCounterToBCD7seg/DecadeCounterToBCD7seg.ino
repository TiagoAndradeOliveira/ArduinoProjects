#define Q0 2
#define Q1 3
#define Q2 4
#define Q3 5
#define Q4 6
#define Q5 7
#define Q6 8
#define Q7 9
#define Q8 10
#define Q9 11

int i;

void setup() {

  for(i = 2;i<11;i++){
    pinMode(i, INPUT);
  } 
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3 OUTPUT); 

}

void loop() {
  if(digitalRead(Q0) == HIGH){
    digitalWrite(A0, LOW);digitalWrite(A1, LOW);digitalWrite(A2, LOW);digitalWrite(A3, LOW);
  }
  if(digitalRead(Q1) == HIGH){
    digitalWrite(A0, HIGH);digitalWrite(A1, LOW);digitalWrite(A2, LOW);digitalWrite(A3, LOW);
  }
  if(digitalRead(Q2) == HIGH){
    digitalWrite(A0, LOW);digitalWrite(A1, HIGH);digitalWrite(A2, LOW);digitalWrite(A3, LOW);
  }
  if(digitalRead(Q3) == HIGH){
    digitalWrite(A0, HIGH);digitalWrite(A1, HIGH);digitalWrite(A2, LOW);digitalWrite(A3, LOW);
  }
  if(digitalRead(Q4) == HIGH){
    digitalWrite(A0, LOW);digitalWrite(A1, LOW);digitalWrite(A2, HIGH);digitalWrite(A3, LOW);
  }
  if(digitalRead(Q5) == HIGH){
    digitalWrite(A0, HIGH);digitalWrite(A1, LOW);digitalWrite(A2, HIGH);digitalWrite(A3, LOW);
  }
  if(digitalRead(Q6) == HIGH){
    digitalWrite(A0, LOW);digitalWrite(A1, HIGH);digitalWrite(A2, HIGH);digitalWrite(A3, LOW);
  }
  if(digitalRead(Q7) == HIGH){
    digitalWrite(A0, HIGH);digitalWrite(A1, HIGH);digitalWrite(A2, HIGH);digitalWrite(A3, LOW);
  }
  if(digitalRead(Q8) == HIGH){
    digitalWrite(A0, LOW);digitalWrite(A1, LOW);digitalWrite(A2, LOW);digitalWrite(A3, HIGH);
  }
  if(digitalRead(Q9) == HIGH){
    digitalWrite(A0, HIGH);digitalWrite(A1, LOW);digitalWrite(A2, LOW);digitalWrite(A3, HIGH);
  }

}
