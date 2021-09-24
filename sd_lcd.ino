/**
 * Arduino SD Card reader with LCD Display
 * 
 * The circuit:
 *   SD card attached to SPI bus as follows:
 *   MOSI  - pin 11
 *   MISO  - pin 12
 *   CLK   - pin 13
 *   CS    - depends on your SD card shield or module.
 *   
 *   LCD Screen
 *   RST   - pin 9 - Reset
 *   CE    - pin 8 - CS
 *   DC    - pin 7 - A0
 *   DIN   - pin 6 - MOSI
 *   CLK   - pin 5 - SCK
 *   VCC   - V3.3 pin - VCC
 *   LED   - goes to GND
 *   GND   - ground pin
 *   
 */

// include the libraries:
#include <SD.h>
#include <U8glib.h>

//#include <MUIU8g2.h>
//#include <U8g2lib.h>
//#include <U8x8lib.h>

File root;

// config display
//U8G2_PCD8544_84X48_1_4W_SW_SPI u8g(U8G2_R0,5,6,8,7,9);
U8GLIB_PCD8544 u8g(5,6,8,7,9);

// config buttons pin
const int btn1 = 4;
const int btn2 = 3;
const int btn3 = 2;

int btn1LastState = HIGH;
int btn2LastState = HIGH;
int btn3LastState = HIGH;

int btn1State;
int btn2State;
int btn3State;

int fileIndex = 0;

String files[40];

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Serial connected");

  SDInit();
  screenInit();

  // buttons init
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
}

void loop() {
  checkButtons();
  // picture loop
  u8g.firstPage();
  do {
    updateDisp();
  } while( u8g.nextPage() );
}
