#define NO          6   //Number of Output Pins   

#define DataPin     8  //Data pin
#define Debounce    250 //Debounce timer

#define ClockPin    12  //Clock pin 
#define ClockPin_I  7   //Inverted clock pin

#define ResetPin    10  //Reset pin
#define ResetPin_I  9   //Inverted reset pin

#define Button 2        //Pin that starts the counting;
#define TimerDelay 1000 //This variable is the time, in miliseconds, in which the timer will add up

uint8_t OutputPins[NO] = {DataPin, ClockPin, ClockPin_I, ResetPin, ResetPin_I, 13};

unsigned long Clock, LastTimeButtonPressed, Timer;

uint16_t counter; //This variable will count the seconds that had had passed since the button press
uint16_t BCD = 0b0000000000000000;     //This variable will store the BCD Value of the counter that will be shifted out
bool ON = false;

uint16_t ShiftOut(uint16_t dataOut){
  
  uint8_t i;
  bool data;
  for(i=0;i<12;i++){
    digitalWrite(DataPin, LOW);
    digitalWrite(ClockPin, LOW);
    digitalWrite(ClockPin_I, LOW);
    data = (dataOut & 1);
    digitalWrite(DataPin, data);
    digitalWrite(ClockPin, HIGH);
    delayMicroseconds(1);    //Datasheet Specifies  a MINIMUM clock pulse-Width f 160 ns.
    digitalWrite(ClockPin, LOW);
    digitalWrite(DataPin, LOW);
    dataOut = (dataOut >> 1);  
    digitalWrite(ClockPin_I, HIGH); //This is the latch pin in the 74HC595. It latches in a rising edge. thats why 
    //it was setted has LOW in the beggining of the shiftOut process
  }
  return 0;
}
uint16_t ConvertToBCD(int dataIn){  //Very important to put the int type in the function declaration
  
  int centenas, dezenas, unidades;
  uint16_t BCD = 0b000000000000001; //this one in the left is to shift values correctly, in the case of 000, for example, ith shifts the '0000' four times each to make the correct bcd value of 000 beeing 0000 0000 0000

  centenas = (dataIn / 100);
  dataIn = (dataIn - (centenas*100));
  dezenas = (dataIn / 10);
  unidades = (dataIn % 10);

  //Serial.print("centenas: ");
  //Serial.println(centenas);
  //Serial.print("dezenas: ");
  //Serial.println(dezenas);
  //Serial.print("unidades: ");
  //Serial.println(unidades);

  if(centenas == 0){BCD = 0b0000000000000000;};
  if(centenas == 1){BCD = 0b0000000100000000;};
  if(centenas == 2){BCD = 0b0000001000000000;};
  if(centenas == 3){BCD = 0b0000001100000000;};
  if(centenas == 4){BCD = 0b0000010000000000;};
  if(centenas == 5){BCD = 0b0000010100000000;};
  if(centenas == 6){BCD = 0b0000011000000000;};
  if(centenas == 7){BCD = 0b0000011100000000;};
  if(centenas == 8){BCD = 0b0000100000000000;};
  if(centenas == 9){BCD = 0b0000100100000000;};
  //Serial.println(BCD, BIN);

  if(dezenas == 0){BCD = BCD + 0b0000000000000000;};
  if(dezenas == 1){BCD = BCD + 0b0000000000010000;};
  if(dezenas == 2){BCD = BCD + 0b0000000000100000;};
  if(dezenas == 3){BCD = BCD + 0b0000000000110000;};
  if(dezenas == 4){BCD = BCD + 0b0000000001000000;};
  if(dezenas == 5){BCD = BCD + 0b0000000001010000;};
  if(dezenas == 6){BCD = BCD + 0b0000000001100000;};
  if(dezenas == 7){BCD = BCD + 0b0000000001110000;};
  if(dezenas == 8){BCD = BCD + 0b0000000010000000;};
  if(dezenas == 9){BCD = BCD + 0b0000000010010000;};
  //Serial.println(BCD, BIN);

  if(unidades == 0){BCD = BCD + 0b0000000000000000;};
  if(unidades == 1){BCD = BCD + 0b0000000000000001;};
  if(unidades == 2){BCD = BCD + 0b0000000000000010;};
  if(unidades == 3){BCD = BCD + 0b0000000000000011;};
  if(unidades == 4){BCD = BCD + 0b0000000000000100;};
  if(unidades == 5){BCD = BCD + 0b0000000000000101;};
  if(unidades == 6){BCD = BCD + 0b0000000000000110;};
  if(unidades == 7){BCD = BCD + 0b0000000000000111;};
  if(unidades == 8){BCD = BCD + 0b0000000000001000;};
  if(unidades == 9){BCD = BCD + 0b0000000000001001;};
  
  //Serial.println(BCD, BIN);


  //with this above, we have the values of each position
  return BCD;
}

void setup() {

  Serial.begin(9600);
  
  for(int i = 0; i<NO; i++){
    pinMode(OutputPins[i], OUTPUT);
  }
  pinMode(Button, INPUT_PULLUP);
  digitalWrite(ResetPin, LOW);
  digitalWrite(ResetPin_I, HIGH);
  Serial.println("<Arduino is Ready>");

}

void loop() {

  BCD = ConvertToBCD(counter);

  Clock = millis();

  if(((Clock - Timer) >= TimerDelay) && (ON == true)){
    Timer = Clock;
    counter++;
    Serial.print("Counter: ");
    Serial.println(counter);
    if(counter == 1000){counter = 0;}
    ShiftOut(BCD);
  }

  if(((digitalRead(Button) == 0) && (Clock - LastTimeButtonPressed) >= Debounce)){
    LastTimeButtonPressed = Clock;
    ON = !ON;
  }
  digitalWrite(13, ON); //ON is a 'bool' type variable, but, it also works with digital write, because LOW = 0 = false, and HIGH = 1 = true


}
