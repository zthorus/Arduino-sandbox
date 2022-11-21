/* test of setup for Simon */

// the setup routine runs once when you press reset:
void setup() {    
  /* keys (connected to ground if pressed) */  
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
   
  /* lamps */ 
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  
  randomSeed(analogRead(0));
}


void loop()
{
  int i,a;
  
  for (i=0;i<4;i++)
  {
    a=digitalRead(6+i);
    if (a==LOW)
    {
      digitalWrite(10+i,HIGH);
      delay(500);
      digitalWrite(10+i,LOW);
    }
  }
}  
