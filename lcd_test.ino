// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int buttonVal;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("asher is great");
  lcd.setCursor(0,1);
  lcd.print("push the button");
}

void loop()
{
  int iAnReading;
  iAnReading=analogRead(0);
  Serial.println(iAnReading);
  if (buttonVal != iAnReading) {
    if (iAnReading == 410) {
      lcd.setCursor(0,1);
      lcd.print("enjoy!          ");
    }
    else {
      lcd.setCursor(0,1);
      lcd.print("Val: ");
      lcd.print(iAnReading);
      lcd.print("hi hi hi     ");
    }
    buttonVal = iAnReading;
  }
}
