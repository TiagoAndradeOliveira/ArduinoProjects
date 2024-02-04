/*
  Testing INPUT_PULLUP pinMode and debouncing techniques.

  According to arduino site: When connecting a sensor to a pin configured with INPUT_PULLUP, 
  the other end should be connected to ground. In the case of a simple switch, this causes the 
  pin to read HIGH when the switch is open, and LOW when the switch is pressed.

  The pin in INPUT_PULLUP mode should have and end connected to ground (in the buutton) and another to the digital pin
  port that it is going to read.

  in INPUT_PULLUP, the pin read LOW when PRESSED.
*/

#define LED 13
#define button 2

unsigned long Clock; //This variable will be used to store the value of millis(); function, to make the code easier to write and read.
unsigned long LastTimeButtonPressed; //This variable will store the last value of millis(); that the button was pressed.
unsigned long Timer;

bool ligar = false; //Thiis variable will store if the LED will be turned on or off. It is inicialized in false to have it started in LOW.

int estado; //This variable will store the value of the button, wheter its pressed or not. Remember how input pullup works.

int const DebounceDelay = 200; //Variable that stores the debounce delay of the button.

void setup() {

  Serial.begin(4800);
 
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);

}

void loop() {

  Clock = millis(); //Storing millis() in clock variable
  
  estado = digitalRead(button); // Lendo o valor do botão

  //Função esperta de Debounce usando o millis(evitando assim o desastre que é o delay()). Essa função é ativida quando
  //o botão(no pinMode(INPUT_PULLUP)) é pressionado, e só muda o estado da variável relacioanada ao botão somente se
  //a última vez que o botão foi pressionado ocorreu num tempo maior que o debounce delay, evitando assim leituras incorretas
  if((estado == LOW) && (Clock - LastTimeButtonPressed) > DebounceDelay){
    LastTimeButtonPressed = Clock;
    ligar = !ligar;
  }//else{ligar = ligar;} depois descobri que essa parte é desnecessária. Ver AdderAndSubtracterWbuttons

  //Apenas imprimir o estado da variável ligar a cada 60 ms, para melhor visualização da variável
  if(Clock -Timer >= 60){
    Timer = Clock;
    Serial.println(ligar);
  }

  //Última lógica do programa, que determina se o LED deve ligar ou nao com base no estado da variável 'ligar'
  if(ligar == true){
    digitalWrite(LED, HIGH);
  }else{digitalWrite(LED, LOW);}

}
