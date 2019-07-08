void WIFIcheck(){  
          WiFi.disconnect();
          WIFIinit();   
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
    WiFi.begin(wifiAp[i][0], wifiAp[i][1]);
    //WiFi.begin(ssid, password);
    //Serial.println (ssid);
    //Serial.println (password);
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

void getAP () {
  if ((digitalRead(button) == HIGH) | ultrasonicEn) {

    devNumbFull = "AP_STA-" + deviceId;
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAPConfig(IPAddress(192, 168, 4, 4), IPAddress(192, 168, 4, 4), IPAddress(255, 255, 255, 0));
    WiFi.softAP(devNumbFull.c_str());
    WiFi.begin(ssid, password);
    ////    mp3_play (102);
    ////    delay(500);
    ////    mp3_set_volume (30);
    ////    delay(100);

    if (WiFi.waitForConnectResult() == WL_CONNECTED) {
      //ntpEn = 1;
      if (mp3En) {
        mp3_play (31);//19 ok boss
        delay(100);
        mp3_set_volume (30);
        delay(100);
      }
    }
  }
  else {

    //IPAddress apIP(192,168,4,1);
    devNumbFull = "AP-" + deviceId;
    WiFi.mode(WIFI_AP);       // WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(IPAddress(192, 168, 4, 4), IPAddress(192, 168, 4, 4), IPAddress(255, 255, 255, 0));
    WiFi.softAP(devNumbFull.c_str());

  }
}
