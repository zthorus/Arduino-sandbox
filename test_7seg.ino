/* test 7-segment display (LTS-312AR, common anode) */

/* use a 330-ohm resistor beween LED cathode and ground.

 7 segment mapping:   
     _
  F| A |B
     _ 
  E| G |C
     _
     D
     
*/

int a=13;
int b=12;
int c=11;
int d=10;
int e=9;
int f=8;
int g=7;



int j=8;
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(a,OUTPUT);    
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  digitalWrite(g,HIGH);
}

// the loop routine runs over and over again forever:
// make "circling" effect (g sement not used)
void loop()
{
  for (j=8;j<13;j++)
  {
    for (int i=8;i<=13;i++)
    {
      if ((i==j) || (i==(j+1)) || ((j==13) && (i==8))) 
      {
        digitalWrite(i,LOW);
      } 
      else
      {
        digitalWrite(i,HIGH);
      }
    }
    delay(100);
  }
}


