// constants won't change. They're used here to
// set pin numbers:
#include <Servo.h>
Servo myServo;        // Create Servo object to control the servo 
Servo myServo2;   
   //Serial.begin(9600);
   //Serial.println("setup");

   //myServo2.attach(3);  // Servo is connected to digital pin 3 
const int buttonPinGreen = 6;     // the number of the pushbutton pin
const int buttonPinRed = 7;
const int ledPinGreen =  13;      // the number of the LED pin
const int ledPinRed = 10;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int position = 0;

void setup() {
 myServo.attach(9);  // Servo is connected to digital pin 9
 myServo2.attach(3);
 
  // initialize the LED pin as an output:
  pinMode(ledPinGreen, OUTPUT);
  pinMode(buttonPinGreen, INPUT);
  
  pinMode(ledPinRed, OUTPUT);
  pinMode(buttonPinRed, INPUT);
  // initialize the pushbutton pin as an input:

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPinGreen);
  buttonState2 = digitalRead(buttonPinRed);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH && buttonState2 == LOW)
  {
    // turn LED on:
    digitalWrite(ledPinGreen, HIGH);
     myServo.writeMicroseconds(2000);  // Counter clockwise
  }
  else {
    // turn LED off:
    digitalWrite(ledPinGreen, LOW);
  }
  
  if (buttonState == LOW && buttonState2 == HIGH) 
  {
    // turn LED on:
    digitalWrite(ledPinRed, HIGH);
    myServo2.writeMicroseconds(2000);  // Clockwise
  }
  else 
  {
    // turn LED off:
    digitalWrite(ledPinRed, LOW);
  }
  
  if (buttonState == LOW && buttonState2 == LOW)
  {
    digitalWrite(ledPinGreen, LOW);
    digitalWrite(ledPinRed, LOW);
     myServo.writeMicroseconds(1500);  // Counter clockwise
    Serial.println("stop"); 
     myServo2.writeMicroseconds(1500);
    Serial.println("stop");
    delay(5);
  }
}
   
 
