void WIFIcheck() {
  WiFi.disconnect();
  WIFIinit2();
}

void WIFIinit2() {
  devNumbFull = "STA-" + deviceId;
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  //  WiFi.softAPConfig(IPAddress(192, 168, 4, 4), IPAddress(192, 168, 4, 4), IPAddress(255, 255, 255, 0));
  //  WiFi.softAP(devNumbFull.c_str());
  wifiScanCount = WiFi.scanNetworks();
  IPAddress ip;
  IPAddress mask;
  IPAddress gate;

  ip.fromString(FS_ReadSetting("[NETWORK]", "ip"));
  mask.fromString(FS_ReadSetting("[NETWORK]", "mask"));
  gate.fromString(FS_ReadSetting("[NETWORK]", "gate"));

  if (ipset) WiFi.config(ip, gate, mask);
  WiFi.hostname(deviceId);
  bool endlist = true;
  int count = 0;

  while (endlist) {
    byte tries = 11;
    count ++;
    ssid = FS_ReadSetting("[WIFIAP]", "ssid" + String (count));
    pass = FS_ReadSetting("[WIFIAP]", "pass" + String (count));
    //    Serial.println(ssid);
    //    Serial.println(pass);
    //    Serial.println(count);
    //Serial.println(bool ((FS_ReadSetting("[MAIN]", "test")).toInt()));
    if (count > 9) break;
    if (ssid == "" or pass == "") continue;
    //Serial.println(WIFIChk(ssid));
    if (!WIFIChk(ssid)) continue;
    Serial.println ("WiFi.begin");
    WiFi.begin(ssid, pass);
    Serial.println(ssid);
    Serial.println(pass);

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
      Serial.println("WiFi router connect");
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
      Serial.print("IP gateway: ");
      Serial.println(WiFi.gatewayIP().toString());

      digitalWrite(ledPinGR1, HIGH);
      delay(1000);
      digitalWrite(ledPinGR1, LOW);
#ifdef debugwifi
      //        Serial.println("WiFi connected");
      Serial.print("WIFI SSID: ");
      Serial.println(WiFi.SSID());
      //        Serial.print("IP address: ");
      //        Serial.println(WiFi.localIP());
#endif
      return;
    }
  }
  return;
  WIFIinitLocalNtp();

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

void WIFIinitLocalNtp() {
  WiFi.disconnect();
  byte tries = 11;
  ssid = FS_ReadSetting("[WIFIAP]", "ssidLNtp");
  pass = FS_ReadSetting("[WIFIAP]", "passLNtp");
  Serial.println("Local Ntp");
  Serial.println(ssid);
  Serial.println(pass);
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
    Serial.println("Local NTP not connected");
    digitalWrite(ledPinR, HIGH);
    delay(1000);
    digitalWrite(ledPinR, LOW);
  }
  else
  {
    Serial.println("Local NTP connected");
    Serial.println("Local NTP IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("Local NTP IP gateway: ");
    Serial.println(WiFi.gatewayIP().toString());

    digitalWrite(ledPinGR1, HIGH);
    delay(1000);
    digitalWrite(ledPinGR1, LOW);


    IPAddress ipgateway;
    ipgateway = WiFi.gatewayIP();
    sendReciveUDPlocal(ipgateway);
    if (dataRecive) {
      Serial.println("Local NTP data recive");
      ntpRegion = "Gateway";
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

bool WIFIChk(String testSSID) {

  if (wifiScanCount == 0) {
    Serial.println(testSSID + " networks no found");
    return false;
  } else {
    //    Serial.print(wifiScanCount);
    //    Serial.println(" networks found");
    for (int i = 0; i < wifiScanCount; ++i) {
      // Print SSID and RSSI for each network found
      //      Serial.print(i + 1);
      //      Serial.print(": ");
      //      Serial.print(WiFi.SSID(i));
      //      Serial.print(" (");
      //      Serial.print(WiFi.RSSI(i));
      //      Serial.print(")");
      //      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");

      //Serial.println(testSSID);
      //Serial.println(WiFi.SSID(i));
      //
      //Serial.println(WiFi.SSID(i) == testSSID);
      if (WiFi.SSID(i) == testSSID) return true;
      delay(10);
    }
    return false;
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
