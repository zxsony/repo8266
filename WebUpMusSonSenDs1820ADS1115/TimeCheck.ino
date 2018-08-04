
void CheckTimeEvents(){
  //if (mp3En){
  
  if ((timeM == 0) and (timeH == 0)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (212);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 1)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (201);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 2)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (202);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 3)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (203);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 4)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (204);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 5)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (205);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 6)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (206);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 7)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (207);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 30) and (timeH == 7)){//будильник
  if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
    soundDelay = millis();
    mp3_play (3);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
}
  if ((timeM == 0) and (timeH == 8)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (20);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 9)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (209);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 10)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
    soundDelay = millis();
    mp3_play (210);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 11)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (211);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 12)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (212);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }  
  if ((timeM == 0) and (timeH == 13)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (201);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 14)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (202);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 15)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (203);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 16)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (204);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 17)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (205);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 18)){
      if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
        soundDelay = millis();
        mp3_play (206);
        delay(100);
        mp3_set_volume (30);
        delay(1000);
      }
  }
  if ((timeM == 0) and (timeH == 19)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (207);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
//  if ((timeM == 25) and (timeH == 20)){
  if ((timeM == 54) and (timeH == 22)){

    //AM2320Stack [timeH][2] = am2320t;
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (13);
      delay(100);
      mp3_set_volume (28);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 20)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (20);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 21)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (209);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 22)){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (210);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  if ((timeM == 0) and (timeH == 23) ){
    if (mp3En and (((millis()/1000) - soundDelay/1000)>60)){
      soundDelay = millis();
      mp3_play (211);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
    }
  }
  
}

