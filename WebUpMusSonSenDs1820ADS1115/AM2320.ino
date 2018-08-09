#define AM2320_i2C_ADDRESS  0xB8
unsigned char am2320buf[8];
float am2320h, am2320t;
float AM2320hPrev = 255;
float AM2320tPrev = 255;
bool am2320Request;
bool AM2320PrevSet;

  
#ifdef AM2320
int _cou = 0;


//unsigned long AM2320DelayPrev = 0; 
void AM23020Read (){
  //if (AM2320DelayPrev == 0) AM2320DelayPrev = millis();
  #ifdef debug
  Serial.print(_cou);
  Serial.print(" am3020 in count.\r\n");
  _cou ++;
  #endif
   
  #ifdef ADS1115
  unsigned long _tempADC1115Delay = millis();
  #endif
  
  //if (AM2320Delay == 0){
    if (am2320Request){
    AM2320Delay = millis();
    am2320Request = false;
  }
  if ((millis() - AM2320Delay)<=1){
    #ifdef debug
      Serial.print(currentTimeDeviceString);
      Serial.print(" AM2320 transmission.\r\n");
    #endif    
    Wire.beginTransmission(AM2320_i2C_ADDRESS>>1);
    Wire.endTransmission();
    Wire.beginTransmission(AM2320_i2C_ADDRESS>>1);
    Wire.write(0x03);
    Wire.write(0x00);
    Wire.write(0x04);
    delay(100);
    if (Wire.endTransmission(1) != 0){
//      am2320buf[2] = 0;
//      am2320buf[3] = 0;
//      am2320buf[4] = 0;
//      am2320buf[5] = 0;
    #ifdef debug
    Serial.print("Not transmission.\r\n");
    #endif  
    }
  }
  if ((millis() - AM2320Delay)>=1600){
    //AM2320Delay = 0;
    am2320Request = true;
    #ifdef debug
      Serial.print(currentTimeDeviceString);
      Serial.print(" AM2320 request.");
      Serial.println(millis() - AM2320Delay);
    #endif
    Wire.requestFrom(AM2320_i2C_ADDRESS>>1, 8, 1);
      while (Wire.available())
    {
    for (int i = 0; i < 8; i++) am2320buf[i] = Wire.read();
    }
    if (am2320buf[2] == 0 & am2320buf[3] == 0){
      #ifdef debug
      Serial.print(currentTimeDeviceString);
      Serial.print(" Null. Delay ");
      Serial.println(millis() - AM2320Delay);
      #endif
    }
    am2320h = ((float)(((am2320buf[2] << 8) + am2320buf[3]) / 10.0) + 15.5);//16.3-89 14.16-82.46 20.1-90.6 29,4-15,7
    //(iva/2320) (27.77 88 / 27.77 72.5)15.5
    am2320t = ((float)(((am2320buf[4] << 8) + am2320buf[5]) / 10.0) - 1.2);// 26.77-(-.33) 
if (AM2320hPrev == 255) AM2320hPrev = am2320h;
if (AM2320tPrev == 255) AM2320tPrev = am2320t;
if (AM2320PrevSet){
  AM2320hPrev = am2320h;
  AM2320tPrev = am2320t;
  AM2320PrevSet = false;
}

    
  }
  #ifdef ADS1115
    ADC1115Delay = ADC1115Delay + (millis() - _tempADC1115Delay);
    #ifdef debug
//      Serial.print("_tempADC1115Delay ");
//      Serial.println(millis() - _tempADC1115Delay);
    #endif
  #endif  
  }
#endif
