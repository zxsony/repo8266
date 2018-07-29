#ifdef AM2320
void AM23020Read (){
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
      Serial.print("Not transmission.\r\n");
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
    am2320h = ((float)(((am2320buf[2] << 8) + am2320buf[3]) / 10.0) + 15.7);//16.3-89 14.16-82.46 20.1-90.6 29,4-15,7
    am2320t = ((float)(((am2320buf[4] << 8) + am2320buf[5]) / 10.0) - 0.33);// 26.77-(-.33) 
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
