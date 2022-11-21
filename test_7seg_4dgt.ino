/* use 4-digit 7-segment display (common anode) */

/* use a 360-ohm resistor beween LED anode (selector pin) of each digit
   and arduino pin 

 7 segment mapping:    
     _
  F| A |B
     _ 
  E| G |C
     _
     D
     
*/

// selector (anode) pins
// s1=most significant digit, s4=less significant digit

int s1=13;
int s2=12;
int s3=11;
int s4=10;

// segment (cathode) pins
int a=9;
int b=8;
int c=7;
int d=6;
int e=5;
int f=4;
int g=3;

// In the following, 0 means segment on
// patterns ABCDEFG

int p_0[7]={0,0,0,0,0,0,1};
int p_1[7]={1,0,0,1,1,1,1};
int p_2[7]={0,0,1,0,0,1,0};
int p_3[7]={0,0,0,0,1,1,0};
int p_4[7]={1,0,0,1,1,0,0};
int p_5[7]={0,1,0,0,1,0,0};
int p_6[7]={0,1,0,0,0,0,0};
int p_7[7]={0,0,0,1,1,1,1};
int p_8[7]={0,0,0,0,0,0,0};
int p_9[7]={0,0,0,0,1,0,0};

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
  // initialize the digital pins as output.
  
  pinMode(s1,OUTPUT);    
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);  
  pinMode(s4,OUTPUT);  
  
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
  for (i=3;i<=9;i++)
  {
    if (pat[9-i]==1)
    {
      digitalWrite(i,HIGH);
    }
    else
    {
      digitalWrite(i,LOW);
    }
  }
}


void display_int_number(int x)
{
  int i;
  int lim=1000;
  int n;
  int a;
  int nz;
  
  nz=0;
  n=x;
  // display forom left to right
  for (i=0;i<4;i++)
  {
    // clear display
    digitalWrite(s1,LOW);
    digitalWrite(s2,LOW);
    digitalWrite(s3,LOW);
    digitalWrite(s4,LOW);
    
    if (n>lim)
    {
      nz=1;
      a=n/lim;
      switch(a)
      {
        case 1: display_pattern(p_1);
                break;
        case 2: display_pattern(p_2);
                break;
        case 3: display_pattern(p_3);
                break;
        case 4: display_pattern(p_4);
                break;
        case 5: display_pattern(p_5);
                break;
        case 6: display_pattern(p_6);
                break;
        case 7: display_pattern(p_7);
                break;
        case 8: display_pattern(p_8);
                break;
        case 9: display_pattern(p_9);
                break;
      }  
    }
    else
    {
      // display zero but avoid padding
      // if x=0, display single zero on the far-right digit-display 
      if ((nz==1) || (lim==1))
      {
        display_pattern(p_0);
      }
      else
      {
        display_pattern(p_spc);
      }
    }  
    // enable digit-display
    digitalWrite(13-i,HIGH);
    n=n%lim;
    lim=lim/10;
    delay(1);
  }
}


void loop()
{
  int x;
  
  for (x=0;x<=9999;x++)
  {
    display_int_number(x);
  }  
}


