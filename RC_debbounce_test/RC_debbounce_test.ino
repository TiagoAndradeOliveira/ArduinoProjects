/*
  Small test setup to detect if analog debouncing is working
  in this setup, we are using a pullup resistor in the button, so
  when the input is read low, the button was pressed.
*/
#define ButtonPin 2
#define HIGH 1
#define LOW 0

void setup() {
  pinMode(ButtonPin, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

bool ligar = false;
unsigned long Clock;
unsigned long LastRisingEdge = 1, LastFallingEdge = 0;
const uint8_t ReadButtonStateDelay = 10;
uint8_t COLS; //this type of variable take only 1 byte of space

int PreviousButtonState = LOW; //false means low and true means high.
int ActualButtonState;

void loop() {

  Clock = millis();
  ActualButtonState = digitalRead(ButtonPin);

  if((ActualButtonState == HIGH) && (PreviousButtonState == LOW)){
    //We just had a rising edge on the input signal.
    PreviousButtonState = HIGH;
    Serial.println("Rising edge at:");
    LastRisingEdge = Clock;
    Serial.println(Clock);
    if(LastRisingEdge == LastFallingEdge){
      ligar = ligar;
    }else{ligar = !ligar;}
  }
  if((ActualButtonState == LOW) && (PreviousButtonState == HIGH)){
    //We just had a faling edge on the input signal.
    PreviousButtonState = LOW;
    Serial.println("Falling edge at:");
    LastFallingEdge = Clock;
    Serial.println(Clock);
  }

  if(ligar == true){digitalWrite(13, HIGH);}
  else{digitalWrite(13, LOW);}

}
