
void CheckTimeEvents(){
  //if (mp3En){
  
  if ((minute == 0) and (hour == 0)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (212);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 1)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (201);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 2)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (202);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 3)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (203);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 4)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (204);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 5)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (205);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 6)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (206);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 7)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (207);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 30) and (hour == 7)){//будильник
  if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
    soundDelay = millis();
    mp3_play (3);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
}
  if ((minute == 0) and (hour == 8)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (20);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 9)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (209);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 10)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
    soundDelay = millis();
    mp3_play (210);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
    }
  }
  if ((minute == 0) and (hour == 11)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (211);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 12)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (212);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }  
  if ((minute == 0) and (hour == 13)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (201);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 14)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (202);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 15)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (203);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 16)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (204);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 17)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (205);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 18)){
    SetSensorTable();
      if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
        soundDelay = millis();
        mp3_play (206);
        delay(100);
        mp3_set_volume (30);
        delay(1000);
      }
  }
  if ((minute == 0) and (hour == 19)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (207);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
                                                                  //  if ((minute == 25) and (hour == 20)){
  if ((minute == 10) and (hour == 13)){
    //SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (13);
      delay(100);
      mp3_set_volume (28);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 20)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (20);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 21)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (209);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 22)){
    SetSensorTable();
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (210);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((minute == 0) and (hour == 23) ){
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
//  Serial.println(tempStack[hour][6]);
//  Serial.println(tempStack[minute][7]);
//  Serial.println(hour);
//  Serial.println(minute);
//  Serial.println("");
//  delay(5000);
  //if (ntpRegion == " Not available")
  if (!ntpSyn)
  {
    return;
  }
  if ((lhour == hour) & (lminute == minute))
  {
    return;
  }
  else
  {
  //Serial.println("SetSensorTable");
  tempStack [hour][0] = am2320h;
  tempStack [hour][1] = am2320t;
  tempStack [hour][2] = dsTemp1;
  tempStack [hour][3] = dsTemp2;
  tempStack [hour][4] = iRSensorOnCounter;
  tempStack [hour][5] = switchOnCounter;
  tempStack [hour][6] = hour;
  tempStack [hour][7] = minute;
  lhour = hour;
  lminute = minute;
  
//  File f = SPIFFS.open(filename, "a");
//  if (!f) {
//    Serial.println("file open failed");
//  }
//  else
//  {
//    //Serial.println("file open");
//      //f.print(currentTimeDeviceString);
//      f.print(day);
//      f.print(".");
//      f.print(month);
//      f.print(".");
//      f.print(year-100);
//      f.print(";");
//      f.print(hour);
//      f.print(":");
//      f.print(minute);
//      f.print(";");
//      f.print(am2320h);
//      f.print(";");
//      f.print(am2320t);
//      f.print(";");
//      f.print(dsTemp1);
//      f.print(";");
//      f.print(dsTemp2);
//      f.print(";\r");
//      f.close();
//  }
String tempString;
bool writeState = false;
  #ifdef AM2320
    tempString += (String)am2320h + ";";
    tempString += (String)am2320t;
    writeState = true;
    if (TempEn) tempString += ";";
  #endif
if (TempEn){
  tempString += (String)dsTemp1 + ";";
  tempString += (String)dsTemp2;
  writeState = true;
}
    if (writeState) FS_FileWrite("/thd.txt", tempString);
  }
}
