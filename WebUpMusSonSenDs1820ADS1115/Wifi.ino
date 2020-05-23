void WIFIcheck(){  
          WiFi.disconnect();
          WIFIinit2();   
}

void WIFIinit2() {
  devNumbFull = "STA-" + deviceId;
  WiFi.persistent(false); 
  WiFi.mode(WIFI_STA);
//  WiFi.softAPConfig(IPAddress(192, 168, 4, 4), IPAddress(192, 168, 4, 4), IPAddress(255, 255, 255, 0));
//  WiFi.softAP(devNumbFull.c_str());

  IPAddress ip;
  IPAddress mask;
  IPAddress gate;
  
  ip.fromString(FS_ReadSetting("[NETWORK]", "ip"));
  mask.fromString(FS_ReadSetting("[NETWORK]", "mask"));
  gate.fromString(FS_ReadSetting("[NETWORK]", "gate"));
  WiFi.config(ip, gate, mask);
  
  bool endlist = true;
  int count = 0;
  
  while (endlist){
    byte tries = 11;
    count ++;  
    ssid = FS_ReadSetting("[WIFIAP]", "ssid" + String (count));
    pass = FS_ReadSetting("[WIFIAP]", "pass" + String (count)); 
//    Serial.println(ssid);
//    Serial.println(pass);
    if (ssid == "" or pass == "") break;
    WiFi.begin(ssid, pass);
    
    while (--tries && WiFi.status() != WL_CONNECTED)
      {
      watchdogCount = 0;
      digitalWrite(ledPinBR2, HIGH);
      delay(300);
      digitalWrite(ledPinBR2, LOW);
      delay(700);
      }
      
    if (WiFi.status() != WL_CONNECTED)
    {
      digitalWrite(ledPinR, HIGH);
      delay(1000);
      digitalWrite(ledPinR, LOW);
      //WiFi.disconnect();
    }
    else 
      {
        // Иначе удалось подключиться отправляем сообщение
        // о подключении и выводим адрес IP
        //Serial.println("");
        digitalWrite(ledPinGR1, HIGH);
        delay(1000);
        digitalWrite(ledPinGR1, LOW);
#ifdef debugwifi        
        Serial.println("WiFi connected");
        Serial.print("IP SSID: ");
        Serial.println(WiFi.SSID());
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
#endif
        return;
      }
    }
    ssid = "Not setting";
    devNumbFull = "AP-" + deviceId;
    WiFi.mode(WIFI_AP);       // WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(IPAddress(192, 168, 4, 4), IPAddress(192, 168, 4, 4), IPAddress(255, 255, 255, 0));
    WiFi.softAP(devNumbFull.c_str());
    digitalWrite(ledPinR, HIGH);
    delay(1000);
    digitalWrite(ledPinR, LOW);
    delay(1000);
    digitalWrite(ledPinR, HIGH);
    delay(1000);
    digitalWrite(ledPinR, LOW);
    delay(1000);
    digitalWrite(ledPinR, HIGH);
    delay(1000);
    digitalWrite(ledPinR, LOW);
    delay(1000);
}


void WIFIinit() {
  // Попытка подключения к точке доступа
  //delay(10000);
  for (int i = 0; i < wifiApCount; i++) {
    //Serial.println (wifiAp[i][0]);
    //Serial.println (wifiAp[i][1]);

    WiFi.mode(WIFI_AP_STA);
    WiFi.softAPConfig(IPAddress(192, 168, 4, 4), IPAddress(192, 168, 4, 4), IPAddress(255, 255, 255, 0));
    WiFi.softAP(devNumbFull.c_str());
    byte tries = 11;
    WiFi.begin(wifiAp[i][0].c_str(), wifiAp[i][1].c_str());
    //WiFi.begin(ssid, password);
    //Serial.println (wifiAp[i][0].c_str());
    //Serial.println (wifiAp[i][1].c_str());
    //delay(1000000);
    // Делаем проверку подключения до тех пор пока счетчик tries
    // не станет равен нулю или не получим подключение
    while (--tries && WiFi.status() != WL_CONNECTED)
    {
      watchdogCount = 0;
      //Serial.print(".");

      digitalWrite(ledPinBR2, HIGH);
      delay(300);
      digitalWrite(ledPinBR2, LOW);
      delay(700);
    }
    if (WiFi.status() != WL_CONNECTED)
    {
      //Serial.println("");
      //Serial.println("WiFi " + wifiAp[i][0] + " down");
      digitalWrite(ledPinGR1, HIGH);
      delay(1000);
      digitalWrite(ledPinGR1, LOW);

      WiFi.disconnect();
    }
    else {
      // Иначе удалось подключиться отправляем сообщение
      // о подключении и выводим адрес IP
      //Serial.println("");
      //Serial.println("WiFi connected");
      //Serial.println("IP address: ");
      //Serial.println(WiFi.localIP());
      return;
    }
  }
}

//void getAP () {
//  if ((digitalRead(button) == HIGH) | ultrasonicEn) {
//
//    devNumbFull = "AP_STA-" + deviceId;
//    WiFi.mode(WIFI_AP_STA);
//    WiFi.softAPConfig(IPAddress(192, 168, 4, 4), IPAddress(192, 168, 4, 4), IPAddress(255, 255, 255, 0));
//    WiFi.softAP(devNumbFull.c_str());
//    WiFi.begin(ssid, password);
//    ////    mp3_play (102);
//    ////    delay(500);
//    ////    mp3_set_volume (30);
//    ////    delay(100);
//
//    if (WiFi.waitForConnectResult() == WL_CONNECTED) {
//      //ntpEn = 1;
//      if (mp3En) {
//        mp3_play (31);//19 ok boss
//        delay(100);
//        mp3_set_volume (30);
//        delay(100);
//      }
//    }
//  }
//  else {
//
//    //IPAddress apIP(192,168,4,1);
//    devNumbFull = "AP-" + deviceId;
//    WiFi.mode(WIFI_AP);       // WiFi.mode(WIFI_AP);
//    WiFi.softAPConfig(IPAddress(192, 168, 4, 4), IPAddress(192, 168, 4, 4), IPAddress(255, 255, 255, 0));
//    WiFi.softAP(devNumbFull.c_str());
//
//  }
//}
