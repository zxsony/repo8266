
void GetServerIndex (void){
  serverIndex = "<!DOCTYPE html><html><head><title>ESP8266</title><meta http-equiv='Content-Type' content='text/html; charset=utf-8' >"
  "<meta http-equiv='Refresh' content='10' >"
  
  #ifdef board1
  "<link href='data:image/x-icon;base64,AAABAAEAEBAQAAAAAAAoAQAAFgAAACgAAAAQAAAAIAAAAAEABAAAAAAAgAAAAAAAAAAAAAAAEAAA"
  "AAAAAAAAAAAA/wAAAP///wAf/2AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
  "AAAAAAAAAAAAAAAAAAAAAAAAAAABEREREREREAIiESIhEhEQAhEhIREhIRACESEiISEhEAIRISER"
  "IRIQAiIRIiEhEhABEREREREREAMzMzMzMzMwAwADMAAzADADMzAwMzAzMAMwAzAAMDMwAwMzMDMw"
  "MzADMAAwADMAMAMzMzMzMzMwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
  "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA' rel='icon' type='image/x-icon' />"
  #endif

  #ifdef board2
  "<link href='data:image/x-icon;base64,AAABAAEAEBAQAAAAAAAoAQAAFgAAACgAAAAQAAAAIAAAAAEABAAAAAAAgAAAAAAAAAAAAAAAEAAA"
  "AAAAAAAAAAAA/wAAAP///wBr//8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
  "AAAAAAAAAAAAAAAAAAAAAAAAAAABEREREREREAIiESIhEhEQAhEhIREhIRACESEiISEhEAIRISER"
  "IRIQAiIRIiEhEhABEREREREREAMzMzMzMzMwAzAzAAMDMDADMDMDMwADMAMwMwADAzAwAzAzAzMD"
  "MDADAAMAAwADMAMzMzMzMzMwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
  "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA' rel='icon' type='image/x-icon' />"
  #endif

  #ifdef board4
  "<link href='data:image/x-icon;base64,AAABAAEAEBAQAAAAAAAoAQAAFgAAACgAAAAQAAAAIAAAAAEABAAAAAAAgAAAAAAAAAAAAAAAEAAA"
  "AAAAAAAAAAAA/wAAAP///wBr//8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
  "AAAAAAAAAAAAAAAAAAAAAAAAAAABEREREREREAIiESIhEhEQAhEhIREhIRACESEiISEhEAIRISER"
  "IRIQAiIRIiEhEhABEREREREREAMzMzMzMzMwAzAzAAMDMDADMDMDMwADMAMwMwADAzAwAzAzAzMD"
  "MDADAAMAAwADMAMzMzMzMzMwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
  "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA' rel='icon' type='image/x-icon' />"
  #endif
  
  #ifdef board6
  "<link href='data:image/x-icon;base64,AAABAAEAEBAQAAAAAAAoAQAAFgAAACgAAAAQAAAAIAAAAAEABAAAAAAAgAAAAAAAAAAAAAAAEAAA"
  "AAAAAAAAAAAA/wAAAP///wAAAP8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
  "AAAAAAAAAAAAAAAAAAAAAAAAAAABEREREREREAIiESIhEhEQAhEhIREhIRACESEiISEhEAIRISER"
  "IRIQAiIRIiEhEhABEREREREREAMzMzMzMzMwAzIjIjIiMzADMiMiMiMzMAMyIyIiIjMwAzIjIjMi"
  "MzADMiMiIiIzMAMzMzMzMzMwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
  "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA' rel='icon' type='image/x-icon' />"
  #endif
  
  "<style>pre {-moz-tab-size: 3;}</style><style>TABLE {color:black;font-size:250%;font-weight:bold;} body{background-color: black;}</style></head>"
  //"<h1>Контроллер ESP 8266<BR>"
  //"<h2><pre><a href='/u'>";
  "<table border='1' bgcolor='White'><tr><td><a href='/data.xml'>";
  //Serial.println(serverIndex);
  serverIndex += deviceId;
  serverIndex += "</a></td><td><a href='/info'>";
  serverIndex += ver;
  serverIndex += "</a></td><td><a href='/update2'>Upd.2</a>";
  serverIndex += "</td></tr></table><table border='1' bgcolor='Gainsboro'>";
  
  serverIndex += "<tr><td><a href='/edit'>APIP:</a></td><td>";
  serverIndex += WiFi.softAPIP().toString();
  serverIndex += "</td></tr><tr><td>IP:</td><td>";
  serverIndex += WiFi.localIP().toString();
  serverIndex += "</td></tr><tr><td>RSSI:</td><td>";
  long rssi = WiFi.RSSI();
  serverIndex += WiFi.RSSI();
    
  serverIndex += "</td></tr></table><table border='1' bgcolor='LightCyan' ><tr><td>NtpS:</td><td>";//<font size='8'>
  serverIndex += ntpRegion;
  serverIndex += "</td></tr></table>";

  serverIndex += "<table border='1' bgcolor='Moccasin' ><tr><td>UT(d|h|m)</td><td>";
  serverIndex += (((millis()/1000)/60)/60)/24 ;
  serverIndex += "d</td><td>";
  serverIndex += ((millis()/1000)/60)/60 ;
  serverIndex += "h</td><td>";
  serverIndex += (millis()/1000)/60 ;
  serverIndex += "m";
  serverIndex += "</td></tr></table>";
  
  serverIndex += "<table border='1' bgcolor='Moccasin' ><tr><td>Time:</td><td>";//</font>
  serverIndex += currentTimeDeviceString;
  serverIndex += "</td></tr><tr><td>CDT:</td><td>0";

  //parseLongWord((timeCheck + lastSynchroDevice)- currentSecsSince1900);
  serverIndex += countDownTimeString;
  serverIndex += "</td></tr></table>";
  //serverIndex += lastSynchroDeviceString;
  //serverIndex += (millis()/1000) - (soundDelay/1000) ;


  

  if (mp3En){
    serverIndex += "<table border='1' bgcolor='Moccasin' ><tr><td>SoundDelay</td><td>";
    serverIndex += (millis()/1000) - (soundDelay/1000) ;
    serverIndex += "</td></tr></table>";
  }

  #ifdef IRSensorEn
    serverIndex += "<table border='1' bgcolor='DarkSeaGreen' ><tr><td><a href='/ht'>iRSensCounter</a></td><td>";
    serverIndex += iRSensorOnCounter;
    serverIndex += "</td></tr></table>";
  #endif

  if (ultrasonicEn){
    //TODO check work table
      serverIndex += "<table border='1' bgcolor='Plum' ><tr><td>UltrasonicValue</td><td>";
      
      //serverIndex += "<tr><td>UltrasonicValue</td><td>";
      serverIndex += ultrasonicValue;
      serverIndex += "</td></tr><tr><td>UltrasonicCounter</td><td>";
      serverIndex += ultrasonicOnCounter;
      serverIndex += "</td></tr></table>";
  }

  if (sensorEn){
    serverIndex += "<table border='1' bgcolor='SkyBlue' ><tr><td>LedOnCounter</td><td>";//LedSensorValue
    //serverIndex += "<tr><td>LedSensorValue</td><td>";
    serverIndex += switchOnCounter;//ledSensorValue
    serverIndex += "</td></tr></table>";
    serverIndex += "<table border='1' bgcolor='Plum' ><tr><td>LedSensValue</td><td>";//LedOnCounter
    serverIndex += ledSensorValue;//switchOnCounter
    serverIndex += "</td></tr><tr><td>LedOn</td><td>";
    if (switchOn){
    serverIndex += "On";  
    }
    else {
    serverIndex += "Off";   
    }
    //serverIndex += switchOn;
    serverIndex += "</td></tr></table>";
  }
  if (TempEn){
    serverIndex += "<table border='1' bgcolor='PaleGreen' ><tr><td><a href='/ht'>ds1820t1</a></td><td>";
    serverIndex += dsTemp1;
    serverIndex += "</td><td>";
    serverIndex += dsTemp1 - dsPrevTemp1;
//--------------------------------------------------
//serverIndex += "</td><td>";
//serverIndex += ds1820PrevCount;
//--------------------------------------------------


    //serverIndex += "</td></tr>";
    //serverIndex += "<tr><td>ds1820t2</td><td>";
    //serverIndex += dsTemp2;
    //serverIndex += "</td><td>";
    //serverIndex += dsTemp2 - dsPrevTemp2;
    serverIndex += "</td></tr></table>";
  }
  
  #ifdef AM2320
    serverIndex += "<table border='1' bgcolor='DarkSeaGreen' ><tr><td><a href='/ht'>am2320t</a></td><td>";
    serverIndex += am2320t;
    serverIndex += "</td><td>";
    serverIndex += am2320t - AM2320tPrev;
    serverIndex += "</td></tr><tr><td>am2320h</td><td>";
    serverIndex += am2320h;
    serverIndex += "</td><td>";
    serverIndex += am2320h - AM2320hPrev;
    serverIndex += "</td></tr></table>";
  #endif
  
  #ifdef ADS1115
    serverIndex += "<table border='1' bgcolor='SkyBlue' ><tr><td>ads1115(0)Gas</td><td>0";
    serverIndex += float((adc0 * 0.1875)/1000);
    serverIndex += "</td></tr><tr><td>ads1115(1)DGa</td><td>0";
    serverIndex += float((adc1 * 0.1875)/1000);
    serverIndex += "</td></tr><tr><td>ads1115(2)3.3</td><td>0";
    serverIndex += float((adc2 * 0.1875)/1000);
    serverIndex += "</td></tr><tr><td>ads1115(3)5.0</td><td>0";
    serverIndex += float((adc3 * 0.1875)/1000);
    serverIndex += "</td></tr></table>";
  #endif

  //"<a href='/update2'>Update2</a><BR>"
  //"<b>";
  
  serverIndex += "</html>";
  }
