String FS_ReadSetting(String section, String parametr) {
  int c = 0;
  String data[2];
  File f = SPIFFS.open("/8266settings.txt", "r");
  if (!f) {
    Serial.println("File doesn't exist yet. Creating it");
    File f = SPIFFS.open("/8266settings.txt", "w");
    if (!f) {
      Serial.println("file creation failed");
    }
    f.println("[MAIN]");
    f.println("deviceId=device0");
    f.println("tempEn=0");
    f.println("analogSensorEn=0");
    f.println("am2320En=0");
    f.println("securityEn=0");
    f.println("mp3En=0");
    f.println("ultrasonicEn=0");
    f.println("ntpEn=1");
    f.println("ledblink=1");
    f.println("syncheck=3600");
    f.println("test=0");
    f.println("");
    
    f.println("[INTERFACE]");
    f.println("oneWire=5");
    f.println("i2cSDA=4");
    f.println("i2cSCL=14");
    f.println("");
    
    f.println("[WIFIAP]");
    f.println("ssid1=NVRAM WARNING");
    f.println("pass1=Lift80Lift");
    f.println("ssid2=zxASUSzx");
    f.println("pass2=Lift80Lift");
    f.println("ssid3=la2");
    f.println("pass3=Lift1980");
    f.println("");

    f.println("[NETWORK]");
    f.println("ipset=0");
    f.println("ip=192.168.1.100");
    f.println("mask=255.255.0.0");
    f.println("gate=192.168.1.1");
    f.println("");
    
    f.println("[DS1820]");
    f.println("name0=ds1820t1");
    f.println("corr0=0.0");
    f.println("name1=ds1820t2");
    f.println("corr1=0.0");
    f.println("");
    
    f.println("[AM2320]");
    f.println("namet=AM2320 t");
    f.println("corrt=0.0");
    f.println("nameh=AM2320 h");
    f.println("corrh=0.0");
    f.println("storage=1");
    f.println("average=1");
    f.println("requery=20");
    f.println("debug=0");


  } 
      String dataread, dataparametr;
      
      while (f.available()){
        dataread = f.readStringUntil('\n');
        dataread.replace("\r", "");
        if (dataread == section)
          {
            while (f.available()){
              dataread = f.readStringUntil('\n');
              dataread.replace("\r", "");
              if (dataread.indexOf("[") > -1) break;
              if (dataread.indexOf(parametr + "=") > -1){
                //Serial.println (dataread.substring (0,dataread.indexOf("=")));
                //Serial.println (dataread.substring (dataread.indexOf("=") + 1));
                dataparametr = dataread.substring (dataread.indexOf("=") + 1);
              }
            }
          }
      }
  f.close();
  return dataparametr;
}



void FS_FileDimWrite(String Fname, String Data) {
  bool fe = SPIFFS.exists(Fname);
  File f = SPIFFS.open(Fname, "a");
  if (!f) {
    Serial.println("file open failed");
  }
  else
  {
    if (!fe) f.print("\"time\";");
    if (am2320En and !fe) {
      f.print("\"" + nameam2320t + "\";");
      f.print("\"" + nameam2320h + "\"");
    }
    if (tempEn and !fe) {
      f.print(";\"" + ds1820name[0] + "\";");
      f.print("\"" + ds1820name[1] + "\"");
    }
    if (analogSensorEn and !fe) {
      f.print(";\"analogIn\"");
    }
    if (!fe) f.print("\r");
    
    for(int w = 0; w < sampleLimit; w++){
if (sampleDateTimeStack[w][0] != 0){
    if (sampleDateTimeStack[w][2] < 10) f.print("0");//hour
    f.print((String)sampleDateTimeStack[w][2]);
    f.print(":");
    if (sampleDateTimeStack[w][3] < 10) f.print("0");//minute
    f.print((String)sampleDateTimeStack[w][3]);

    if (am2320En) {
      f.print(";");
      f.print((String)sampleDataStack[w][0]);
      f.print(";");
      f.print((String)sampleDataStack[w][1]);
    }

    if (tempEn) {
      f.print(";");
      f.print((String)sampleDataStack[w][2]);
      f.print(";");
      f.print((String)sampleDataStack[w][3]);
    }

    if (analogSensorEn) {
      f.print(";");
      f.print((String)((int)sampleDataStack[w][6]));
    }    
    
    f.print("\r");
}
    }
    f.close();
  }
}


