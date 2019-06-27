void Unix_to_GMT(unsigned long epoch)
{
 // корректировка часового пояса и синхронизация
  //epoch = epoch + 3 * 3600;    
 
  second=epoch%60;
  epoch/=60; // now it is minutes
  minute=epoch%60;
  epoch/=60; // now it is hours
  hour=epoch%24;
  epoch/=24; // now it is days
  weekday=(epoch+4)%7; // day week, 0-sunday
  year=70;
  int days=0;
  while(days + ((year % 4) ? 365 : 366) <= epoch) {
     days += (year % 4) ? 365 : 366;
     year++;
  }
  epoch -= days; // now it is days in this year, starting at 0
 
  days=0;
  month=0;
  byte monthLength=0;
  for (month=0; month<12; month++) {
    if (month==1) { // february
      if (year%4) monthLength=28;
      else monthLength=29;
    }
    else monthLength = monthDays[month];
    if (epoch>=monthLength) epoch-=monthLength;
    else break;  
  }
  month++;       // jan is month 1
  day=epoch+1;  // day of month
} 

void updateCurrent (){
  currentTimeDevice = millis();
  currentSecsSince1900 = startSecsSince1900 + ((currentTimeDevice / 1000) - startTimeDevice/1000) + 3600*3;// - 3600*7 - 60*16;
  
  parseLongWord(lastSynchroDevice);
  lastSynchroDeviceString = timeString;

  parseLongWord((timeCheck + lastSynchroDevice)- currentSecsSince1900);
  countDownTimeString = timeString;
  
  parseLongWord(currentSecsSince1900);
  currentTimeDeviceString = timeString;
  
  Unix_to_GMT (currentSecsSince1900);
}
void checkLastUpdate (){
  if (currentSecsSince1900 - lastSynchroDevice > timeCheck){

  loopUDP();
  
  if (dataRecive) {
    lastSynchroDevice = startSecsSince1900 + (currentTimeDevice / 1000) + 3600*3 - startTimeDevice/1000;
    timeCheck = synCheck;

#ifdef AM2320
    AM2320PrevSet = true;
#endif    
    ds1820PrevSet = true; 
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
