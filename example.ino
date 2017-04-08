#include <LiquidCrystal.h>
#include <inttypes.h>
#include "BarChars.h"
#include "LiquidCrystalChart.h"


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
BarChars* barChar = new BarChars(lcd);  //defined outside the LiquidCrystalChart if you want to used to chars for another proposes
LiquidCrystalChart* chartBar = new LiquidCrystalChart(lcd, *barChar, 0, 0, 2, 16); //LiquidCrystal, BarChars, Display: posChartX, posChartY, chartHeight, chartBars

void setup()
{
   Serial.begin(9600);
   lcd.begin(16, 2);
}

void loop()
{
  uint8_t samples[16];
  for(uint8_t i=0; i<16; ++i)
  {
    samples[i]= i * i;
  }
  chartBar->plotChart(samples);
}
