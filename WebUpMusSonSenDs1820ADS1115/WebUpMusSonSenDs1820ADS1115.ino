
#include <Adafruit_ADS1015.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//#include <ESP8266mDNS.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
#include <Ultrasonic.h>
#include <WiFiUdp.h>
#include <OneWire.h>
#include <Wire.h>
#include <Ticker.h>
#include <FS.h>

Ultrasonic ultrasonic(4,16);
const char* host = "esp8266-webupdate";

//////////////////////
#define board6
//#define debug
//String deviceId = "1";  //1=loc, sound; 2=loc, temp
                        //3=pn, temp; 4=td, temp
String ver = "v2.5.6";
//////////////////////
#ifdef board1
  bool mp3En = 1;
  bool TempEn = 0;
  bool ultrasonicEn = 0;
  bool sensorEn = 1;
  bool ntpEn = 1;
  const char* ssid = "NVRAM WARNING";
  const char* password = "Lift80Lift";
  String deviceId = "board1";
  
  #define IRSensorEn
  #define ledblink  
#endif


#ifdef board2
  bool mp3En = 0;
  bool TempEn = 1;
  bool ultrasonicEn = 0;
  bool sensorEn = 0;
  bool ntpEn = 1;
  const char* ssid = "NVRAM WARNING";
  const char* password = "Lift80Lift";
  String deviceId = "board2";
  //#define IRSensorEn
  //const char* ssid = "la8";
  //const char* password = "Lift1980";
  
  //#define debug
  #define ADS1115
  #define AM2320
  #define ledblink
#endif


#ifdef board3
  bool mp3En = 0;
  bool TempEn = 1;
  bool ultrasonicEn = 0;
  bool sensorEn = 0;
  bool ntpEn = 1;
//  const char* ssid = "OTK2";
//  const char* password = "Lift80Lift";
//  const char* ssid = "Pusko-Naladka";
//  const char* password = "1234578906";
  const char* ssid = "NVRAM WARNING";
  const char* password = "Lift80Lift";
  String deviceId = "board3";
  //#define AM2320
  #define ledblink
#endif

  
#ifdef board4
  bool mp3En = 0;
  bool TempEn = 1;
  bool ultrasonicEn = 0;
  bool sensorEn = 0;
  bool ntpEn = 1;
  const char* ssid = "Tenda_FBA7C0";
  const char* password = "121314150";
  String deviceId = "board4";

  #define ledblink
#endif

#ifdef board5
  bool mp3En = 0;
  bool TempEn = 0;
  bool ultrasonicEn = 0;
  bool sensorEn = 1;
  bool ntpEn = 1;
  const char* ssid = "NVRAM WARNING";
  const char* password = "Lift80Lift";
  String deviceId = "board5";
  
  #define ledblink  
#endif

#ifdef board6
  bool mp3En = 0;
  bool TempEn = 0;
  bool ultrasonicEn = 0;
  bool sensorEn = 0;
  bool ntpEn = 1;
  //const char* ssid = "Tenda_FBA7C0";
  //const char* password = "121314150";
  const char* ssid = "NVRAM WARNING";
  const char* password = "Lift80Lift";
  String deviceId = "board6";
  #define AM2320
  #define ledblink
  //#define irtool  
#endif

byte mac[6];

int button = 4;
int IRSensorIn = 16;
int sensorPin = A0;
int ledPinGR1 = 12;
int ledPinBR2 = 13;
int ledPinYR3 = 14;
int ledPinR = 15;
int ledCurrent = ledPinGR1;
int ledSensorValue = 0;
bool switchOn = false;
int switchOnCounter = 0;
int ultrasonicValue = 0;
int ultrasonicOnCounter = 0;
bool ledSensorState = false;
bool IRSensorEnVar = false;
bool iRSensorState = false;
int iRSensorOnCounter = 0;
bool LightActivityState1 = false;
bool LightActivityState2 = false;
bool LightActivityState3 = false;
bool SecurityEn = true;
bool ledblinkVal = false;

int ultrasonicLoop = 0;
String ledColoure = "green";
int ktoid = 1;
String devNumbFull, tempStr;
int watchdogCount = 0;

float tempStack [24][8];

String wifiStack [10][2];
int wifiCount;

String filename = "/data.txt";
  
unsigned long startTimeDevice, currentTimeDevice, startSecsSince1900, currentSecsSince1900, secsSince1900, epochStamp;
unsigned long lastStartDevice, lastSynchroDevice, timeCheck, synCheck, soundDelay, dsDelay, ADC1115Delay, AM2320Delay, LightActivityDelay;
String timeString, currentTimeDeviceString, lastStartDeviceString, lastSynchroDeviceString, countDownTimeString, ntpRegion;
byte timeD, timeH, timeM, timeS, testByte;
uint8_t hour, minute, second, day, month, year, weekday;
uint8_t monthDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool dataRecive;
unsigned int localPort = 2390;
//IPAddress timeServer(129, 6, 15, 30);// 28, 29

const int NTP_PACKET_SIZE = 48;
byte packetBuffer[ NTP_PACKET_SIZE];
WiFiUDP Udp;
Ticker secondTick;

  OneWire  ds(0);

  float dsTemp1, dsTemp2;
  float dsPrevTemp1= 255;
  float dsPrevTemp2 = 255;
  bool ds1820PrevSet;
//  int ds1820PrevCount = 0;
#ifdef ADS1115
  Adafruit_ADS1115 ads1115(0x4A);  // construct an ads1115 at address 0x49
  int16_t adc0, adc1, adc2, adc3;
#endif

ESP8266WebServer server(80);
//const char* serverIndex = "<form method='POST' acton=i'/update' enctype='multipart/form-data'><input type='file' name='update'><input type='submit' value='Update'></form>";
  String serverIndex = "<form method='POST' action='/update' enctype='multipart/form-data'>"
  "<a href='http://192.168.1.203/'>Home</a><BR>"
  "</form>";
  String xmlData = "<?xml version='1.0' ?><main><name>test name data</name><testData>test data</testData></main>";

File fsUploadFile;

void ISRwatchdog(){
  watchdogCount++;
  if (watchdogCount == 60){
    Serial.println();
    Serial.println("the watchdog bites!!!!!!!!!!");

    if (mp3En){
    mp3_play (30);
    delay(100);
    mp3_set_volume (32);
    delay(100);      
    } 
    
    ESP.reset();
  }
}
void tmp(void){} // not del
