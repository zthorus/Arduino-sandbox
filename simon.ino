/* Simon */

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
  
  randomSeed(analogRead(0));
}


void loop()
{
  int i,j,a,s;
  int n=0;
  int g=1;
  int p[50];
  
  while (g==1)
  {
    p[n]=random(4);
    n=n+1;
    /* play sequence */
    delay(1000);
    for (i=0;i<n;i++)
    {
      digitalWrite(10+p[i],HIGH);
      delay(500);
      digitalWrite(10+p[i],LOW);
      delay(100);
    }
    /* ask to repeat sequence */
    for (i=0;i<n;i++)
    {
      s=0;
      j=0;
      /* pool keys */
      while (s==0)
      {
        a=digitalRead(6+j);
        if (a==LOW)
        {
          s=1;
        }
        else
        {
          j=j+1;
          if (j>3)
          {
            j=0;
          }
        }
      }  
      /* check input */
      if (j==p[i])
      {
        /* good => turn on lamp */
        digitalWrite(10+p[i],HIGH);
        delay(500);
        digitalWrite(10+p[i],LOW);
      }
      else
      {
        /* lost => bail out */
        g=0;
        i=n;
      }
    } 
  }
  
  /* end-of-game animation */
  for (i=0;i<7;i++)
  {
    for (n=0;n<4;n++)
    {
      digitalWrite(10+n,HIGH);
      delay(50);
      digitalWrite(10+n,LOW);
    }
    for (n=2;n>0;n--)
    {
      digitalWrite(10+n,HIGH);
      delay(50);
      digitalWrite(10+n,LOW);
    }
  }
}    
