// mic test

int x,y;
int s;
int i;

void setup() {
  Serial.begin(115200);
}

void loop() {

  s=0;
  y=0;
  
  for (i=0;i<50;i++)
  {
    x=analogRead(A0);
    s=s+abs(x-y);
    delay(1);
    y=x;
  }
  Serial.print(("analog in = "));
  Serial.print(s);
  Serial.println(F(" "));
}
