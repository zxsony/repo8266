
void updateCurrent (){
  currentTimeDevice = millis();
  currentSecsSince1900 = startSecsSince1900 + ((currentTimeDevice / 1000) - startTimeDevice/1000) + 3600*3;// - 3600*7 - 60*16;
  
  parseLongWord(lastSynchroDevice);
  lastSynchroDeviceString = timeString;

  parseLongWord((timeCheck + lastSynchroDevice)- currentSecsSince1900);
  countDownTimeString = timeString;
  
  parseLongWord(currentSecsSince1900);
  currentTimeDeviceString = timeString;
}
void checkLastUpdate (){
  if (currentSecsSince1900 - lastSynchroDevice > timeCheck){


//  parseLongWord(lastSynchroDevice);
//  Serial.println(timeString);
//  parseLongWord(currentSecsSince1900);
//  Serial.println(timeString);
  
  //Serial.println(currentSecsSince1900);
  //Serial.println(lastSynchroDevice);
  
  //Serial.println("\nSynchro. Get NTP data...");
  //dataRecive = 0;
  loopUDP();
  //sendReciveUDP();
  
  if (dataRecive) {
    lastSynchroDevice = startSecsSince1900 + (currentTimeDevice / 1000) + 3600*3 - startTimeDevice/1000;
    timeCheck = synCheck; 
  }
  else timeCheck = timeCheck + 600;
  }
}
bool parseLongWord(unsigned long data)
{
  timeString = "";
  timeString = ((data  % 86400L) / 3600);
  timeH = ((data  % 86400L) / 3600);
  timeString += (':');
  if (((data % 3600) / 60) < 10) {
    timeString += ('0');
  }
  timeString += ((data  % 3600) / 60);
  timeM = ((data  % 3600) / 60);
  timeString += (':');
  if ((data % 60) < 10) {
    timeString += ('0');
  }
  timeString += (data % 60);
  timeS = (data % 60);
  if (data == 0) return 1;  
  else return 0;
}
