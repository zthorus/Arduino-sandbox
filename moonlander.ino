
const int t_d=15;
const float g=-0.000005;

void setup()
{
  int i;
  for (i=4;i<=13;i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(3,INPUT_PULLUP);
  pinMode(2,OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  float y=10.0;
  float a=0.000007;
  float v=0; 
  int y_a;
  int t_a;
  int t_b;
  int i;
  
  while(y>1.3)
  {  
    // display sprite with sub-pixel position accuracy (pulse-width modulation)
    y_a=floor(y);
    t_a=(1-(y-y_a))*t_d;
    t_b=(y-y_a)*t_d;
    if (t_a>t_b)
    {
      digitalWrite(3+y_a,HIGH);
      digitalWrite(3+y_a+1,HIGH);
      delay(t_b);
      digitalWrite(3+y_a+1,LOW);
      delay(t_a-t_b);
      digitalWrite(3+y_a,LOW);
      delay(t_b);
    }
    else
    {
      digitalWrite(3+y_a,HIGH);
      digitalWrite(3+y_a+1,HIGH);
      delay(t_a);
      digitalWrite(3+y_a,LOW);
      delay(t_b-t_a);
      digitalWrite(3+y_a+1,LOW);
      delay(t_a);
    }
      
    // mechanics
    if (digitalRead(3)==LOW)
    {   
      v=v+(g+a)*t_d;
    }
    else
    {
      v=v+g*t_d;
    }
    y=y+v*t_d;
    if (y>10) 
    {
      y=10;
    }
    if (abs(v)>0.0015)
    {
      digitalWrite(2,LOW);
    }
    else
    {
      digitalWrite(2,HIGH);
    }
  }
  // check landing speed
  //Serial.print(v,6);
  //Serial.println("");
  if (abs(v)>0.0015)
  {
    for (i=0;i<3;i++)
    {
      digitalWrite(4,HIGH);
      delay(300);
      digitalWrite(4,LOW);
      delay(300);
    }
  }
  else
  {
    for (i=4;i<=13;i++)
    {
      digitalWrite(i,HIGH);
      delay(100);
    }
    for (i=4;i<=13;i++)
    {
      digitalWrite(i,LOW);
      delay(100);
    }
  }
}
