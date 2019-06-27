
void CheckTimeEvents(){
  //if (mp3En){
  
  if ((timeM == 0) and (timeH == 0)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (212);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 1)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (201);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 2)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (202);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 3)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (203);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 4)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (204);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 5)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (205);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 6)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (206);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 7)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (207);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 30) and (timeH == 7)){//будильник
  if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
    soundDelay = millis();
    mp3_play (3);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
}
  if ((timeM == 0) and (timeH == 8)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (20);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 9)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (209);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 10)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
    soundDelay = millis();
    mp3_play (210);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 11)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (211);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 12)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (212);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }  
  if ((timeM == 0) and (timeH == 13)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (201);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 14)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (202);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 15)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (203);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 16)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (204);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 17)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (205);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 18)){
    SetSensorTable();
      if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
        soundDelay = millis();
        mp3_play (206);
        delay(100);
        mp3_set_volume (30);
        delay(1000);
      }
  }
  if ((timeM == 0) and (timeH == 19)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (207);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
                                                                  //  if ((timeM == 25) and (timeH == 20)){
  if ((timeM == 51) and (timeH == 20)){
    //SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (13);
      delay(100);
      mp3_set_volume (28);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 20)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (20);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 21)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (209);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 22)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (210);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 23) ){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (211);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  
}
void SetSensorTable(){
  
  if (ntpRegion == " Not available")
  {
    return;
  }
  if ((tempStack[timeH][6] == timeH) & (tempStack[timeH][7] == timeM))
  {
    return;
  }
  else
  {
  //Serial.println("SetSensorTable");
  tempStack [timeH][0] = am2320h;
  tempStack [timeH][1] = am2320t;
  tempStack [timeH][2] = dsTemp1;
  tempStack [timeH][3] = dsTemp2;
  tempStack [timeH][4] = iRSensorOnCounter;
  tempStack [timeH][5] = switchOnCounter;
  tempStack [timeH][6] = timeH;
  tempStack [timeH][7] = timeM;
  
  File f = SPIFFS.open(filename, "a");
  if (!f) {
    Serial.println("file open failed");
  }
  else
  {
    //Serial.println("file open");
      //f.print(currentTimeDeviceString);
      f.print(day);
      f.print(".");
      f.print(month);
      f.print(".");
      f.print(year-100);
      f.print(";");
      f.print(hour);
      f.print(":");
      f.print(minute);
      f.print(";");
      f.print(am2320h);
      f.print(";");
      f.print(am2320t);
      f.print(";");
      f.print(dsTemp1);
      f.print(";");
      f.print(dsTemp2);
      f.print(";\r");
      f.close();
  }
  }
}
