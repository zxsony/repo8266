
void GetHTIndex (void){
//    for (int i = 0; i < 25; i++) {
//      Serial.println(AM2320Stack[i][1]);
////    AM2320Stack [i][0] = i;
////    AM2320Stack [i][1] = i;
//  }
  serverIndex = "<html><head><title>ESP8266</title><meta http-equiv='Content-Type' content='text/html; charset=utf-8' />"
  "<style>pre {-moz-tab-size: 3;}</style><style type='text/css'>TABLE {color:black;font-size:140%;font-weight:bold;} body{background-color: black;}</style></head>";
  serverIndex += "</table><table border='1' bgcolor='Gainsboro'>";

  serverIndex += "<tr><td><a href='/'>Hour</a></td><td>Hydro</td><td>Temp</td><td>T1</td><td>T2</td>";
  serverIndex += "<tr><td>0</td><td>";
  serverIndex += tempStack [0][0];
  serverIndex += "</td><td>";
  serverIndex += tempStack [0][1];
  serverIndex += "</td><td>";
  serverIndex += tempStack [0][2];
  serverIndex += "</td><td>";
  serverIndex += tempStack [0][3];  

  for (int i = 1; i<24; i++){
    if (i == timeH){
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
    //Serial.println(AM2320Stack[i][1]);
  }
   
  serverIndex += "</td></tr></table>";
  
  serverIndex += "</form></pre></h2></html>";
  }
