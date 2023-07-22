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

### **Arduino Uno code** " Attached under the name "LED-BUTTON-CODE" in this repository." 
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
"C:\Users\rawna\Downloads\Untitled video - Made with Clipchamp (1).mp4"

## 2. Arduino UNO with a 25 LEDs as a LED Matrix

### **Circuit Components :** 
  **1.**  Arduino UNO\
  **2.**  25 LEDs\
  **3.**  220 ohm resistor\
  **4.**  220 ohm resistor ( for the LED )\
  **5.**  Breadboard\