void FS_ReadAM2320Setting(void) {
  int c = 0;
  File f = SPIFFS.open("/2320settings.txt", "r");
  if (!f) {
    Serial.println("File doesn't exist yet. Creating it");

    // open the file in write mode
    File f = SPIFFS.open("/2320settings.txt", "w");
    if (!f) {
      Serial.println("file creation failed");
    }
    // now write two lines in key/value style with  end-of-line characters
    f.println("0.0");
    f.println("0.0");
  } 
      String tstr = f.readStringUntil('\n');
      tstr.replace("\n", "");
      tstr.replace("\r", "");
      corram2320t = tstr.toFloat();
      //Serial.println(corram2320t);
      tstr = f.readStringUntil('\n');
      tstr.replace("\n", "");
      tstr.replace("\r", "");
      corram2320h = tstr.toFloat();
  f.close();
}


int FS_ReadWiFiSetting(void) {
  int c = 0;
  File f = SPIFFS.open("/wifisettings.txt", "r");
  if (!f) {
    Serial.println("File doesn't exist yet. Creating it");

    // open the file in write mode
    File f = SPIFFS.open("/wifisettings.txt", "w");
    if (!f) {
      Serial.println("file creation failed");
    }
    // now write two lines in key/value style with  end-of-line characters
    f.println("la2");
    f.println("Lift1980");
    f.println("Tenda_FBA7C0");
    f.println("121314150");
    f.println("NVRAM WARNING");
    f.println("Lift80Lift");
  } else {
    // we could open the file
    
    while (f.available()) {
      //Lets read line by line from the file
      String tstr = f.readStringUntil('\n');
      tstr.replace("\n", "");
      tstr.replace("\r", "");
      wifiAp [c][0] = tstr;
      tstr = f.readStringUntil('\n');
      tstr.replace("\n", "");
      tstr.replace("\r", "");
      wifiAp [c][1] = tstr;
      c++;
    }
  }
  f.close();
  return c;
}


void FS_FileWrite(String Fname, String Data) {
  File f = SPIFFS.open(Fname, "a");
  if (!f) {
    Serial.println("file open failed");
  }
  else
  {
    if (day < 10) f.print("0");
    f.print(day);
    f.print(".");
    if (month < 10) f.print("0");
    f.print(month);
    f.print(".");
    f.print(year - 100);
    f.print(";");
    if (hour < 10) f.print("0");
    f.print(hour);
    f.print(":");
    if (minute < 10) f.print("0");
    f.print(minute);
    f.print(";");

    f.print(Data);
    f.print("\r");

    f.close();
  }
}

