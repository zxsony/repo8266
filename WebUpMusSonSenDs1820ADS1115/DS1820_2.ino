byte dallSensorsCount = 0;
byte dallAddr[10][8];
float dallData[10];
byte flagDallRead;
int16_t dallRaw;


void DallRead(unsigned long interval){
  static unsigned long prevTime = 0;
  if (millis() - prevTime > interval) { //Проверка заданного интервала
  static boolean flagDall = 0; //Признак операции
  prevTime = millis();
  flagDall =! flagDall; //Инверсия признака
  if (flagDall) {
    ds.reset();
    ds.write(0xCC); //Обращение ко всем датчикам
    ds.write(0x44); //Команда на конвертацию
    flagDallRead = 1; //Время возврата в секундах
  }
  else {
    byte i;
     int temp;
     byte dallReadData1[9];
     
    for (i = 0; i < 2; i++){ //Перебор количества датчиков
     ds.reset();
     ds.select(dallAddr[i]);
     ds.write(0xBE); //Считывание значения с датчика

    for (int i = 0; i < 8; i++) {
      dallReadData1[i] = ds.read();
      Serial.print(dallReadData1[i], HEX);
      Serial.print(" ");
    }

  
  dallRaw = (dallReadData1[1] << 8) | dallReadData1[0];
  dallRaw = dallRaw << 3;
  //dallRaw = (dallRaw & 0xFFF0) + 12 - dallReadData1[6];

  if ((dallReadData1[1]==255) and (dallReadData1[0]==255) and (dallReadData1[6]==255) ){
    dallRaw = 0x3E7F;
  }

  dallData[i] = ((float)dallRaw / 16.0)-0.2; //-----------------------------------------------------------
    
     //temp = (ds.read() | ds.read()<<8); //Принимаем два байта температуры
     //dallData[i] = (float)temp / 16.0; 
     Serial.println(dallData[i]);

     if ( i == 0) dsTemp1 = dallData[i];
     if ( i == 1) dsTemp2 = dallData[i];
     flagDallRead = 2; //Время возврата в секундах
     }
   }
  }
}

void DallSearch (){
  byte i;
  int devCounter = 0;
  while  (ds.search(addr)){
    
      for (i=0; i<(8); i++)
      {
        dallAddr[dallSensorsCount][i] = addr[i];
        Serial.println(addr[i], HEX);
      }


    dallSensorsCount++;
    Serial.println(dallSensorsCount);
  }
  ds.reset_search();
  delay(250);
}
