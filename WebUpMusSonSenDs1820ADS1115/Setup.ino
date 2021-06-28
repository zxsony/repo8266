void setup(void) {
  ////////////////////
  startMillisDevice = millis();
  secondTick.attach(1, ISRwatchdog);
  
  ntpSyn = false;
  firstSynNTP = false;
  am2320storagecounter = 0;
  am2320averagecounter = 0;
  am2320averagecounterfull = false;
  StartSampling();

  if (am2320En) AM2320PrevSet = false;

  ds1820PrevSet = false;
  timeCheck = synCheck;
  soundDelay = startMillisDevice;
  WiFi.macAddress(mac);
  byte i;
  Serial.begin (9600);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinGR1, OUTPUT);
  pinMode(ledPinBR2, OUTPUT);
  pinMode(ledPinYR3, OUTPUT);

  //OneWire  ds(0);
  FS_init();    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //wifiApCount = FS_ReadWiFiSetting();
  //FS_ReadAM2320Setting();

  readDeviceSettings();
  if (synCheck == 0) synCheck = 3600;//3600
  timeCheck = synCheck;
#ifdef DEBUGFS
Serial.println ("\nDEBUGFS\n");
//for (int i = 1; i < 4; i++){
//  Serial.println(FS_ReadSetting("[DS1820]", "name" + String (i)));
//  Serial.println(FS_ReadSetting("[DS1820]", "corr" + String (i)));
//}

#endif
  
#ifdef DEBUG  
//  Serial.println(wifiApCount);
//  for (int i = 0; i < wifiApCount; i++){
//    Serial.println (wifiAp[i][0]);
//    Serial.println (wifiAp[i][1]);
//  }
//  Serial.println ("end");
#endif

  ds.begin(ds1820pin);
  Wire.begin(am2320SDApin, am2320SCLpin);
  Wire.beginTransmission(AM2320_i2C_ADDRESS >> 1);  
  Wire.endTransmission(1);
#ifdef ADS1115
  ads1115.begin();
#endif

  if (!ultrasonicEn) {
    pinMode(button, INPUT);
  }
#ifdef IRSensorEn
  pinMode(IRSensorIn, INPUT);
  LightActivityDelay = 0;
  LightActivityState1 = true;
  LightActivityState2 = true;
  LightActivityState3 = true;
#endif
  if (tempEn) {
    DsSearch ();
    //  DallSearch ();
  }

  Serial.println();
  if (mp3En) {

    mp3_set_serial (Serial);  //set Serial for DFPlayer-mini mp3 module
    delay(100);
    mp3_play (32);//16
    delay(100);
    mp3_set_volume (30);
    delay(2500);
  }

  ////////////////////
  //  Serial.begin(115200);
  //  Serial.println();
  //  Serial.println("Booting Sketch...");

//getAP ();

WIFIinit2();   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef debug
  Serial.print("LocalIP: ");
  Serial.println(WiFi.localIP());
  Serial.print("APIP: ");
  Serial.println(WiFi.softAPIP());

  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  for ( i = 0; i < 6; i++) {
    //Serial.print(mac[i], HEX);

    tempStr = String(mac[i], HEX);
    Serial.print(tempStr);
    devNumbFull += tempStr;
    Serial.print(" ");
  }
  Serial.println("");
#endif
  //WiFi.softAP(devNumbFull.c_str());

  if (tempEn) {
#ifdef debug
    DsAddrPrint();
#endif
  }



  if (ntpEn) {
    Udp.begin(localPort);
    ////Serial.println("\nGet NTP data...");
    dataRecive = 0;
if (WiFi.status() == WL_CONNECTED) {
    loopUDP();    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

    ////printEpoch(epochStamp);
    if (firstSynNTP){
      lastSynchroDevice = startSecsSince1900 + 3600*3;
    }
    else{
      lastSynchroDevice = startSecsSince1900;
    }
    //lastSynchroDevice = startSecsSince1900 + (currentMilisDevice / 1000) + 3600 * 3 - startMillisDevice / 1000;
  }
  updateCurrentDateTime ();
  FS_FileWrite("/sl.txt", "\"StartDevice\";\"" + (String)ver + "\";\"" + WiFi.SSID() + "\"");
  lhour = hour;
  lminute = minute;
  tikminute = minute;
  ////MDNS.begin(host);
  ////MDNS.addService("http", "tcp", 80);
  
  dsDelay = 0;
  AM2320Delay = 0;
  ADC1115Delay = millis();
  
  if (am2320En) am2320Request = true;

#ifdef IRSensorEn
  IRSensorEnVar = true;
#endif

tempStack[hour][6] = hour;
tempStack[hour][7] = minute;
  ////MDNS.addService("http", "tcp", 80);

httpInit(); ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
void readDeviceSettings(void) {
    deviceId = FS_ReadSetting("[MAIN]", "deviceId");
    securityEn = bool ((FS_ReadSetting("[MAIN]", "securityEn")).toInt());
    tempEn = bool ((FS_ReadSetting("[MAIN]", "tempEn")).toInt());
    am2320En = bool ((FS_ReadSetting("[MAIN]", "am2320En")).toInt());
    analogSensorEn = bool ((FS_ReadSetting("[MAIN]", "analogSensorEn")).toInt());
    mp3En = bool ((FS_ReadSetting("[MAIN]", "mp3En")).toInt());
    ultrasonicEn = bool ((FS_ReadSetting("[MAIN]", "ultrasonicEn")).toInt());
    ntpEn = bool ((FS_ReadSetting("[MAIN]", "ntpEn")).toInt());
    ipset = bool ((FS_ReadSetting("[NETWORK]", "ipset")).toInt());
    ledblink = bool ((FS_ReadSetting("[MAIN]", "ledblink")).toInt());
    synCheck = (FS_ReadSetting("[MAIN]", "syncheck")).toInt();
    
    ds1820pin = (FS_ReadSetting("[INTERFACE]", "oneWire")).toInt();
    am2320SDApin = (FS_ReadSetting("[INTERFACE]", "i2cSDA")).toInt();
    am2320SCLpin = (FS_ReadSetting("[INTERFACE]", "i2cSCL")).toInt();
    
    fillds1820();
    
    nameam2320t = FS_ReadSetting("[AM2320]", "namet");
    corram2320t = (FS_ReadSetting("[AM2320]", "corrt")).toFloat();
    nameam2320h = FS_ReadSetting("[AM2320]", "nameh");
    corram2320h = (FS_ReadSetting("[AM2320]", "corrh")).toFloat();
    am2320storage = (FS_ReadSetting("[AM2320]", "storage")).toInt();
    am2320average = (FS_ReadSetting("[AM2320]", "average")).toInt();
    am2320debug = bool ((FS_ReadSetting("[AM2320]", "debug")).toInt());
    am2320requery = (FS_ReadSetting("[AM2320]", "requery")).toInt();
//    String stry = "1";
//    Serial.println (bool ((stry).toInt()));
}
void fillds1820(void) {
    for (int i = 0; i < 10; i++){
    String tds1820name = FS_ReadSetting("[DS1820]", "name" + String (i));
    float tds1820corr = (FS_ReadSetting("[DS1820]", "corr" + String (i))).toFloat();
    if (tds1820name != ""){
      ds1820name[i] = tds1820name;
      ds1820corr[i] = tds1820corr;
    }
    
  }
}
