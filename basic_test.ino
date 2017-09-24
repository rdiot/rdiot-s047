/* Hall Magnetic Sensor Module (KY-003) [S047] : http://rdiot.tistory.com/93 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int pin = A0;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(pin,INPUT);
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S047:Hall Magnetic");
 
  int val = analogRead(pin);
 
  lcd.setCursor(0,1);
  lcd.print("val=" + (String)val + "  ");
 
  if(val>=750)
  {
    lcd.setCursor(0,2);
    lcd.print("nomally >= 750      ");    
  }
  else
  {
    lcd.setCursor(0,2);
    lcd.print("detected : under 100");    
 
  } 
  delay(200); 
}
