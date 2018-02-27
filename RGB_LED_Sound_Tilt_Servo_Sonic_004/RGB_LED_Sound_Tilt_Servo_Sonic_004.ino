
//#include <SMH_Song.h>
#include "pitches.h"
#include <Timer.h>                     //http://github.com/JChristensen/Timer
#include <Servo.h>
#include "SR04.h"
//#include "SMH_Song_Mario.h"


// Define Pins *are 'define'/const because these should never be changed 
#define BLUE 3
#define GREEN 5
#define RED 6
#define AUD1 10
//#define AUD2 11
#define Button1 8
#define Button2 9
#define Button3 12
#define Button4 13
#define TILT 2
#define SERVO 7
#define ECHO 11
#define TRIG 4


// define variables
Servo myServo;
Timer t;
SR04 ultrasonicSensor = SR04(ECHO,TRIG);
int redValue;
int greenValue;
int blueValue;
int tiltValue;
int i=0;
int j=0;
int serRot;
long USENDist;
bool stopLoop = false;
bool Clockwise = false;
bool r = true;
int melody[] = {
                NOTE_E7, NOTE_E7, 0, NOTE_E7,
                0, NOTE_C7, NOTE_E7, 0,
                NOTE_G7, 0, 0,  0,
                NOTE_G6, 0, 0, 0,
               
                NOTE_C7, 0, 0, NOTE_G6,
                0, 0, NOTE_E6, 0,
                0, NOTE_A6, 0, NOTE_B6,
                0, NOTE_AS6, NOTE_A6, 0,
               
                NOTE_G6, NOTE_E7, NOTE_G7,
                NOTE_A7, 0, NOTE_F7, NOTE_G7,
                0, NOTE_E7, 0, NOTE_C7,
                NOTE_D7, NOTE_B6, 0, 0,
               
                NOTE_C7, 0, 0, NOTE_G6,
                0, 0, NOTE_E6, 0,
                0, NOTE_A6, 0, NOTE_B6,
                0, NOTE_AS6, NOTE_A6, 0,
               
                NOTE_G6, NOTE_E7, NOTE_G7,
                NOTE_A7, 0, NOTE_F7, NOTE_G7,
                0, NOTE_E7, 0, NOTE_C7,
                NOTE_D7, NOTE_B6, 0, 0
               };
//Mario main them tempo
int tempo[] = {
              12, 12, 12, 12,
              12, 12, 12, 12,
              12, 12, 12, 12,
              12, 12, 12, 12,
             
              12, 12, 12, 12,
              12, 12, 12, 12,
              12, 12, 12, 12,
              12, 12, 12, 12,
             
              9, 9, 9,
              12, 12, 12, 12,
              12, 12, 12, 12,
              12, 12, 12, 12,
             
              12, 12, 12, 12,
              12, 12, 12, 12,
              12, 12, 12, 12,
              12, 12, 12, 12,
             
              9, 9, 9,
              12, 12, 12, 12,
              12, 12, 12, 12,
              12, 12, 12, 12,
              };               


void setup()
{
Serial.begin(9600);
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
pinMode(AUD1, OUTPUT);
//pinMode(AUD2, OUTPUT);
pinMode(Button1,INPUT_PULLUP);
pinMode(Button2,INPUT_PULLUP);
pinMode(Button3,INPUT_PULLUP);
pinMode(Button4,INPUT_PULLUP);
pinMode(TILT,OUTPUT);
digitalWrite(RED, HIGH);
digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, HIGH);
digitalWrite(TILT,HIGH);
myServo.attach(SERVO);
//t.every(1000,takeReadingB);
t.every(500,takeReadingI);
//t.every(500,takeReadingS);
}


