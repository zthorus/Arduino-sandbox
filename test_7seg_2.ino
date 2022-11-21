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


/* patterns ABCDEFG
*/

int p_H[7]={1,0,0,1,0,0,0};
int p_O[7]={0,0,0,0,0,0,1};
int p_L[7]={1,1,1,0,0,0,1};
int p_A[7]={0,0,0,1,0,0,0};
int p_J[7]={1,0,0,0,0,1,1};
int p_I[7]={1,0,0,1,1,1,1};
int p_M[7]={0,0,0,1,0,0,1};
int p_E[7]={0,1,1,0,0,0,0};
int p_spc[7]={1,1,1,1,1,1,1};

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
}


void display_pattern(int *pat)
{
  int i;
  for (i=7;i<=13;i++)
  {
    if (pat[13-i]==1)
    {
      digitalWrite(i,HIGH);
    }
    else
    {
      digitalWrite(i,LOW);
    }
  }
  delay(500);
}

void circle_effect(int d)
{
  int i;
  int j;
  int k;
  
  digitalWrite(g,HIGH);
  for (k=1;k<d;k++)
  {
    for (j=8;j<13;j++)
    {
      for (i=8;i<=13;i++)
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
      delay(70);
    }
  }
}


void loop()
{
  circle_effect(10);
  display_pattern(p_spc);
  display_pattern(p_H);
  display_pattern(p_O);
  display_pattern(p_L);
  display_pattern(p_A);
  display_pattern(p_spc);
  display_pattern(p_J);
  display_pattern(p_A);
  display_pattern(p_I);
  display_pattern(p_M);
  display_pattern(p_E);
}


