#define NO          5   //Number of Output Pins   

#define DataPin     8  //Data pin
#define Debounce    250 //Debounce timer

#define ClockPin    12  //Clock pin 
#define ClockPin_I  7   //Inverted clock pin

#define ResetPin    10  //Reset pin
#define ResetPin_I  9   //Inverted reset pin

#define ResetButton 2   //Pin of the reset button

uint8_t OutputPins[NO] = {DataPin, ClockPin, ClockPin_I, ResetPin, ResetPin_I};

bool data, dataChange; //Thiis variale track if the data changed. If it did, call the ShiftDataIn Function.

uint8_t i, Centenas, Dezenas, Unidades;
uint16_t NewData, BCD, dataOut; //Variable that will store the data that is going to the shift register
int dataIn;
unsigned long Clock, LastTimeButtonPressed, LastTimeCounted;
bool test = false;
// Example 4 - Receive a number as text and convert it to an int

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;

int dataNumber = 0;             // new for this version


void setup(){

  Serial.begin(9600);
  
  for(i = 0; i<NO; i++){
    pinMode(OutputPins[i], OUTPUT);
  }
  pinMode(13, OUTPUT);
  pinMode(ResetButton, INPUT_PULLUP);
  Serial.println("<Arduino is ready>");

}

void showNewNumber() {
    if (newData == true) {
        dataNumber = 0;             // new for this version
        dataNumber = atoi(receivedChars);   // new for this version
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        Serial.print("Data as Number ... ");    // new for this version
        Serial.println(dataNumber);     // new for this version
        BCD = ConvertToBCD(dataNumber);
        Serial.print("Number in BCD:");
        Serial.println(BCD, BIN);
        ShiftOut(BCD);
        newData = false;
    }
}

uint16_t ShiftOut(uint16_t dataOut){
  uint8_t i;
  bool data;
  for(i=0;i<12;i++){
    digitalWrite(DataPin, LOW);
    digitalWrite(ClockPin, LOW);
    digitalWrite(ClockPin_I, HIGH);
    data = (dataOut & 1);
    digitalWrite(DataPin, data);
    digitalWrite(ClockPin, HIGH);
    digitalWrite(ClockPin_I, LOW);
    delayMicroseconds(1);    //Datasheet Specifies  a MINIMUM clock pulse-Width f 160 ns.
    digitalWrite(ClockPin, LOW);
    digitalWrite(ClockPin_I, HIGH);
    digitalWrite(DataPin, LOW);
    dataOut = (dataOut >> 1);  
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

  Serial.print("centenas: ");
  Serial.println(centenas);
  Serial.print("dezenas: ");
  Serial.println(dezenas);
  Serial.print("unidades: ");
  Serial.println(unidades);

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
  Serial.println(BCD, BIN);

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
  Serial.println(BCD, BIN);

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
  
  Serial.println(BCD, BIN);


  //with this above, we have the values of each position
  return BCD;
}

void ResetShiftRegisters(){
  LastTimeButtonPressed = Clock;
  digitalWrite(ClockPin, LOW);
  digitalWrite(ClockPin_I, HIGH);
  delay(10);
  digitalWrite(ClockPin, HIGH);
  digitalWrite(ClockPin_I, LOW);
  delay(10);
  digitalWrite(ResetPin, HIGH);
  digitalWrite(ResetPin_I, LOW);
  digitalWrite(ClockPin, LOW);
  digitalWrite(ClockPin_I, HIGH);
  delay(10);
  digitalWrite(ClockPin, HIGH);
  digitalWrite(ClockPin_I, LOW);
  test = !test;
}

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    if (Serial.available() > 0) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void loop(){

  Clock = millis();

  recvWithEndMarker();
  showNewNumber();

  //Reset Button Setup
  if((digitalRead(ResetButton) == 0) && ((Clock - LastTimeButtonPressed) > Debounce)){
    ResetShiftRegisters();
  }
  else{
    digitalWrite(ResetPin, LOW);
    digitalWrite(ResetPin_I, HIGH);
  }

  if(test == true){digitalWrite(13, HIGH);}else{digitalWrite(13, LOW);}




} // End of void loop()
