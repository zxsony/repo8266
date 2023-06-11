
void GetHTIndex (void){
//    for (int i = 0; i < 25; i++) {
//      Serial.println(AM2320Stack[i][1]);
////    AM2320Stack [i][0] = i;
////    AM2320Stack [i][1] = i;
//  }
  serverIndex = "<html><head><title>ESP8266</title><meta http-equiv='Content-Type' content='text/html; charset=utf-8' />"
  "<style>pre {-moz-tab-size: 3;}</style><style type='text/css'>TABLE {color:black;font-size:140%;font-weight:bold;} body{background-color: black;}</style></head>";
  serverIndex += "</table><table border='1' bgcolor='Gainsboro'>";

  serverIndex += "<tr><td><a href='/'>Hour</a></td><td>Hydro</td><td>Temp</td><td>T1</td><td>T2</td><td>C1</td><td>C2</td>";
//  serverIndex += "<tr><td><a href='/'>Hour</a></td><td>Hydro</td><td>Temp</td><td>T1</td><td>C1</td><td>C2</td>";

    if (0 == hour){
      serverIndex += "<tr bgcolor='DarkSeaGreen' ><td>0</td><td>";}
    else{
      serverIndex += "<tr><td>0</td><td>";}
  
  //serverIndex += "<tr><td>0</td><td>";
  serverIndex += tempStack [0][0];
  serverIndex += "</td><td>";
  serverIndex += tempStack [0][1];
  serverIndex += "</td><td>";
  serverIndex += tempStack [0][2];
  serverIndex += "</td><td>";
  serverIndex += tempStack [0][3];  
  serverIndex += "</td><td>";
  if (tempStack [0][4] > 0){serverIndex += (int)(tempStack [0][4] - tempStack [23][4]);}
    else {serverIndex += 0;}
  serverIndex += "</td><td>";
  if (tempStack [0][5] > 0){serverIndex += (int)(tempStack [0][5] - tempStack [23][5]);}
  else {serverIndex += 0;}

  for (int i = 1; i<24; i++){
    if (i == hour){
      serverIndex += "</td></tr><tr bgcolor='DarkSeaGreen' ><td>";}
    else{
      serverIndex += "</td></tr><tr><td>";}
    //serverIndex += "</td></tr><tr><td>";
    serverIndex += i;
    serverIndex += "</td><td>";
    serverIndex += tempStack [i][0];
    serverIndex += "</td><td>";
    serverIndex += tempStack [i][1];
    serverIndex += "</td><td>";
    serverIndex += tempStack [i][2];
    serverIndex += "</td><td>";
    serverIndex += tempStack [i][3];
    serverIndex += "</td><td>";
    if (tempStack [i][4] > 0){serverIndex += (int)(tempStack [i][4] - tempStack [i-1][4]);}
      else {serverIndex += 0;}
    serverIndex += "</td><td>";
    if (tempStack [i][5] > 0){serverIndex += (int)(tempStack [i][5] - tempStack [i-1][5]);}
      else {serverIndex += 0;}
    //Serial.println(AM2320Stack[i][1]);
  }
   
  serverIndex += "</td></tr></table>";
  
  serverIndex += "</form></pre></h2></html>";
  }


  
  void httpInit(void){
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
    readDeviceSettings();
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
  }
