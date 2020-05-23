#ifdef ADS1115
void ADC1115Read (){

  if (am2320En) unsigned long _tempAM2320Delay = millis();

  if (ADC1115Delay == 0){
    ADC1115Delay = millis();
  }
  if ((millis() - ADC1115Delay)<=1){
    //reset if you wish
  }
  if ((millis() - ADC1115Delay)>=2000){
    ADC1115Delay = 0; 
    #ifdef debug
      Serial.print(currentTimeDeviceString);
      Serial.print(" ADC1115 request.\r\n");
    #endif    
    adc0 = ads1115.readADC_SingleEnded(0);
    adc1 = ads1115.readADC_SingleEnded(1);
    adc2 = ads1115.readADC_SingleEnded(2);
    adc3 = ads1115.readADC_SingleEnded(3);  
  }
    if (am2320En) AM2320Delay = AM2320Delay + (millis() - _tempAM2320Delay);
    #ifdef debug
//      Serial.print("_tempAM2320Delay ");
//      Serial.println(millis() - _tempAM2320Delay);
    #endif
}
#endif
