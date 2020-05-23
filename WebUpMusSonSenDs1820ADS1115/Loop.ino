
void loop(void){
//if (!ledSensorState){
// watchdogCount = 0; 
//}
  watchdogCount = 0;
  if (digitalRead(button) == LOW){while(1){}};
  if (ledblink){
    digitalWrite(ledCurrent, HIGH);
    delay(1);
    digitalWrite(ledCurrent, LOW);
    delay(1);
  }


  if (ultrasonicEn){
    averageUltrasonic();
    CheckUltrasonic(); 
  }
  #ifdef IRSensorEn
    CheckIRSensor();
  #endif 
  //
  if (analogSensorEn){
    //analogSensorValue = analogRead(sensorPin);
    ReadLedSensor();
    CheckLedSensor();
  }
  //
  if (tempEn){
    DsRead ();
    DsTempCalc(); 
//DallRead( flagDallRead*1000 );
  }

  if (ntpEn){ 
    updateCurrentDateTime() ;
//    testByte = timeM;
    CheckTimeEvents();
    CheckTimeEvent(); // New!!!
    //WIFIcheck();
    checkNtpUpdate();
    }
  
  #ifdef ADS1115
    ADC1115Read ();
  #endif
  
  if (am2320En) AM23020Read ();

  //Serial.println(day);
   
  GetServerIndex();

  GetXmlData();
  
  server.handleClient();

  delay(10);
} 
