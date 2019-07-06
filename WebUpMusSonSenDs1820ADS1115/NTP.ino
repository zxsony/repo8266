

unsigned long sendNTPpacket(IPAddress& address) {
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  packetBuffer[0] = 0b11100011;
  packetBuffer[1] = 0;
  packetBuffer[2] = 6;
  packetBuffer[3] = 0xEC;
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;
  Udp.beginPacket(address, 123);
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

void sendReciveUDP(IPAddress& address) {
  sendNTPpacket(address);
  delay(300);
  digitalWrite(ledPinBR2, HIGH);
  delay(300); // wait to see if a reply is available
  digitalWrite(ledPinBR2, LOW);
  delay(300);
  //dataRecive = 0;
  if (Udp.parsePacket()) {
    //Serial.println("packet received");
    Udp.read(packetBuffer, NTP_PACKET_SIZE);

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);

    //if (startSecsSince1900 == 0) startTimeDevice = millis();
    secsSince1900 = highWord << 16 | lowWord;
    const unsigned long seventyYears = 2208988800UL;
    unsigned long epoch = secsSince1900 - seventyYears;
    if (startSecsSince1900 == 0) startSecsSince1900 = epoch;
    epochStamp = epoch;
    dataRecive = 1;
    digitalWrite(ledPinGR1, HIGH);
    delay(300);
    digitalWrite(ledPinGR1, LOW);
    return;
  }
  digitalWrite(ledPinR, HIGH);
  delay(300);
  digitalWrite(ledPinR, LOW);
  dataRecive = 0;
}

void loopUDP() {
  byte ipData [3][4] = {{89, 109, 251, 21}, {216, 229, 0, 179}, {129, 6, 15, 30}};//ntp1.vniiftri.ru, Moscow | Lincoln, Nebraska | NIST, Gaithersburg, Maryland
  //byte ipData [3][4] = {{198, 111, 152, 100}, {216, 229, 0, 179}, {129, 6, 15, 30}};//Carson City, Michigan | Lincoln, Nebraska | NIST, Gaithersburg, Maryland
  dataRecive = 0;
  for (int ip = 0; ip < 3; ip++) {
    for (int i = 0; i < 10; i++) {
      if (!dataRecive) {
        IPAddress timeServer(ipData[ip]);
        sendReciveUDP(timeServer);
        if (!dataRecive) {
          //          Serial.println(timeServer.toString());
          //          Serial.println("NTP data not available...\n");
          ntpRegion = " Not available";
          WiFi.disconnect();
          WIFIinit();
        }
        else {
          ntpSyn = true;
          //          Serial.println(timeServer.toString());
          //          Serial.println("NTP data available...\n");
          switch (ip) {
            case 0:
              ntpRegion = " ntp1.vniiftri.ru, Moscow ";
              ntpRegion += i + 1;
              break;
            case 1:
              ntpRegion = " Lincoln, Nebraska " + i;
              ntpRegion += i + 1;
              break;
            case 2:
              ntpRegion = " NIST, Gaithersburg, Maryland ";
              ntpRegion += i + 1;
              break;
          }
          break;
        }
      }
    }
  }
}
