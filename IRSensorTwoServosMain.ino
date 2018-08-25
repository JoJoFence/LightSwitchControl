#include <IRLibAll.h>
#include <Servo.h> 

// You will have to set these values depending on the protocol
// and remote codes that you are using. These are For the Adafruit
// Mini Remote
#define MY_PROTOCOL NEC
#define RIGHT_ARROW   0xfd50af //Move servo clockwise
#define LEFT_ARROW    0xfd10ef //Move servo counterclockwise
#define SELECT_BUTTON 0xfd906f //Center the servo
#define UP_ARROW      0xfda05f //Increased number of degrees servo moves
#define DOWN_ARROW    0xfdb04f //Decrease number of degrees servo moves
#define BUTTON_0 0xfd30cf  //Pushing buttons 0-9 moves to fixed positions
#define BUTTON_1 0xfd08f7  // each 20 degrees greater
#define BUTTON_2 0xfd8877
#define BUTTON_3 0xfd48b7
#define BUTTON_4 0xfd28d7
#define BUTTON_5 0xfda857
#define BUTTON_6 0xfd6897
#define BUTTON_7 0xfd18e7
#define BUTTON_8 0xfd9867
#define BUTTON_9 0xfd58a7

IRrecv myReceiver(11); //pin number for the receiver
IRdecode myDecoder;

Servo myServo;  // create servo object to control a servo 
Servo myServo2;

const int ledPinGreen =  13;      // the number of the LED pin
const int ledPinRed = 10;

int16_t pos;         // variable to store the servo position 
int16_t pos2;
int16_t Speed;       // Number of degrees to move each time a left/right button is pressed
uint32_t Previous;//handles NEC repeat codes

void setup() { 
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  
  myServo.attach(9);      // attaches the servo on pin 9 to the servo object 
  myServo2.attach(3);
  pos = 90;               // start at midpoint 90 degrees
  pos2 = 90;
//  Speed = 3;              // servo moves 3 degrees each time left/right is pushed
  myServo.write(pos);     // Set initial position
  myServo2.write(pos2);
  myReceiver.enableIRIn(); // Start the receiver
} 
  
void loop() 
{ 
    if (myReceiver.getResults()) {
       myDecoder.decode();
       if(myDecoder.protocolNum==MY_PROTOCOL) {
         if(myDecoder.value==0xFFFFFFFF)
            myDecoder.value=Previous;
         switch(myDecoder.value) {
            case LEFT_ARROW:    pos=7*20, digitalWrite(ledPinGreen, HIGH); break;
            case RIGHT_ARROW:   pos=4*20, digitalWrite(ledPinGreen, HIGH); break;
            case SELECT_BUTTON: pos=90, pos2=90, digitalWrite(ledPinGreen, LOW), digitalWrite(ledPinRed, LOW); break;
            case UP_ARROW:      pos2=7*20, digitalWrite(ledPinRed, HIGH); break;
            case DOWN_ARROW:    pos2=4*20, digitalWrite(ledPinRed, HIGH); break;
         }
         myServo.write(pos); // tell servo to go to position in variable 'pos' 
         myServo2.write(pos2);
         Previous=myDecoder.value;
       } 
       myReceiver.enableIRIn();
    }
}
