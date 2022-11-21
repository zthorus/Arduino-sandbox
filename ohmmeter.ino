// ohm-meter
// plug resistor to measure between A0 and GND


const float R_PULLUP = 38.9;  //in k ohms

void setup()
{
    pinMode(A0, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop()
{
   float r;
   int v;
   
   v=analogRead(A0);
   r=R_PULLUP/(1023/v-1);
   
   Serial.print("R = ");
   Serial.print(r);
   Serial.print(" K");
   Serial.println("");
}
