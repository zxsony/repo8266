  byte data[12];
  byte addr[8], addr1[8], addr2[8];
  byte dsData1[9], dsData2[9];
  int devCounter = 0;
  
  
void DsTempCalc(){

  //Serial.println(devCounter);
  int16_t raw1, raw2;
  raw1 = (dsData1[1] << 8) | dsData1[0];
  raw1 = raw1 << 3;
  raw1 = (raw1 & 0xFFF0) + 12 - dsData1[6];

  if ((dsData1[1]==255) and (dsData1[0]==255) and (dsData1[6]==255) or ((dsData1[1]==0) and (dsData1[0]==0) and (dsData1[6]==0))){
    raw1 = 0x3E7F;
  }
  raw2 = (dsData2[1] << 8) | dsData2[0];
  raw2 = raw2 << 3;
  raw2 = (raw2 & 0xFFF0) + 12 - dsData2[6];
        
  if ((dsData1[1]==255) and (dsData1[0]==255) and (dsData1[6]==255) or ((dsData1[1]==0) and (dsData1[0]==0) and (dsData1[6]==0))){
    raw2 = 0x3E7F;
  }
  dsTemp1 = ((float)raw1 / 16.0)+ ds1820corr[0]; //-----------------------------------------------------------
  dsTemp2 = ((float)raw2 / 16.0)+ ds1820corr[1];
//  Serial.print ("Sensor1=");
//  Serial.println((float)raw1 / 16.0);
//  Serial.print ("Sensor2=");
//  Serial.println((float)raw2 / 16.0);
//  Serial.println(""); 
if (dsPrevTemp1 == 255 and dsTemp1 <999) dsPrevTemp1 = dsTemp1;
if (dsPrevTemp2 == 255 and dsTemp2 <999) dsPrevTemp2 = dsTemp2;

    if (devCounter == 1){
      dsTemp2 = 0;
      dsPrevTemp2 = 0;
    }

  if (ds1820PrevSet){
    dsPrevTemp1 = dsTemp1;
    dsPrevTemp2 = dsTemp2;
//    ds1820PrevCount ++;
    ds1820PrevSet = false;
    
  }
}

void DsDataPrint(){
  byte i;
  for ( i = 0; i < 9; i++) {
    Serial.print(dsData1[i], HEX);
    Serial.print(" ");
  }
  Serial.println("");
  for ( i = 0; i < 9; i++) {
    Serial.print(dsData2[i], HEX);
    Serial.print(" ");
  } 
  Serial.println("");  
}
 
void DsRead (){
  byte i;
  //Serial.println(dsDelay);
  if (dsDelay == 0){
    dsDelay = millis();
  }
  if ((millis() - dsDelay)<=1){
    //Serial.println(millis() - dsDelay);
    ds.reset();
    ds.select(addr1);
    ds.write(0x44);
    ds.reset();
    ds.select(addr2);
    ds.write(0x44);   
  }

 //delay(1000);
  if ((millis() - dsDelay)>=1000){
    //Serial.println(millis() - dsDelay);
    dsDelay = 0;
    ds.reset();
    ds.select(addr1);    
    ds.write(0xBE);
    for ( i = 0; i < 8; i++) {
      dsData1[i] = ds.read();
      //Serial.print(dsData1[i], HEX);
      //Serial.print(" ");
    }
    //Serial.println("\n");
    ds.reset();
    ds.select(addr2);    
    ds.write(0xBE);
    for ( i = 0; i < 8; i++) {
      dsData2[i] = ds.read();
      //Serial.print(dsData2[i], HEX);
      //Serial.print(" ");
    }
    //Serial.println("\n"); 
    //Serial.println("\n");    
  }

}
void DsSearch (){
  //Serial.println("DsSearch");
  byte i;
  
  while  (ds.search(addr)){
    //Serial.println(devCounter);
    devCounter++;
    if (devCounter==1){ 
      for (i=0; i<(8); i++)
      {
        addr1[i] = addr[i];
        //Serial.println(addr[i], HEX);
      }
    }
    if (devCounter==2){ 
      for (i=0; i<(8); i++)
      {
        addr2[i] = addr[i];
        //Serial.println(addr[i], HEX);
      }
    }
    Serial.println("");
    //delay(250);
  }
  ds.reset_search();
  delay(250);
}
void DsAddrPrint(){
  byte i;
  Serial.print("TS2: ");
  for( i = 0; i < 8; i++) {
    Serial.print(addr1[i], HEX);
    Serial.print(" ");
  }
  Serial.println("");
  Serial.print("TS1: ");
  for( i = 0; i < 8; i++) {
    Serial.print(addr2[i], HEX);
    Serial.print(" ");
  }
  Serial.println("");
}
