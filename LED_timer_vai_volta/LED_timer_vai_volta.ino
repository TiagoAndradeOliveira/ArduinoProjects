#define L1 11
#define L2 10
#define L3 9
#define L4 6
#define L5 5
#define L6 3
int value;
unsigned long Clock;
unsigned long TempoAtual;
unsigned long Timer;
bool indo=true;
int val;
int lvl;
int lvl2;
int i=0;

void setup() {

  Serial.begin(4800);

  pinMode(A1, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
}

void loop() {
  
  Clock =  millis();
  
  /*value = analogRead(A1);
  
  if(Clock - TempoAtual >=50){
  TempoAtual = Clock;
  Serial.println(value);
  Serial.println(value/4);
  }
  analogWrite(L1, value / 4);
  */

  //val = analogRead(A1);
  
  val = i;

  lvl = map(lvl, 0, 170, 0, 255);
  lvl2 = map(lvl2, 0, 170, 255, 0);

  if((val <= 170) && (indo == true)){                   //LED 1
    lvl = val;
    analogWrite(L1, lvl);
    analogWrite(L2, 0);
    analogWrite(L3, 0);
    analogWrite(L4, 0);
    analogWrite(L5, 0);
    analogWrite(L6, 0);
  }
  if((val > 170) && (val <= 340) && (indo == true)){  //LED 2
    lvl = (val-170);
    lvl2 = (val-170);
    analogWrite(L1, lvl2);
    analogWrite(L2, lvl);
    analogWrite(L3, 0);
    analogWrite(L4, 0);
    analogWrite(L5, 0);
    analogWrite(L6, 0);
  }
  if((val > 340) && (val <= 510) && (indo == true)){  //LED 3
    lvl = (val-340);
    lvl2 = (val-340);
    analogWrite(L1, 0);
    analogWrite(L2, lvl2);
    analogWrite(L3, lvl);
    analogWrite(L4, 0);
    analogWrite(L5, 0);
    analogWrite(L6, 0);
  }
  if((val > 510) && (val <= 680) && (indo == true)){  //LED 4
    lvl = (val-510);
    lvl2 = (val-510);
    analogWrite(L1, 0);
    analogWrite(L2, 0);
    analogWrite(L3, lvl2);
    analogWrite(L4, lvl);
    analogWrite(L6, 0);
    analogWrite(L5, 0);
  }
  if((val > 680) && (val <= 850) && (indo == true)){  //LED 5
    lvl = (val-680);
    lvl2 = (val-680);
    analogWrite(L1, 0);
    analogWrite(L2, 0);
    analogWrite(L3, 0);
    analogWrite(L4, lvl2);
    analogWrite(L5, lvl);
    analogWrite(L6, 0);
  }
  if((val > 850) && (val <= 1023) && (indo == true)){  //LED 6
    lvl = (val-850);
    lvl2 = (val-850);
    analogWrite(L1, 0);
    analogWrite(L2, 0);
    analogWrite(L3, 0);
    analogWrite(L4, 0);
    analogWrite(L5, lvl2);
    analogWrite(L6, lvl);
  }

  if((Clock - Timer >= 3) && (indo == true)){
    Timer = Clock;
    if(i<1023){i++;}
    if(i >= 1023){indo = false;}
  }
  if((Clock - Timer >= 3) && (indo == false)){
    Timer = Clock;
    if(i>0){i--;}
    if(i <= 0){indo = true;}
  }

  if(Clock - TempoAtual >=50){
  TempoAtual = Clock;
  Serial.println(lvl);
  }

  /*if(val <= 170){                   //LED 1
    lvl = val;
    analogWrite(L1, lvl);
    analogWrite(L2, 0);
    analogWrite(L3, 0);
    analogWrite(L4, 0);
    analogWrite(L5, 0);
    analogWrite(L6, 0);
  }
  if((val > 170) && (val <= 340)){  //LED 2
    lvl = (val-170);
    analogWrite(L1, 255);
    analogWrite(L2, lvl);
    analogWrite(L3, 0);
    analogWrite(L4, 0);
    analogWrite(L5, 0);
    analogWrite(L6, 0);
  }
  if((val > 340) && (val <= 510)){  //LED 3
    lvl = (val-340);
    analogWrite(L1, lvl);
    analogWrite(L2, 255);
    analogWrite(L3, lvl);
    analogWrite(L4, 0);
    analogWrite(L5, 0);
    analogWrite(L6, 0);
  }
  if((val > 510) && (val <= 680)){  //LED 4
    lvl = (val-510);
    analogWrite(L1, 0);
    analogWrite(L2, lvl);
    analogWrite(L3, 255);
    analogWrite(L4, lvl);
    analogWrite(L6, 0);
    analogWrite(L5, 0);
  }
  if((val > 680) && (val <= 850)){  //LED 5
    lvl = (val-680);
    analogWrite(L1, 0);
    analogWrite(L2, 0);
    analogWrite(L3, lvl);
    analogWrite(L4, 255);
    analogWrite(L5, lvl);
    analogWrite(L6, 0);
  }
  if((val > 850) && (val <= 1023)){  //LED 6
    lvl = (val-850);
    analogWrite(L1, 0);
    analogWrite(L2, 0);
    analogWrite(L3, 0);
    analogWrite(L4, 0);
    analogWrite(L5, 255);
    analogWrite(L6, lvl);
  }
*/


}
