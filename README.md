# Arduino-with-a-push-button-&-LED-matrix
This is the first task for the Electronics and Power Department. It consists of two assignments: the first involves building a circuit with an Arduino UNO and a push button, while the second involves creating my own LED matrix (DIY version ).
## 1. Arduino UNO with a Push Button to Control a LED

### **Circuit Components :** 
  **1.**  Arduino UNO\
  **2.**  Push Button\
  **3.**  LED\
  **4.**  220 ohm resistor ( for the LED )\
  **5.**  Breadboard\
Usually we need a resistor for the push button. However, since the Arduino UNO has a pull-up resistor built into it, we can enable it in code. [(Instructables, 2017)](https://www.instructables.com/Arduino-Button-with-no-resistor/)\
<br />
### **The Circuit**
  The digital pin 2 is connected to the button, and digital pin 7 is connected with the anode leg of the LED.\
<kbd>![image](https://github.com/Rawnaa-19/Arduino-UNO-Push-Button-and-LED-Matrix/assets/106926557/de2084d7-a646-422b-bd7e-2d96ee28ac43)</kbd>

### **Arduino Uno code** " Attached under the name "ARDUINO-LED-BUTTON-CODE" in this repository." 
  This code will make the LED light up for 5 seconds only when the button is pushed, otherwise the LED will be turned off.\
```
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 7;    // the number of the LED pin

int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    delay(5000);
  } else {
    // turn LED off:
   digitalWrite(ledPin, LOW);
  }
}
```
### **Code Simulation**

https://github.com/Rawnaa-19/Arduino-UNO-Push-Button-and-LED-Matrix/assets/106926557/9f3a1982-98de-4fa6-a74d-e6790e8ff849

### **Arduino UNO Code Adjustments**

 This code will turn the LED off for 5 seconds only when the button is pushed, otherwise the LED will be on.\
 ```
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 7;    // the number of the LED pin

int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, LOW);
    delay(5000);
  } else {
    // turn LED off:
   digitalWrite(ledPin, HIGH);
  }
}

 ```
### **Adujsted Code Simulation**


https://github.com/Rawnaa-19/Arduino-UNO-Push-Button-and-LED-Matrix/assets/106926557/c0b69308-cc84-4f85-a80b-6886a4d7f851


## 2. Arduino UNO with a 25 LEDs as a LED Matrix

### **Circuit Components :** 
  **1.**  Arduino UNO\
  **2.**  25 LEDs\
  **3.**  5 of 1k ohm resistors\
  
### **The Circuit** 
  The goal is to divide all 25 LEDs into a 5X5 matrix. As such, the cathode leg of each 5 LEDs will represent the rows, and the anode leg will represent the columns. Each row is connected to an Arduino pin, while each column is connected to a resistor connected to an Arduino pin. 
<kbd>![image](https://github.com/Rawnaa-19/Arduino-UNO-Push-Button-and-LED-Matrix/assets/106926557/6a092dfb-03ef-4f39-bb7a-2b056b1df72c)</kbd>

### **Arduino Uno code** " Attached under the name "ARDUINO-LED-MATRIX-CODE" in this repository." 
  By running the code below, some LEDs will light up to create a smiley face.\
```
//define column and row pin number
int rows[]={13,12,11,10,9};
int columns[]={6,5,4,3,2};
int delayTime = 300;
int matrix[5][5] = {{1,1,1,1,1},
		       {1,0,1,0,1},
		       {1,0,1,0,1},
		       {0,1,1,1,0},
		       {1,0,0,0,1}};
// initialize pin mode
void setup() {
for (int thisPin = 0; thisPin < 5; thisPin++) {
    // initialize the output pins:
    pinMode(columns[thisPin], OUTPUT);
    pinMode(rows[thisPin], OUTPUT);
  }

}
// define loop
void loop(){
  for (int c=0; c<5; c++){
    digitalWrite(columns[c], HIGH);
    for (int r = 0; r < 5; r++){
      digitalWrite(rows[r], 255*matrix[r][c]);
    delay(1);
    }
    for (int r = 0; r < 5; r++){
      digitalWrite(rows[r], HIGH);
   delay(1);
    }
  
    digitalWrite(columns[c], LOW);
  }
}
```
### **Code Simulation**

https://github.com/Rawnaa-19/Arduino-UNO-Push-Button-and-LED-Matrix/assets/106926557/199c9d72-3285-4eca-bfc2-9b624babbefa

The resistor values were adjusted to get brighter LEDs (not recommended with actual hardware settings because LEDs could burn).


https://github.com/Rawnaa-19/Arduino-UNO-Push-Button-and-LED-Matrix/assets/106926557/cf8b5d0e-7cda-47b5-a37e-8ff575a9dbf6


### **Arduino UNO Code Adjustments**
By running the code below, some LEDs will light up to create a heart.\
```
//define column and row pin number
int rows[]={13,12,11,10,9};
int columns[]={6,5,4,3,2};
int delayTime = 300;
int matrix[5][5] = {{1,1,1,1,1},
		            {0,0,1,0,0},
		            {0,0,0,0,0},
		            {1,0,0,0,1},
		            {1,1,0,1,1}};
// initialize pin mode
void setup() {
for (int thisPin = 0; thisPin < 5; thisPin++) {
    // initialize the output pins:
    pinMode(columns[thisPin], OUTPUT);
    pinMode(rows[thisPin], OUTPUT);
  }

}
// define loop
void loop(){
  for (int c=0; c<5; c++){
    digitalWrite(columns[c], HIGH);
    for (int r = 0; r < 5; r++){
      digitalWrite(rows[r], 255*matrix[r][c]);
    delay(1);
    }
    for (int r = 0; r < 5; r++){
      digitalWrite(rows[r], HIGH);
   delay(1);
    }
  
    digitalWrite(columns[c], LOW);
  }
}  
```
### **Adujsted Code Simulation**



https://github.com/Rawnaa-19/Arduino-UNO-Push-Button-and-LED-Matrix/assets/106926557/6fdd5015-dee5-4337-a7c4-9471c42cda42





