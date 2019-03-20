//#include <IRLibAll.h>
#include <IRremote.h>
#include <Servo.h> 

// You will have to set these values depending on the protocol
// and remote codes that you are using. These are For the Adafruit
// Mini Remote
//#define MY_PROTOCOL NEC
#define POWER_BUTTON        16580863 //Move servo clockwise
#define VOLUME_UP_BUTTON    16613503 //Move servo counterclockwise
#define FUNC/STOP_BUTTON    16597183 //Center the servo
#define REVERSE_BUTTON      16589023 //Increased number of degrees servo moves
#define PLAY_BUTTON         16621663 //Decrease number of degrees servo moves
#define FORWARD_BUTTON      16605343  //Pushing buttons 0-9 moves to fixed positions
#define DOWN_BUTTON         16584943  // each 20 degrees greater
#define VOLUME_DOWN_BUTTON  16617583
#define UP_BUTTON 16601263
#define BUTTON_0  16593103
#define BUTTON_5  16625743
#define BUTTON_6  16609423
#define BUTTON_1  16582903
#define BUTTON_2  16615543
#define BUTTON_3  16599223
#define BUTTON_4  16591063
#define BUTTON_5  16623703
#define BUTTON_6  16607383
#define BUTTON_7  16586983
#define BUTTON_8  16619623
#define BUTTON_9  16603303



IRrecv myReceiver(11); //pin number for the receiver
decode_results results;

Servo servoRight;  // create servo object to control a servo 
Servo servoLeft;

const int ledPinGreen =  3;      // the number of the LED pin
const int ledPinRed = 5;
const int ledPinBlue = 6;

int16_t pos;         // variable to store the servo position 
int16_t pos2;
int16_t Speed;       // Number of degrees to move each time a left/right button is pressed
uint32_t Previous;//handles NEC repeat codes

void setup() { 
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  
  servoRight.attach(9);      // attaches the servo on pin 9 to the servo object 
  servoLeft.attach(10);
  pos = 90;               // start at midpoint 90 degrees
  pos2 = 90;
//  Speed = 3;              // servo moves 3 degrees each time left/right is pushed
  servoRight.write(pos);     // Set initial position
  servoLeft.write(pos2);

  Serial.begin(9600);
  myReceiver.enableIRIn(); // Start the receiver
} 
  
void loop() 
{ 
    if (myReceiver.decode(&results)) {
      Serial.println(results.value);
 //       if(myDecoder.protocolNum==MY_PROTOCOL) {
//         if(myDecoder.value==0xFFFFFFFF)
//            myDecoder.value=Previous;
         switch(results.value) {
            case FORWARD_BUTTON: pos=2000, digitalWrite(ledPinGreen, HIGH); break;
            case REVERSE_BUTTON: pos=1000, digitalWrite(ledPinGreen, HIGH); break;
            case POWER_BUTTON:   pos=1500, pos2=1500, digitalWrite(ledPinGreen, LOW), digitalWrite(ledPinRed, LOW); break;
            case UP_BUTTON:      pos2=2000, digitalWrite(ledPinRed, HIGH); break;
            case DOWN_BUTTON:    pos2=1000, digitalWrite(ledPinRed, HIGH); break;
         }
         servoRight.writeMicroseconds(pos); // tell servo to go to position in variable 'pos' 
         servoLeft.writeMicroseconds(pos2);
         myReceiver.resume();;
       }

}

