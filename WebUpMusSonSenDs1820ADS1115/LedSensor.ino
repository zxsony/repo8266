 
 void CheckLedSensor (void){

  if (LightActivityDelay != 0){
  if ((millis() - LightActivityDelay)>=180000 and LightActivityState1 == true){
    if (mp3En){
      mp3_set_volume (28);
      delay(100);
      mp3_play (28);//101
      delay(100);
      LightActivityState1 = false;
      //LightActivityDelay = 0;
    }
  }
    if ((millis() - LightActivityDelay)>=300000 and LightActivityState2 == true){
    if (mp3En){
      mp3_set_volume (28);
      delay(100);
      mp3_play (29);//102
      delay(100);
      LightActivityState2 = false;
      //LightActivityDelay = 0;
    }
  }
      if ((millis() - LightActivityDelay)>=10000 and LightActivityState3 == true){
    if (mp3En){
      mp3_set_volume (32);
      delay(100);
      mp3_play (15);
      delay(100);
      LightActivityState3 = false;
      //LightActivityDelay = 0;
    }
  }
  }
  
  if ((ledSensorValue >= 80) and (ledSensorState == false)) {
    
    if (LightActivityDelay == 0){
      LightActivityDelay = millis();
      LightActivityState1 = true;
      LightActivityState2 = true;
      LightActivityState3 = true;
  }  

    ledSensorState = true;
    //ledCurrent = ledPinGR1;
    if((((millis()/1000) - soundDelay/1000)>3)){
    soundDelay = millis();
        if (mp3En){
          mp3_set_volume (30);//30
          delay(100);
          if (ledSensorValue > 100 and ledSensorValue < 150){
            mp3_play (6);//6
          }
          else {
            mp3_play (8);//8  
          }
          //mp3_play (27);
          delay(500);
        }
}
    switchOn = true;
    switchOnCounter += 1;
    FS_FileWrite("/Sensors.txt", "Led:" + (String)switchOnCounter + ";Val:" + ledSensorValue);
  }
  if ((ledSensorValue < 50) and (ledSensorState == true)) {
    ledSensorState = false;
    LightActivityState1 = false;
    LightActivityState2 = false;
    LightActivityState3 = false;
    LightActivityDelay = 0;
    //ledCurrent = ledPinGR1;
    if((((millis()/1000) - soundDelay/1000)>3)){
    soundDelay = millis();
    if (mp3En){
      mp3_set_volume (27);
      delay(100);      
      mp3_play (6);
      //mp3_play (27);
      delay(10);      
    }

    }
    switchOn = false;
  }
}
 void ReadLedSensor (void){
  int r[3];
  for (int i = 0; i<3; i++) {
    r[i] = analogRead(sensorPin);
    delay(10);
    }
  int ra = (r[0]+r[1]+r[2])/3;

//if (ra > 145) r[0]=100;
  
  for (int i = 0; i < 3; i++){
    if (abs(r[i] - ra) > 10){
//    soundDelay = millis();
//    mp3_play (7);
//    delay(100);
//    mp3_set_volume (10);
//    delay(1000);
      return;
    }
  }
    ledSensorValue = ra;
}
  























 
