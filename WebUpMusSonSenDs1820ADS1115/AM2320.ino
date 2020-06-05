#define AM2320_i2C_ADDRESS  0xB8
unsigned char am2320buf[8];
String nameam2320t, nameam2320h;
float am2320h, am2320t, corram2320h, corram2320t;
float am2320mt [50], am2320mh [50], am2320at[10], am2320ah[10];
int am2320ct [50], am2320ch [50];
int am2320storagecounter, am2320averagecounter;
int am2320storage;
int am2320average;
float AM2320hPrev = 255;
float AM2320tPrev = 255;
bool am2320Request;
bool AM2320PrevSet;
bool am2320averagecounterfull;
int am2320requery;
bool am2320debug;

//if (am2320En){
int _cou = 0;


//unsigned long AM2320DelayPrev = 0;
void AM23020Read () {
  //if (AM2320DelayPrev == 0) AM2320DelayPrev = millis();
#ifdef debug
  //Serial.print(_cou);
  //Serial.print(" am3020 in count.\r\n");
  _cou ++;
#endif

#ifdef ADS1115
  unsigned long _tempADC1115Delay = millis();
#endif

  //if (AM2320Delay == 0){
  if (am2320Request) {
    AM2320Delay = millis();
    am2320Request = false;
  }
  if ((millis() - AM2320Delay) <= 1) {
#ifdef debug
    Serial.print(currentTimeDeviceString);
    Serial.print(" AM2320 transmission.\r\n");
#endif
//    Wire.beginTransmission(AM2320_i2C_ADDRESS >> 1);  
//    Wire.endTransmission(1);
//    Wire.beginTransmission(AM2320_i2C_ADDRESS >> 1);
//    Wire.endTransmission(0);
//    delay(10);
//    Wire.beginTransmission(AM2320_i2C_ADDRESS >> 1);
//    Wire.write(0x03);
//    Wire.write(0x00);
//    Wire.write(0x04);
//    
//    delay(10);
//    Wire.endTransmission(1);

    
//    if (Wire.endTransmission(1) != 0) {
//      //      am2320buf[2] = 0;
//      //      am2320buf[3] = 0;
//      //      am2320buf[4] = 0;
//      //      am2320buf[5] = 0;
//#ifdef debug
//      Serial.print("Not transmission.\r\n");
//#endif
//    }
  }
  if ((millis() - AM2320Delay) >= am2320requery * 1000) {//1600
    //AM2320Delay = 0;
    am2320Request = true;
#ifdef debug
    Serial.print(currentTimeDeviceString);
    Serial.print(" AM2320 request.");
    Serial.println(millis() - AM2320Delay);
#endif
    Wire.beginTransmission(AM2320_i2C_ADDRESS >> 1);
    Wire.endTransmission(1); 
    //int aet = Wire.endTransmission(1);
    //delay(10);
    Wire.beginTransmission(AM2320_i2C_ADDRESS >> 1);
    Wire.endTransmission(0);
    //int bet = Wire.endTransmission(0);
    delay(10);
    Wire.beginTransmission(AM2320_i2C_ADDRESS >> 1);
    Wire.write(0x03);
    Wire.write(0x00);
    Wire.write(0x04);
    
    Wire.endTransmission(1);
    //int cet = Wire.endTransmission(1);
delay(10);

    
    Wire.beginTransmission(AM2320_i2C_ADDRESS >> 1);
    Wire.requestFrom(AM2320_i2C_ADDRESS >> 1, 8, 1);
    while (Wire.available())
    {
      for (int i = 0; i < 8; i++) am2320buf[i] = Wire.read();
    }
    Wire.endTransmission(1);
    //int det = Wire.endTransmission(1);
// Serial.println(aet);
// Serial.println(bet);
// Serial.println(cet);
// Serial.println(det);  
//Serial.println("AM2320 read");
//  for (int i = 0; i<7; i++){
//    Serial.println(am2320buf[i]);
//  }
//Serial.println(((float)(((am2320buf[4] << 8) + am2320buf[5]) / 10.0) + corram2320t));
//Serial.println(((float)(((am2320buf[2] << 8) + am2320buf[3]) / 10.0) + corram2320h));    
    if (am2320buf[2] == 0 & am2320buf[3] == 0) {
#ifdef debug
      Serial.print(currentTimeDeviceString);
      Serial.print(" Null. Delay ");
      Serial.println(millis() - AM2320Delay);
#endif
    }

    if  (am2320storagecounter < am2320storage) {
      am2320mt [am2320storagecounter] = ((float)(((am2320buf[4] << 8) + am2320buf[5]) / 10.0) + corram2320t);
      //Serial.println((float)(((am2320buf[4] << 8) + am2320buf[5]) / 10.0) + corram2320t);

      am2320mh [am2320storagecounter] = ((float)(((am2320buf[2] << 8) + am2320buf[3]) / 10.0) + corram2320h);

#ifdef debug2320
      if (am2320debug){
            Serial.println (am2320mt [am2320storagecounter]);
            Serial.println (am2320mh [am2320storagecounter]);  
      }

#endif
      //Serial.println(am2320storagecounter);
      am2320storagecounter++;

      if  (am2320storagecounter == am2320storage) {


        search_max_sort(am2320mt, am2320ct, am2320storagecounter);

//        Serial.print(am2320mt[am2320storagecounter - 1]);
//        Serial.print(" ");
//        Serial.println(am2320ct[am2320storagecounter - 1]);

        search_max_sort(am2320mh, am2320ch, am2320storagecounter);

//        Serial.print(am2320mh[am2320storagecounter - 1]);
//        Serial.print(" ");
//        Serial.println(am2320ch[am2320storagecounter - 1]);

        if (am2320averagecounter < am2320average)
        {

          am2320at [am2320averagecounter] = am2320mt[am2320storagecounter - 1];
          am2320ah [am2320averagecounter] = am2320mh[am2320storagecounter - 1];
          am2320averagecounter++;
          if (am2320averagecounterfull)
          {
            am2320t = average_data(am2320at, am2320average);
            am2320h = average_data(am2320ah, am2320average);
          }
          else
          {
            am2320t = average_data(am2320at, am2320averagecounter);
            am2320h = average_data(am2320ah, am2320averagecounter);        
          }
//          am2320t = average_data(am2320at, am2320averagecounter);
//          am2320h = average_data(am2320ah, am2320averagecounter);
          if (am2320debug){
            Serial.print(am2320averagecounter);
            Serial.print(" average am2320t=");
            Serial.println(am2320t);
            Serial.print(am2320averagecounter);
            Serial.print(" average am2320h=");
            Serial.println(am2320h);
          }
          if (am2320averagecounter == am2320average)
          {
            am2320averagecounter = 0;
            am2320averagecounterfull = true;
          }
        }
        am2320storagecounter = 0;
      }
    }
    //    #ifdef board2
    //    am2320t = ((float)(((am2320buf[4] << 8) + am2320buf[5]) / 10.0) - 0.4);// 26.77-(-.33)
    //    am2320h = ((float)(((am2320buf[2] << 8) + am2320buf[3]) / 10.0) + 25.5);//16.3-89 14.16-82.46 20.1-90.6 29,4-15,7
    //    #endif
    //    #ifdef board3
    //    am2320t = ((float)(((am2320buf[4] << 8) + am2320buf[5]) / 10.0) - 3.2);// 26.77-(-.33)
    //    am2320h = ((float)(((am2320buf[2] << 8) + am2320buf[3]) / 10.0) + 15.5);//16.3-89 14.16-82.46 20.1-90.6 29,4-15,7
    //    #endif
    //    #ifdef board6
    //    am2320t = ((float)(((am2320buf[4] << 8) + am2320buf[5]) / 10.0) - 2.0);// 26.77-(-.33)
    //    am2320h = ((float)(((am2320buf[2] << 8) + am2320buf[3]) / 10.0) - 11.0);// - 11.8
    //    #endif
    //(iva/2320) (27.77 88 / 27.77 72.5)15.5

    if (AM2320hPrev == 255 and am2320h != 0) AM2320hPrev = am2320h;
    if (AM2320tPrev == 255 and am2320t != 0) AM2320tPrev = am2320t;
    if (AM2320PrevSet) {
      AM2320hPrev = am2320h;
      AM2320tPrev = am2320t;
      AM2320PrevSet = false;
    }


  }
#ifdef ADS1115
  ADC1115Delay = ADC1115Delay + (millis() - _tempADC1115Delay);
#ifdef debug
  //      Serial.print("_tempADC1115Delay ");
  //      Serial.println(millis() - _tempADC1115Delay);
#endif
#endif
}


