void SDInit(void) {
  Serial.print("\nInitializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed.");
    while(1);
  }
  
  Serial.println("SD card initalized.");
  root = SD.open("/");
  int index = 0;

  while(true) {
    File entry =  root.openNextFile();

    if (!entry) {
      break;
    }
    
    files[index] = entry.name();
    Serial.print(index,DEC);
    Serial.print(" ");
    Serial.println(entry.name());
    
    index++;
    entry.close();
  }

  index = 0;
  
  while(true) {
    if(!files[index]) {
      break;
    }
    Serial.println(files[index]);
    index++;
  }
}

void printDir(File dir) {
  const int lh = 6; // line height
  int index = 0;
  
  if(fileIndex == 0) {
    u8g.drawStr(0,lh,"-");
  }

  while(true) {
    if(!files[index]) {
      break;
    }
    
    int pos_y = (index + 1) * lh;
    
    if(fileIndex == index) {
      u8g.setPrintPos(0,pos_y);
      u8g.print("-");
    }

    u8g.setPrintPos(4,pos_y);
    u8g.println(files[index]);

    index++;
  }
}
