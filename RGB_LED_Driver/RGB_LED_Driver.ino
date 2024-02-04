#define N 3                   //Number of colors in the RGB LED
#define NDI 7                 //Number of buttons that controls the RGB LED. NDI stands for Number of Digital Inputs
#define NDO 10
#define DebounceDelay 200     //Button Debounce Delay
#define DataOutDelay 5000     //Data out delay

int ColorValues[N] = {0,0,0}; //Store the realtime colors (Red, Green and Blue)
int PresetValue[N] = {0,0,0}; //Default Prese. Theres a button that can change it in the code.

#define RED_PIN 9             //PWM pin that controls the amount of this RED in the RGB LED     
#define GREEN_PIN 10           //PWM pin that controls the amount of this GREEN in the RGB LED
#define BLUE_PIN 11            //PWM pin that controls the amount of this BLUE in the RGB LED
//Note: I'm still looking for the most optimal resistances for a "full bright" and a dimmed version of this

#define Potentiometer A0      //Quick Definition to the potentiometer pin to make the code more readable. Connect the middle of the potentiometer to this pin in the arduino.

/*
  Auxiliary definitions to control the buttons that drives
  the RBG LED. each one of this is a button input.
*/
#define ColorUp 2             //Changes the driven LED in the sequence R G B R G B...
#define ColorDown 3           //Changes the driven LED in the sequence B G R B G R...
#define WriteColorSelect 4    //Button that selects if the potentiometer "Writes" a determined color to the RBG LED.
#define Reset 5               //Resets the RBG LED to 0, 0, 0, (turns it off).
#define PresetButton 7        //Button that changes the color to the chosen preset.
#define setPreset 8          //Button that stores the current color to make it a preset.
#define seeValues 13          //Button that shows the color precise information in the Serial Monitor.

#define newline Serial.print("\n"); //Line that prints a blank line in the Serial Monitor.

#define WriteEnableStatus 15  //AKA A1
#define PickedColorRED 18     //AKA A4
#define PickedColorGREEN 17   //AKA A3
#define PickedColorBLUE 16    //AKA A2
#define SeePWMValue 6         //Another Digital OutPut for feedback, it shows how much of the pwm was used
#define PWMMax 12
#define PWMMin 19
//make here 2 another outputs that shows if the Potentiometer is in one of its extremes.

int DigitalInputs[NDI] = {ColorUp, ColorDown, Reset, PresetButton, WriteColorSelect, setPreset, seeValues};
//The aboce array of integers contains the buttons that drives the RGB LED.

int DigitalOutputs[NDO] = {WriteEnableStatus, PickedColorRED, PickedColorGREEN, PickedColorBLUE, RED_PIN, GREEN_PIN, BLUE_PIN,SeePWMValue,PWMMax,PWMMin};

bool WriteColorEnable = false;      
unsigned long LastTimeButtonPressed;
unsigned long Clock;
unsigned long LastTimeDataOut;
int ColorSelect = 0;  //This variable s the current picked color, 0 = RED, 1 = GREEN and 2 = BLUE.
int i,j;
int PotentiometerRead;


void setup() {
//Starting Serial Monitor communication
Serial.begin(4800);

//Declaring all Digital Output pins
for(i=0;i<NDO;i++){
  pinMode(DigitalOutputs[i], OUTPUT);
}

//Declaring all digital input pins
for(i=0;i<NDI;i++){
  pinMode(DigitalInputs[i], INPUT_PULLUP);
}

}

void loop() {
  
  Clock = millis();

  //Color Write Enable
  if(((digitalRead(WriteColorSelect) == 0)) && ((Clock - LastTimeButtonPressed) > DebounceDelay)){
    LastTimeButtonPressed = Clock;
    WriteColorEnable = !WriteColorEnable;
    Serial.println("\nButton pin 9 was pressed. New Stored Value:");
    Serial.print(WriteColorEnable);
    newline
  }
  //Color Select Up Enable
  if(((digitalRead(ColorUp) == 0)) && ((Clock - LastTimeButtonPressed) > DebounceDelay)){
    LastTimeButtonPressed = Clock;
    if(ColorSelect == 2){ColorSelect = 0;}
    else{ColorSelect++;}
    Serial.println("\nNewColorSelect:");
    Serial.print(ColorSelect);
    newline
  }
  //Color Select Down Enable
  if(((digitalRead(ColorDown) == 0)) && ((Clock - LastTimeButtonPressed) > DebounceDelay)){
    LastTimeButtonPressed = Clock;
    if(ColorSelect == 0){ColorSelect = 2;}
    else{ColorSelect--;}
    Serial.println("\nNewColorSelect:");
    Serial.print(ColorSelect);
    newline
  }

  if(((digitalRead(Reset) == 0)) && ((Clock - LastTimeButtonPressed) > DebounceDelay)){
    LastTimeButtonPressed = Clock;
    for(i=0;i<N;i++){
      ColorValues[i] = 0;
    }
  }
  //PresetButton logic
  if(((digitalRead(setPreset) == 0)) && ((Clock - LastTimeButtonPressed) > DebounceDelay)){
    LastTimeButtonPressed = Clock;
      Serial.println("\nPreset Seted.");
      for(i=0;i<N;i++){
        PresetValue[i] = ColorValues[i];
      }
      newline
  }

  if(((digitalRead(PresetButton) == 0)) && ((Clock - LastTimeButtonPressed) > DebounceDelay)){
    LastTimeButtonPressed = Clock;
    Serial.println("Putting preset value in color values.");
    for(i=0;i<N;i++){
      ColorValues[i] = PresetValue[i];
    }
    newline
  }

  PotentiometerRead = (analogRead(Potentiometer)/4);
  if(WriteColorEnable == true){
    ColorValues[ColorSelect] = PotentiometerRead;
    digitalWrite(WriteEnableStatus, HIGH);
  }else{digitalWrite(WriteEnableStatus, LOW);}

  //Lastily, Writing the color of each one of the pins of the RBG LED.
  analogWrite(RED_PIN, ColorValues[0]);
  analogWrite(GREEN_PIN, ColorValues[1]);
  analogWrite(BLUE_PIN, ColorValues[2]);
  analogWrite(SeePWMValue, PotentiometerRead);
  //note: see if this can be substituted with an "for" loop
  if((ColorSelect == 0)){
    digitalWrite(PickedColorRED, HIGH);
    digitalWrite(PickedColorGREEN, LOW);
    digitalWrite(PickedColorBLUE, LOW);
  }
  if((ColorSelect == 1)){
    digitalWrite(PickedColorRED, LOW);
    digitalWrite(PickedColorGREEN, HIGH);
    digitalWrite(PickedColorBLUE, LOW);
  }
  if((ColorSelect == 2)){
    digitalWrite(PickedColorRED, LOW);
    
    digitalWrite(PickedColorGREEN, LOW);
    digitalWrite(PickedColorBLUE, HIGH);
  }
  if(PotentiometerRead == 0){digitalWrite(PWMMin, HIGH);}
  else{digitalWrite(PWMMin, LOW);}
  if(PotentiometerRead == 255){digitalWrite(PWMMax, HIGH);}
  else{digitalWrite(PWMMax, LOW);}

  if((digitalRead(seeValues) == 0) && ((Clock - LastTimeButtonPressed) > DebounceDelay)){
    LastTimeButtonPressed = Clock;
    Serial.println("\n\nValues stored:");
    Serial.print("RED:");Serial.print(ColorValues[0]);
    Serial.print("\nGREEN:");Serial.print(ColorValues[1]);
    Serial.print("\nBLUE:");Serial.print(ColorValues[2]);
  }
}
