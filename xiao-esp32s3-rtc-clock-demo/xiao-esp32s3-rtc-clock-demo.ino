#include <Arduino.h>
#include <Wire.h>
#include <U8x8lib.h>
#include <PCF8563.h>

PCF8563 pcf;
U8X8_SSD1306_128X64_NONAME_HW_I2C oled(U8X8_PIN_NONE);

void setup() {
  Wire.begin(SDA, SCL);

  oled.begin();
  oled.setPowerSave(0);
  oled.setFlipMode(1);
  oled.setFont(u8x8_font_chroma48medium8_r);
  oled.clearDisplay();
  oled.drawString(0,0,"Starting");

  // DO NOT CALL pcf.init();

  // Set clock once if needed:
  /*
  pcf.stopClock();
  pcf.setYear(26);
  pcf.setMonth(4);
  pcf.setDay(29);
  pcf.setHour(15);
  pcf.setMinut(30);
  pcf.setSecond(0);
  pcf.startClock();
  */
}

void loop() {
  Time t = pcf.getTime();

  char line1[20];
  char line2[20];

  sprintf(line1,"%02d/%02d/20%02d",t.day,t.month,t.year);
  sprintf(line2,"%02d:%02d:%02d",t.hour,t.minute,t.second);

  oled.clearDisplay();
  oled.drawString(0,0,line1);
  oled.drawString(0,1,line2);

  delay(1000);
}