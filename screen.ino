void updateDisp(void) {
  u8g.drawStr(0,0,"dir:");
  u8g.setPrintPos(16,0);
  u8g.print(root.name());
  u8g.setPrintPos(75,0);
  u8g.print(fileIndex,DEC);
  
  printDir(root);
}

void screenSet(int i) {
  u8g.setColorIndex(i); // pixel on !
  for (int x_axis=0;x_axis<84;x_axis++){
    for (int y_axis=0;y_axis<44;y_axis++){
      u8g.drawPixel(x_axis,y_axis);
    }
  }
}

void screenClear(void) {
  u8g.setFont(u8g_font_04b_03);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}

void screenInit(void) {
  // Display init
  u8g.begin();
  u8g.setFont(u8g_font_u8glib_4);
  screenSet(1);
  u8g.firstPage();
  do {
    screenSet(1);
  } while( u8g.nextPage() );
  
  delay(1000);
  
  u8g.firstPage();
  do {
    screenSet(0);
  } while( u8g.nextPage() );
  
  delay(1000);
  screenClear();
}