void search_max_sort(float* m, int* index, int sizem)
{
  for (int i1 = 0; i1 < sizem; i1++)
  { // search max
    int counter = 0;
    for (int i2 = 0; i2 < sizem; i2++)
    {
      if (m[i1] == m[i2])
      {
        counter++;
      }
    }
    index[i1] = counter;
  }
  for (int i = 1; i < sizem; i++)
  { //sort max
    int counter = i;
    while (counter > 0 and m[counter - 1] > m[counter])
    {
      float tmpm = m[counter - 1];
      int tmpi = index[counter - 1];

      m[counter - 1] = m[counter];
      m[counter] = tmpm;

      index[counter - 1] = index[counter];
      index[counter] = tmpi;

      counter--;
    }
  }
  for (int i = 1; i < sizem; i++)
  { //sort index
    int counter = i;
    while (counter > 0 and index[counter - 1] > index[counter])
    {
      float tmpm = m[counter - 1];
      int tmpi = index[counter - 1];

      m[counter - 1] = m[counter];
      m[counter] = tmpm;

      index[counter - 1] = index[counter];
      index[counter] = tmpi;

      counter--;
    }
  }
}
float average_data (float* m, int averagecouner)
{
  float tmp = 0;
  for (int i = 0; i < averagecouner; i++)
  {
    tmp += m[i];
  }
  return tmp / averagecouner;
}
