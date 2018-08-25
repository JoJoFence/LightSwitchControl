#include <Servo.h>

const int buttonPinGreen = 6;
const int buttonPinRed = 7;
const int ledPinGreen = 11;
const int ledPinRed = 13;

int buttonStateGreen = 0;
int buttonStateRed = 0;
int position = 0;

Servo servoA;
Servo servoB;

void setup() {
  // put your setup code here, to run once:
  servoA.attach(9);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(buttonPinGreen, INPUT);

  servoB.attach(3);
  pinMode(ledPinRed, OUTPUT);
  pinMode(buttonPinRed, INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonStateGreen = digitalRead(buttonPinGreen);
  buttonStateRed = digitalRead(buttonPinRed);
  
  if (buttonStateGreen == HIGH) {
  
    digitalWrite(ledPinGreen, HIGH);
  }
    
  else {
    
    digitalWrite(ledPinGreen, LOW);
  }
  
  if (buttonStateRed == HIGH) {
  
    digitalWrite(ledPinRed, HIGH);
    
  } 
  
  else {
    
    digitalWrite(ledPinRed, LOW);
  }
 
  if (buttonStateGreen == HIGH && position < 180) {

  servoA.write(position++);

  } 
  
  else {
    Serial.println("stop");

  }

  if (buttonStateRed == HIGH && position > 3) {

  servoB.write(position--);

  } 
  
  else {
    Serial.println("stop");

  }
 }
