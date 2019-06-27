
void CheckIRSensor (void){

if((((millis()) - soundDelay)>300000)){
  ktoid = 7;
  
}

    if(digitalRead(IRSensorIn) == HIGH and iRSensorState == false and SecurityEn == true){
      iRSensorOnCounter ++;

      
      FS_FileWrite("/Sensors.txt", "IR:" + (String)iRSensorOnCounter);
      
      iRSensorState = true;
      ledCurrent = ledPinR;
      digitalWrite(ledCurrent, HIGH);
      if (mp3En){
   
      switch (ktoid){
        case 1:
          if (mp3En){
            mp3_set_volume (30);
            delay(100);
            mp3_play (21);
            delay(100);
            ktoid ++;    
            break;
          }
      case 2:
          if (mp3En){
            mp3_set_volume (30);
            delay(100);
            mp3_play (22);
            delay(100);
            ktoid ++;    
            break;
          }
        case 3:
          if (mp3En){
            mp3_set_volume (30);
            delay(100);
            mp3_play (23);
            delay(100);
            ktoid ++;    
            break;
          }
        case 4:
          if (mp3En){
            mp3_set_volume (30);
            delay(100);
            mp3_play (24);
            delay(100);
            ktoid ++;    
            break;
          }
       case 5:
          if (mp3En){
            mp3_set_volume (30);
            delay(100);
            mp3_play (22);
            delay(100);
            ktoid ++;    
            break;
          }
      case 6:
          if (mp3En){
            mp3_set_volume (30);
            delay(100);
            mp3_play (26);
            delay(100);
            ktoid = 1;    
            break;
          }
      case 7:
        if (mp3En){
          mp3_set_volume (30);
          delay(100);
          mp3_play (17);
          delay(100);
          ktoid = 1;
          soundDelay = millis();    
          break;
        }
         //ktoid ++;
    }
        
  //      mp3_set_volume (20);
  //      delay(100);
  //      mp3_play (6);
  //      delay(1000);  
      }
  
      }
  if(digitalRead(IRSensorIn) == LOW and iRSensorState == true){
      iRSensorState = false;
      ledCurrent = ledPinGR1;
      digitalWrite(ledCurrent, LOW);
  }
  //}
}
