
void averageUltrasonic (void){
  ultrasonicValue = 0;
  for (int i = 0; i < 3; i++){
  ultrasonicValue += ultrasonic.distanceRead(CM);
  //delay(1);
  }
  ultrasonicValue = ultrasonicValue / 3;
}
void CheckUltrasonic (void){
  if (ultrasonicValue>10) {
    ledCurrent = ledPinBR2;
  }
  if (ultrasonicValue<10) {
    ledCurrent = ledPinR;
  }
  if ((ultrasonicValue>500) and (ledSensorState == true)) {
    ultrasonicOnCounter += 1;
    ledCurrent = ledPinGR1;

    if((((millis()/1000) - soundDelay/1000)>3)){
    digitalWrite(ledCurrent, HIGH);
    if (mp3En){

    switch (ktoid){
      case 1:
        if (mp3En){
          mp3_set_volume (30);
          delay(100);
          mp3_play (21);
          delay(500);
          ktoid ++;    
          break;
        }
    case 2:
        if (mp3En){
          mp3_set_volume (30);
          delay(100);
          mp3_play (22);
          delay(500);
          ktoid ++;    
          break;
        }
      case 3:
        if (mp3En){
          mp3_set_volume (30);
          delay(100);
          mp3_play (23);
          delay(500);
          ktoid ++;    
          break;
        }
      case 4:
        if (mp3En){
          mp3_set_volume (30);
          delay(100);
          mp3_play (24);
          delay(500);
          ktoid ++;    
          break;
        }
     case 5:
        if (mp3En){
          mp3_set_volume (30);
          delay(100);
          mp3_play (25);
          delay(500);
          ktoid ++;    
          break;
        }
    case 6:
        if (mp3En){
          mp3_set_volume (30);
          delay(100);
          mp3_play (26);
          delay(500);
          ktoid = 1;    
          break;
        }
       //ktoid ++;
  }
      
    }

    }
    digitalWrite(ledCurrent, LOW);
  }
}
