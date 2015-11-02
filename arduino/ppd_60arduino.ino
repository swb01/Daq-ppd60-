void setup()
{
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}
float analogvalue, analogcount, LconAV, analogtotal = 0, Lugm3_2, analogvalue1, analogcount1, LconAV1, analogtotal1 = 0, Lugm3_1,analogvalue2, analogcount2, LconAV2, analogtotal2 = 0, Lugm3_3;
int i = 0;
void loop() {
  analogvalue = 0;
  for (int j = 0; j < 10; j++)
  {
    analogvalue = analogvalue + analogRead(A1);
    analogvalue1 = analogvalue1 + analogRead(A2);
    analogvalue2 = analogvalue2 + analogRead(A3);
  }
  analogvalue = analogvalue / 10;
  analogvalue1 = analogvalue1 / 10;

  analogtotal = (analogvalue * 5.0) / 1024;
  analogtotal1 = (analogvalue1 * 5.0) / 1024;
  LconAV1 = (240.0 * pow(analogtotal1, 6) - 2491.3 * pow(analogtotal1, 5) + 9448.7 * pow(analogtotal1, 4) - 14840.0 * pow(analogtotal1, 3) + 10684.0 * pow(analogtotal1, 2) + 2211.8 * (analogtotal1) + 7.9623);
  Lugm3_2 = (0.0000000495 * pow(LconAV, 2) + 0.0015247767 * (LconAV)); //Cardboard
  LconAV = (240.0 * pow(analogtotal, 6) - 2491.3 * pow(analogtotal, 5) + 9448.7 * pow(analogtotal, 4) - 14840.0 * pow(analogtotal, 3) + 10684.0 * pow(analogtotal, 2) + 2211.8 * (analogtotal) + 7.9623);
  Lugm3_1 = (0.0000000495 * pow(LconAV1, 2) + 0.0015247767 * (LconAV1)); //Cardboard
    LconAV2 = (240.0 * pow(analogtotal2, 6) - 2491.3 * pow(analogtotal2, 5) + 9448.7 * pow(analogtotal2, 4) - 14840.0 * pow(analogtotal2, 3) + 10684.0 * pow(analogtotal2, 2) + 2211.8 * (analogtotal2) + 7.9623);
      Lugm3_3 = (0.0000000495 * pow(LconAV2, 2) + 0.0015247767 * (LconAV2)); //Cardboard

  //  Serial.println(LconAV);
  if (Lugm3_2 < 0)
  {
    Lugm3_2 = 0;
  }
  //    if (i=15)
  //    {i=0;
  //  analogcount=0;}
  // Serial.print(i);
  if (Lugm3_2 >= 0)
  { Serial.println(1);

    Serial.print(Lugm3_2);
    Serial.print("\n");
  }
  if (Lugm3_1 >= 0)
  { Serial.println(2);
    Serial.print(Lugm3_1);
    Serial.print("\n");
    
    delay(500);
  }
   if (Lugm3_3 >= 0)
  { Serial.println(3);
    Serial.print(Lugm3_3);
    Serial.print("\n");
    
    delay(500);
  }
}
