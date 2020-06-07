void setup(void) {
  ////////////////////
  startMillisDevice = millis();
  secondTick.attach(1, ISRwatchdog);
  synCheck = 3600;//3600
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

  readsettings();

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
  server.on("/info", HTTP_GET, []() {
    
  FSInfo fs_info;
  SPIFFS.info(fs_info);
  
//    if (securityEn) {
//      securityEn = false;
//    }
//    else {
//      securityEn = true;
//    }

    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    serverIndex = "";
    serverIndex += "mac: " + String(WiFi.macAddress()) + "<BR>";
    //serverIndex += "vcc: " + String(ESP.getVcc()/1024.00f) + "<BR>";
    serverIndex += "freeHeap: " + String(ESP.getFreeHeap()) + "<BR>";
    serverIndex += "chipId: " + String(ESP.getChipId()) + "<BR>";
    serverIndex += "sdkVersion: " + String(ESP.getSdkVersion()) + "<BR>";
    serverIndex += "coreVersion: " + ESP.getCoreVersion() + "<BR>";
    serverIndex += "cpuFreqMHz: " + String(ESP.getCpuFreqMHz()) + " MHz<BR>";

    serverIndex += "flashRealSize: " + String(ESP.getFlashChipRealSize()) + "<BR>";
    serverIndex += "flashChipId: " + String(ESP.getFlashChipId()) + "<BR>";
    serverIndex += "flashChipSpeed: " + String(int(ESP.getFlashChipSpeed() * 0.000001)) + " MHz<BR>";

    serverIndex += "sketchSize: " + String(ESP.getSketchSize()) + "<BR>";
    serverIndex += "sketchMD5: " + ESP.getSketchMD5() + "<BR>";
    serverIndex += "freeSketchSpace: " + String(ESP.getFreeSketchSpace()) + "<BR>";

    serverIndex += "resetReason: " + ESP.getResetReason() + "<BR>";
    serverIndex += "resetInfo: " + ESP.getResetInfo() + "<BR>";

    serverIndex += "CPUCycleCount: " + String(ESP.getCycleCount()) + "<BR>";

    serverIndex += "bootVersion: " + String(ESP.getBootVersion()) + "<BR>";
    serverIndex += "bootMode: " + String(ESP.getBootMode()) + "<BR>";
    serverIndex += "Security: " + String(securityEn) + "<BR>";
    serverIndex += "samplePolling: " + String(samplePolling) + "<BR>";

    serverIndex += "fs_info.totalBytes: " + String(fs_info.totalBytes) + "<BR>";
    serverIndex += "fs_info.freeBytes: " + String(fs_info.totalBytes - fs_info.usedBytes) + "<BR>";
    serverIndex += "fs_info.usedBytes: " + String(fs_info.usedBytes) + "<BR>";

//    for (int q = 0; q < 3; q++){
//      serverIndex += "0: " + String(sampleDataStack [q][0]) + "<BR>";
//      serverIndex += "2: " + (String)sampleDataStack [q][2] + "<BR>";
//      //serverIndex += "8: " + (String)sampleDataStack [q][8] + "<BR>";
//    }

    server.send(200, "text/html", serverIndex);

  });
  ///////////////////////////////////////////////////////////
  server.on("/rs", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    readsettings();
  server.send(200, "text/html", "Read settings.<meta http-equiv='refresh' content='5;URL=/'>");
  });
  
  server.on("/t1", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");

  StartSampling();
    //timeCheck = timeCheck - 3600000;
    //startMillisDevice += 3600000;
    //FS_FileWrite("/t1.txt", "tempStack6=" + (String)tempStack[timeH][6] + ";" + "tempStack7=" + (String)tempStack[timeH][7] + ";" + "timeH=" + timeH + ";" + "timeM=" + timeM); //tempStack[timeH][6] == timeH) & (tempStack[timeH][7] == timeM
  server.send(200, "text/html", "Start polling. page limit 24.<meta http-equiv='refresh' content='5;URL=/'>");
  //delay (500);<meta http-equiv='refresh' content='30;URL=/'>
  });
    server.on("/t2", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    samplePolling = !samplePolling;
    //timeCheck = timeCheck - 600;
    //startMillisDevice += 600000;
    server.send(200, "text/html", "Stop/Start polling.<meta http-equiv='refresh' content='1;URL=/'>");
  });
    server.on("/t3", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    samplePolling = true;
    sampleCount = sampleLimit - 1;
    samplePage = 1;
    //timeCheck = timeCheck - 60;
    //ntpSyn = false;
    //startMillisDevice += 60000;
    server.send(200, "text/html", "Stop/Start polling. Write File.<meta http-equiv='refresh' content='1;URL=/'>");
  });
 ///////////////////////////////////////////////////////////// 
  server.on("/data.xml", HTTP_GET, []() {
    server.send(200, "text/xml", xmlData);
  });
  server.on("/ht", HTTP_GET, []() {
    //ledColoure = "red";
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    GetHTIndex();
    server.send(200, "text/html", serverIndex);
    //ledCurrent = ledPinR;
    ////      mp3_stop ();
    ////      delay(100);
  });
  server.on("/greenled", HTTP_GET, []() {
    ledColoure = "green";
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    GetServerIndex();
    server.send(200, "text/html", serverIndex);
    ledCurrent = ledPinGR1;
    ////      mp3_play (1);
    ////      delay(100);
    ////      mp3_set_volume (24);
    ////      delay(100);
  });
  server.on("/update2", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "text/html", "<form method='POST' action='/update' enctype='multipart/form-data'><input type='file' name='update'><input type='submit' value='Update'>");
  });

  server.on("/u", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "text/html", "<html><head><title>ESP8266</title><meta http-equiv='Content-Type' content='text/html; charset=utf-8' /><script>alert( 'Вы запустили процедуру самоуничтожения!))' );document.location.href='/';</script>");
    //lastSynchroDevice = startSecsSince1900 + (currentMilisDevice / 1000) + 3600 * 3 - startMillisDevice / 1000;
    timeCheck = synCheck;
  });

  server.on("/", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    
  #ifdef ADS1115
    ADC1115Read ();
  #endif
  
  if (am2320En) AM23020Read ();
  
    server.send(200, "text/html", serverIndex);
  });

  server.on("/index.html", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "text/html", serverIndex);
  });

  server.on("/update", HTTP_POST, []() {
    server.sendHeader("Connection", "close");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "text/html", "Update complete! Restarting device 30 sec...<meta http-equiv='refresh' content='30;URL=/'>");
    FS_FileWrite("/sl.txt", "\"UpdateDevice\";\"" + (String)ver + "\";\"" + WiFi.SSID() + "\"");
    //FS_FileWrite("/sysLog.txt", "UpdateDevice;" + (String)ver + ";" + (String)ssid);
    if (mp3En) {
      mp3_play (18);
      delay(50);
      mp3_set_volume (30);
      delay(10);
    }
    delay (500);
    ////<meta http-equiv="refresh" content="10;URL=http://php-mysql-video.ru">
    ////server.send(200, "text/plain", (Update.hasError())?"Update Fail (":"Update complete! Restarting device...");
    ESP.restart();
  }, []() {


    digitalWrite(ledPinR, HIGH);
    HTTPUpload& upload = server.upload();
    String a = upload.filename.c_str();
    if (a.indexOf("ino.bin") > 0) {
      //Serial.printf("Update: %s\n", upload.filename.c_str());


      if (upload.status == UPLOAD_FILE_START) {
        ////Serial.setDebugOutput(true);
        ////WiFiUDP::stopAll();
        ////Serial.printf("Update: %s\n", upload.filename.c_str());
        uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
        if (!Update.begin(maxSketchSpace)) { //start with max available size
          //Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_WRITE) {
        if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
          //Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_END) {
        digitalWrite(ledPinR, LOW);
        digitalWrite(ledPinBR2, HIGH);
        delay (1500);
        digitalWrite(ledPinBR2, LOW);
        if (Update.end(true)) { //true to set the size to the current progress
          for (int i = 1; i < 4; i++) {
            digitalWrite(ledPinGR1, HIGH);
            delay (500);
            digitalWrite(ledPinGR1, LOW);
            delay (500);
          }

          //Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
        } else {
          for (int i = 1; i < 4; i++) {
            digitalWrite(ledPinR, HIGH);
            delay (500);
            digitalWrite(ledPinR, LOW);
            delay (500);
          }
          //Update.printError(Serial);
        }
        //Serial.setDebugOutput(false);
      }
    }

    yield();
    digitalWrite(ledPinR, LOW);
  });
  server.begin();
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


}
void readsettings(void) {
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
