/*
  Testing INPUT_PULLUP pinMode and debouncing techniques.

  According to arduino site: When connecting a sensor to a pin configured with INPUT_PULLUP, 
  the other end should be connected to ground. In the case of a simple switch, this causes the 
  pin to read HIGH when the switch is open, and LOW when the switch is pressed.

  The pin in INPUT_PULLUP mode should have and end connected to ground (in the buutton) and another to the digital pin
  port that it is going to read.

  in INPUT_PULLUP, the pin read LOW when PRESSED.
*/

int L[5] = {13,12,11,10,9}; // My LED string

#define I1 2
#define I2 3

unsigned long Clock; //This variable will be used to store the value of millis(); function, to make the code easier to write and read.
unsigned long LastTimeButtonPressed; //This variable will store the last value of millis(); that the button was pressed.
unsigned long Timer; //variavble that allows a more pleasant to see SeriaComunication (updates serial output every 60ms)

int count = 0;

int E1; //This variable will store the value of the button 1
int E2;

int const DebounceDelay = 200; //Variable that stores the debounce delay of the button.

int i;

void setup() {

  Serial.begin(4800);
 
  for(i=0;i<5;i++){
    pinMode(L[i], OUTPUT); //defining all pins of LEDS has outputs
  }
  pinMode(I1, INPUT_PULLUP);
  pinMode(I2, INPUT_PULLUP);

}

void loop() {

  Clock = millis(); //Storing millis() in clock variable
  
  E1 = digitalRead(I1); // Lendo o valor do botão 1
  E2 = digitalRead(I2); // Lendo o valor do botão 2

  //botão responsável por AUMENTAR somente uma vez o valor da variável com o Debounce que garante isso
  if((E1 == LOW) && (Clock - LastTimeButtonPressed) > DebounceDelay){
    LastTimeButtonPressed = Clock;
    count++;
    if(count == 5){count = 0;} //Como a lista vai de 0 até 4, se o botão for apertado na posição [4], count vai pra [5] que é fora da range
  }                            //da lista de LEDS. quando count vale 5, seu valor é resetado

  //botão responsável por DIMINUIR somente uma vez o valor da variável com o Debounce que garante isso
  if((E2 == LOW) && (Clock - LastTimeButtonPressed) > DebounceDelay){
    LastTimeButtonPressed = Clock;
    count--;
    if(count == -1){count = 4;} //mesma lógica da de cima, para loopar corretamente as variáveis
  }

  if(Clock - Timer >= 60){
    Timer = Clock;
    Serial.println(count);
  }

  //Verifica o valor da variável e somente liga o LED correspondente a posição da variável na lista
  for(i=0;i<5;i++){
    if(count == i){
      digitalWrite(L[i], HIGH);
    }else{digitalWrite(L[i], LOW);}
  }


  


}
