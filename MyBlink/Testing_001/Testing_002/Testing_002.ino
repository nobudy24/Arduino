
int i = 0;
#define BLUE 3
#define GREEN 5
#define RED 6

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  
  digitalWrite(RED,HIGH);
  digitalWrite(GREEN,LOW);
  digitalWrite(BLUE,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
     digitalWrite(13,HIGH);
     delay(i);
     digitalWrite(13,LOW);
     delay(500);
     i+=100;
     if(i>=1500)i=0;
        
}
