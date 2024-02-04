#define RED 6
#define BLU 5

unsigned long Clock;
unsigned long Timer;

int val;

void setup() {
  
  Serial.begin(4800);
  
  pinMode(RED, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(A1, INPUT);

}

void loop() {
  
  Clock = millis();
  val = analogRead(A1);
  
  if((val < 255)){
    analogWrite(BLU, (255-val));
    analogWrite(RED, 255);
  }
  if((val >= 255) && (val < 511)){
    analogWrite(BLU, 0);
    analogWrite(RED, (510-val));
  }
  if((val >= 511) && (val < 767)){
      analogWrite(BLU, (val - 511));
      analogWrite(RED, 0);
  }
  if((val >= 767) && (val <=1023)){
      analogWrite(BLU, 255);
      analogWrite(RED, ((val-1) - 767));
  }
  
  
  
  if((Clock - Timer) >= 60){
    Timer = Clock;
    Serial.println(val);
  }


  

}
