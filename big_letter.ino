#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BigFont01_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
BigFont01_I2C big(&lcd);

void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.clear();
lcd.backlight();
big.begin();
delay(1000);
lcd.setCursor(0, 0);
lcd.print("HOLA");
delay(2000);
big.writechar(0, 0, 'H');
big.writechar(0, 3, 'O');
big.writechar(0, 6, 'L');
big.writechar(0, 9, 'A');
delay(2000);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
float potValue = analogRead(A0);
float voltage = potValue*5/1023;
lcd.setCursor(0,0);
lcd.print("Volt");
int parteEnteraVoltage = int(voltage);
float parteDecimalVoltage = voltage -parteEnteraVoltage;
int parteDecimal100 = int (parteDecimalVoltage*100);
big.writeint(0, 4, parteEnteraVoltage, 1, true);
big.writechar(0, 7, '.');
big.writeint(0, 10, parteDecimal100, 2, true);
delay(100);
}
