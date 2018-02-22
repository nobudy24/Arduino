
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  
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