// Инициализация FFS
void FS_init(void) {
  SPIFFS.begin();
  {
    Dir dir = SPIFFS.openDir("/");
    while (dir.next()) {
      String fileName = dir.fileName();
      size_t fileSize = dir.fileSize();
    }
  }
  //HTTP страницы для работы с FFS
  //list directory
  server.on("/list", HTTP_GET, handleFileList);
  //загрузка редактора editor
  server.on("/edit", HTTP_GET, []() {
    if (!handleFileRead("/edit2.html")) server.send(404, "text/plain", "FileNotFound");
  });
  //Создание файла
  server.on("/edit", HTTP_PUT, handleFileCreate);
  //Удаление файла
  server.on("/edit", HTTP_DELETE, handleFileDelete);
  //first callback is called after the request has ended with all parsed arguments
  //second callback handles file uploads at that location
  server.on("/edit", HTTP_POST, []() {
    server.send(200, "text/plain", "");
  }, handleFileUpload);
  //called when the url is not defined here
  //use it to load content from SPIFFS
  server.onNotFound([]() {
    if (!handleFileRead(server.uri()))
      server.send(404, "text/plain", "FileNotFound");
  });
}
// Здесь функции для работы с файловой системой
String getContentType(String filename) {
  if (server.hasArg("download")) return "application/octet-stream";
  else if (filename.endsWith(".htm")) return "text/html";
  else if (filename.endsWith(".html")) return "text/html";
  else if (filename.endsWith(".json")) return "application/json";
  else if (filename.endsWith(".css")) return "text/css";
  else if (filename.endsWith(".js")) return "application/javascript";
  else if (filename.endsWith(".png")) return "image/png";
  else if (filename.endsWith(".gif")) return "image/gif";
  else if (filename.endsWith(".jpg")) return "image/jpeg";
  else if (filename.endsWith(".ico")) return "image/x-icon";
  else if (filename.endsWith(".xml")) return "text/xml";
  else if (filename.endsWith(".pdf")) return "application/x-pdf";
  else if (filename.endsWith(".zip")) return "application/x-zip";
  else if (filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}

bool handleFileRead(String path) {
  if (path.endsWith("/")) path += "index.htm";
  String contentType = getContentType(path);
  String pathWithGz = path + ".gz";
  if (SPIFFS.exists(pathWithGz) || SPIFFS.exists(path)) {
    if (SPIFFS.exists(pathWithGz))
      path += ".gz";
    File file = SPIFFS.open(path, "r");
    size_t sent = server.streamFile(file, contentType);
    file.close();
    return true;
  }
  return false;
}

void handleFileUpload() {
  if (server.uri() != "/edit") return;
  HTTPUpload& upload = server.upload();
  if (upload.status == UPLOAD_FILE_START) {
    String filename = upload.filename;
    if (!filename.startsWith("/")) filename = "/" + filename;
    fsUploadFile = SPIFFS.open(filename, "w");
    filename = String();
  } else if (upload.status == UPLOAD_FILE_WRITE) {
    //DBG_OUTPUT_PORT.print("handleFileUpload Data: "); DBG_OUTPUT_PORT.println(upload.currentSize);
    if (fsUploadFile)
      fsUploadFile.write(upload.buf, upload.currentSize);
  } else if (upload.status == UPLOAD_FILE_END) {
    if (fsUploadFile)
      fsUploadFile.close();
  }
}

void handleFileDelete() {
  if (server.args() == 0) return server.send(500, "text/plain", "BAD ARGS");
  String path = server.arg(0);
  if (path == "/")
    return server.send(500, "text/plain", "BAD PATH");
  if (!SPIFFS.exists(path))
    return server.send(404, "text/plain", "FileNotFound");
  SPIFFS.remove(path);
  server.send(200, "text/plain", "");
  path = String();
}

void handleFileCreate() {
  if (server.args() == 0)
    return server.send(500, "text/plain", "BAD ARGS");
  String path = server.arg(0);
  if (path == "/")
    return server.send(500, "text/plain", "BAD PATH");
  if (SPIFFS.exists(path))
    return server.send(500, "text/plain", "FILE EXISTS");
  File file = SPIFFS.open(path, "w");
  if (file)
    file.close();
  else
    return server.send(500, "text/plain", "CREATE FAILED");
  server.send(200, "text/plain", "");
  path = String();

}

void handleFileList() {
  if (!server.hasArg("dir")) {
    server.send(500, "text/plain", "BAD ARGS");
    return;
  }
  String path = server.arg("dir");
  Dir dir = SPIFFS.openDir(path);
  path = String();
  String output = "[";
  while (dir.next()) {
    File entry = dir.openFile("r");
    if (output != "[") output += ',';
    bool isDir = false;
    output += "{\"type\":\"";
    output += (isDir) ? "dir" : "file";
    output += "\",\"name\":\"";
    output += String(entry.name()).substring(1);
    output += "\"}";
    entry.close();
  }
  output += "]";
  server.send(200, "text/json", output);
}
