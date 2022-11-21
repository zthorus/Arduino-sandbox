
// 1-D Flappy-Bird !

const int t_d=15;
const float g=-0.000003;

void setup()
{
  int i;
  for (i=4;i<=13;i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(3,INPUT_PULLUP);
  Serial.begin(115200);
}

void loop()
{
  float y=5.0;
  float a=0.00003;
  float v=0; 
  int y_a[6];
  int t_a[6];
  int l[6];
  int i;
  float y_wu=10;
  float y_wd=1;
  unsigned long t_s; 
  int n_off;
  int k=0;
  int q=0;
  int ju=0;
  
  while((y>(y_wd)) && (y<(y_wu)))
  {  
    // wall calculation 
    
    // (=pseudo Dirac comb)
    //  y_wd=0+(3-cos((float)k*0.01)-cos((float)k*0.02)-cos((float)k*0.03))/2;
    //  y_wu=11-(3-cos((float)k*0.015)-cos((float)k*0.03)-cos((float)k*0.45))/2; 
    
    y_wd=3*cos((float)k*0.01)*cos((float)k*0.01)*k/1500;
    y_wu=11-3*cos((float)k*0.01)*cos((float)k*0.01)*k/1500; 
    if (y_wd>4)
    {
      y_wd=4;
    }
    if (y_wu<7)
    {
      y_wu=7;
    }
    
    // display bird (blinking) and walls with sub-pixel position accuracy (pulse-width modulation)
    /* note: although calculated, we won't display y_a[3] and y_a[4] (upper of top
       wall and lower part of bottom wall)
    */
    y_a[0]=floor(y);
    y_a[1]=y_a[0]+1;
    y_a[2]=floor(y_wu);
    y_a[3]=y_a[2]+1;
    y_a[4]=floor(y_wd);
    y_a[5]=y_a[4]+1; 
    t_a[0]=(1-(y-y_a[0]))*t_d;
    t_a[1]=(y-y_a[0])*t_d;
    t_a[2]=(1-(y_wu-y_a[2]))*t_d;
    t_a[3]=(y_wu-y_a[2])*t_d;
    t_a[4]=(1-(y_wd-y_a[4]))*t_d;
    t_a[5]=(y_wd-y_a[4])*t_d;
    // draw walls
    for (i=1;i<=y_a[4];i++)
    {
      digitalWrite(3+i,HIGH);
    }
    for (i=10;i>=y_a[3];i--)
    {
      digitalWrite(3+i,HIGH);
    }
    Serial.print(t_a[2]);
    Serial.println("\t");
    Serial.print(t_a[5]);
    Serial.println("\t");
    Serial.println("");
    
    // draw non-binary intensities (3 pixels)
    
    for (i=0;i<6;i++)
    {
       if ((i!=3) && (i!=4) && (((3+y_a[i])>=4) && ((3+y_a[i])<=13)))
       {
       //  if (((q<6) && (i!=0)) || ((q>=6) && (i!=1)))
       //  {
           digitalWrite(3+y_a[i],HIGH);
       //  }
       }
       l[i]=1;
    }
    t_s=millis();
    n_off=0;
    while (n_off<4)
    {
       for (i=0;i<6;i++)
       {
         if ((i!=3) && (i!=4) && ((millis()-t_s)>t_a[i]) && (l[i]==1))
          {
            if (((3+y_a[i])>=4) && ((3+y_a[i])<=13))
            {
              digitalWrite(3+y_a[i],LOW);
            }
            l[i]=0;
            n_off++;
          }
       }
    }
    while ((millis()-t_s)<t_d);
    // make sure all pixels off
    for (i=4;i<=13;i++)
    {
      digitalWrite(i,LOW);
    }
    // control of bird
    if (digitalRead(3)==LOW)
    {
      if (ju==0)
      {   
        v=-30*g*t_d;
        ju=1;
      }
    }
    else
    {
      ju=0;
      v=v+g*t_d;
    }
    y=y+v*t_d;
    if (y>10) 
    {
      y=10;
    }
    if (y<1)
    {
      y=1;
    }
  
    k++;
    q++;
    if (q>=12)
    {
      q=0;
    }
  }
  // game over
  for (i=0;i<4;i++)
  {
    digitalWrite(4,HIGH);
    delay(150);
    digitalWrite(4,LOW);
    delay(150);
  }
}
