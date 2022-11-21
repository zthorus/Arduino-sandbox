/* Test of LM386 amplifier */

// Pin 13 conected to amp input
// Pin 3 connected to on/off switch

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(13,OUTPUT);
  pinMode(3,INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  int i,j;
  if (digitalRead(3)==LOW)
  {
   /* for (i=10;i<500;i++)
    {*/
    // play sound
       digitalWrite(13, HIGH);
       delayMicroseconds(1000);
       digitalWrite(13, LOW);
       delayMicroseconds(1000);
    //}
  }
}
