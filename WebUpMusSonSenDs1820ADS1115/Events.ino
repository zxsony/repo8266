void StartSampling(){
  sampleFn = "Null";
  samplePolling = true;
  sampleLimit = 60;
  samplePage = 24;
  sampleCount = 0;
  ClearSampleStack();
}

void ClearSampleStack(){
  for(int w = 0; w < sampleLimit; w++){

    sampleDataStack[w][0] = 0;
    sampleDataStack[w][1] = 0;
    sampleDataStack[w][2] = 0;
    sampleDataStack[w][3] = 0;
    sampleDataStack[w][4] = 0;
    sampleDataStack[w][5] = 0;
    sampleDataStack[w][6] = 0;
    sampleDataStack[w][7] = 0;    
    sampleDateTimeStack[w][0] = 0;
    sampleDateTimeStack[w][1] = 0;
    sampleDateTimeStack[w][2] = 0;
    sampleDateTimeStack[w][3] = 0;
    sampleDateTimeStack[w][4] = 0;    
  }
}

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
    ClearSampleStack();
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
