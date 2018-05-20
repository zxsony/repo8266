
void CheckTimeEvents(){
  if (mp3En){
  
  if ((timeM == 0) and (timeH == 0 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (212);
    delay(100);
    mp3_set_volume (20);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 1 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (201);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 2 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (202);
    delay(100);
    mp3_set_volume (20);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 3 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (203);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 4 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (204);
    delay(100);
    mp3_set_volume (20);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 5 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (205);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 6 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (206);
    delay(100);
    mp3_set_volume (20);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 7 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (207);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
  }
  if ((timeM == 30) and (timeH == 7 and (((millis()/1000) - soundDelay/1000)>60)) ){//будильник
  soundDelay = millis();
    mp3_play (3);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
}
  if ((timeM == 0) and (timeH == 8 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (20);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 9 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (209);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 10 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (210);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 11 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (211);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 12 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (212);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
  }  
  if ((timeM == 0) and (timeH == 13 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (201);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 14 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (202);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 15 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (203);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 16 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (204);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 17 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (205);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 18) and (((millis()/1000) - soundDelay/1000)>60) ){
      soundDelay = millis();
      mp3_play (206);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 19 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (207);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
  if ((timeM == 25) and (timeH == 20 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (13);
    delay(100);
    mp3_set_volume (28);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 20 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (20);
      delay(100);
      mp3_set_volume (30);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 21 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (209);
    delay(100);
    mp3_set_volume (30);
    delay(1000);
  }
  if ((timeM == 0) and (timeH == 22 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
      mp3_play (210);
      delay(100);
      mp3_set_volume (20);
      delay(1000);
  }
  if ((timeM == 0) and (timeH == 23 and (((millis()/1000) - soundDelay/1000)>60)) ){
    soundDelay = millis();
    mp3_play (211);
    delay(100);
    mp3_set_volume (20);
    delay(1000);
  }
  }
}

