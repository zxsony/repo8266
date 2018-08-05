
void GetHTIndex (void){
//    for (int i = 0; i < 25; i++) {
//      Serial.println(AM2320Stack[i][1]);
////    AM2320Stack [i][0] = i;
////    AM2320Stack [i][1] = i;
//  }
  serverIndex = "<html><head><title>ESP8266</title><meta http-equiv='Content-Type' content='text/html; charset=utf-8' />"
  "<style>pre {-moz-tab-size: 3;}</style><style type='text/css'>TABLE {color:black;font-size:130%;font-weight:bold;} body{background-color: black;}</style></head>";
  serverIndex += "</table><table border='1' bgcolor='Gainsboro'>";

  serverIndex += "<tr><td>Hour</td><td>Hydro</td><td>Temp</td>";
  serverIndex += "<tr><td>0</td><td>";
  serverIndex += AM2320Stack [0][0];
  serverIndex += "</td><td>";
  serverIndex += AM2320Stack [0][1];

  for (int i = 1; i<25; i++){
    serverIndex += "</td></tr><tr><td>";
    serverIndex += i;
    serverIndex += "</td><td>";
    serverIndex += AM2320Stack [i][0];
    serverIndex += "</td><td>";
    serverIndex += AM2320Stack [i][1];
    //Serial.println(AM2320Stack[i][1]);
  }
   
  serverIndex += "</td></tr></table>";
  
  serverIndex += "</form></pre></h2></html>";
  }
