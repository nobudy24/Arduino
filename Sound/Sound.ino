

int buzzer = 12;//the pin of the active buzzer
void setup()
{
 pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}
void loop()
{
 while(1)
 {
   int i=0;
   int j=0;
   for(i=0;i<80;i++)
   {
       digitalWrite(buzzer,HIGH);
       delay(1);//wait for 1ms
       digitalWrite(buzzer,LOW);
       delay(1);//wait for 1ms
   }
   for(j=0;j<100;j++)
   {
       digitalWrite(buzzer,HIGH);
       delay(2);//wait for 2ms
       digitalWrite(buzzer,LOW);
       delay(2);//wait for 2ms
   }
  }
} 