// main loop
void loop()
{
#define delayTime 10
stopLoop = false;
tiltValue = digitalRead(2);
USENDist = ultrasonicSensor.Distance();
t.update();

if(HIGH==tiltValue)
{
 if(serRot<=0)Clockwise ==true;
 if(serRot>=180)Clockwise ==false;
//  
//  if(Clockwise)serRot+=1;
//  if(!Clockwise)serRot-=1;
//  
  //myServo.write(serRot);              
//   //delay(7);
 
    
  if(digitalRead((Button1)== LOW) || digitalRead((Button2)== LOW) || digitalRead((Button3)== LOW) || digitalRead((Button4)== LOW)  )
  { 
    stopLoop = true;
    if (digitalRead(Button1) == LOW)
      {
        stopLoop = true;
        ToggleLight(RED,true);
        ToggleLight(BLUE,true);
      }
    else
      {
        stopLoop = false;
      }
    if (digitalRead(Button2) == LOW)
    {
      for( int i=0;i<15;i++)
      {
        if (digitalRead(Button1) == LOW)
        {
           break;
        }
        ToggleLight(RED,true);
        ToggleLight(BLUE,true);
        delay(40);
        ToggleLight(RED,false);
        ToggleLight(BLUE,false);
        delay(50);
      }
      ToggleLight(RED,false);
      ToggleLight(BLUE,false);
  
    }
  
    if(digitalRead(Button3)==LOW)
    {   
 
//        for (serRot = 0; serRot < 179; serRot += 1) 
//        {
//          myServo.write(serRot);            
//          delay(8);  
//        }
    }
  
    if(digitalRead(Button4)==LOW)
    { 
//       for (serRot = 180; serRot > 1; serRot -= 1) 
//        {
//          myServo.write(serRot);            
//          delay(17);                      
//        }
      
        //SMH_Song::play(11, SMH_Song_Mario);
  //    int size = sizeof(melody) / sizeof(int);
  //    for (int thisNote = 0; thisNote < size; thisNote++) {
  // 
  //      int noteDuration = 1000 / tempo[thisNote];
  // 
  //      tone(AUD2, melody[thisNote], noteDuration);
  // 
  //      int pauseBetweenNotes = noteDuration * 1.30;
  //      delay(pauseBetweenNotes);
  // 
  //      // stop the tone playing:
  //      tone(AUD2, 0, noteDuration);
   
      } 
   
    
  
  } 

        if(USENDist <= 15)
      {
        if(r)
          {
            r=false;
            startAudio();
          }
      }
  }
else
{ 
  if(r)
      {
        r=false;
        startAudio();
      }
      
}
}



void ToggleLight(int color,bool on)
{
  if(on == true)on == HIGH ;
  else on == LOW;
  digitalWrite(color,on);
}
//
//void Fade(int s,bool y)
//{
//
//redValue = 255; // choose a value between 1 and 255 to change the color.
//greenValue = 0;
//blueValue = 0;
//
//for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
//{
//redValue -= 1;
//greenValue += 1;
//if(y)break;
//if(digitalRead((Button1)== LOW) || digitalRead((Button2)== LOW) || digitalRead((Button3)== LOW) || digitalRead((Button4)== LOW)  )break;
//analogWrite(RED, redValue);
//analogWrite(GREEN, greenValue);
//delay(s);
//}
//
//redValue = 0;
//greenValue = 255;
//blueValue = 0;
//
//for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
//{
//greenValue -= 1;
//blueValue += 1;
//if(y)break;
//if(digitalRead((Button1)== LOW) || digitalRead((Button2)== LOW) || digitalRead((Button3)== LOW) || digitalRead((Button4)== LOW)  )break;
//analogWrite(GREEN, greenValue);
//analogWrite(BLUE, blueValue);
//delay(s);
//}
//
//redValue = 0;
//greenValue = 0;
//blueValue = 255;
//
//for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
//{
//// The following code has been rearranged to match the other two similar sections
//blueValue -= 1;
//redValue += 1;
//if(y)break;
//if(digitalRead((Button1)== LOW) || digitalRead((Button2)== LOW) || digitalRead((Button3)== LOW) || digitalRead((Button4)== LOW)  )break;
//analogWrite(BLUE, blueValue);
//analogWrite(RED, redValue);
//delay(s);
//
//}
//}

void startAudio()
{

       int i=0;
       int j=0;
       for(i=0;i<80;i++)
       {
           digitalWrite(AUD1,HIGH);
           delay(1);//wait for 1ms
           digitalWrite(AUD1,LOW);
           delay(1);//wait for 1ms
       }
       for(j=0;j<100;j++)
       {
           digitalWrite(AUD1, HIGH);
           delay(1);//wait for 2ms
           digitalWrite(AUD1,LOW);
           delay(2);//wait for 2ms
       }
       r = true;
}

//void takeReadingB()
//{
//    Serial.print("Value :");
//    Serial.println(tiltValue);
//}
void takeReadingI()
{
    Serial.print("Value of int is :");
    //Serial.println(serRot);
    Serial.println(USENDist);
}
//void takeReadingS()
//{
//    Serial.print("Value of String is :");
//    Serial.print(digitalRead(Button3));
//    Serial.print('\t');
//    Serial.println(digitalRead(Button4));
//}

