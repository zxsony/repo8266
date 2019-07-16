
void CheckTimeEvent (void) {
  if ((tikminute == minute))
  {
    return;
  }
  else {
    if (samplePolling) sampleWrite();
    tikminute = minute;
    //Serial.println("tik");
  }
}
void sampleWrite() {
  sampleDataStack [sampleCount][0] = am2320h;
  sampleDataStack [sampleCount][1] = am2320t;
  sampleDataStack [sampleCount][2] = dsTemp1;
  sampleDataStack [sampleCount][3] = dsTemp2;
  sampleDataStack [sampleCount][4] = iRSensorOnCounter;
  sampleDataStack [sampleCount][5] = switchOnCounter;
  sampleDataStack [sampleCount][6] = ledSensorValue;
  sampleDateTimeStack [sampleCount][0] = day;
  sampleDateTimeStack [sampleCount][1] = month;
  sampleDateTimeStack [sampleCount][2] = hour;
  sampleDateTimeStack [sampleCount][3] = minute;
  //sampleDataStack [sampleCount][7] = hour;
  //sampleDataStack [sampleCount][8] = minute;
  sampleCount++;
  if (sampleCount == sampleLimit) {
    String tempfn = "/";
    if (sampleDateTimeStack [0][0] < 10) tempfn += "0";
    tempfn += (String)sampleDateTimeStack [0][0];
    if (sampleDateTimeStack [0][1] < 10) tempfn += "0";
    tempfn += (String)sampleDateTimeStack [0][1] + "-";
    if (sampleDateTimeStack [0][2] < 10) tempfn += "0";
    tempfn += (String)sampleDateTimeStack [0][2];
    if (sampleDateTimeStack [0][3] < 10) tempfn += "0"; 
    tempfn += (String)sampleDateTimeStack [0][3] + "-" + (String)samplePage + ".txt";
    if (sampleFn == "Null") sampleFn = tempfn;
    FS_FileDimWrite(sampleFn, "test");
    //FS_FileDimWrite(tempfn, "Test");
    sampleCount = 0;
    samplePage--;
    if (samplePage == 0) {
      sampleFn = "Null";
      samplePolling = false;
    }
  }
}
void startSamplePolling(){
  
}
