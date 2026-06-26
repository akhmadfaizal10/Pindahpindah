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
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

// Array Piksel Karakter Kustom (8 Slot CGRAM)
byte customChars[8][8] = {
  { B11111, B11111, B00000, B00000, B00000, B00000, B00000, B00000 }, // 0: Blok Atas
  { B00000, B00000, B00000, B00000, B00000, B00000, B11111, B11111 }, // 1: Blok Bawah
  { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 }, // 2: Blok Penuh
  { B11100, B11100, B11100, B11100, B11100, B11100, B11100, B11100 }, // 3: Blok Kiri
  { B00111, B00111, B00111, B00111, B00111, B00111, B00111, B00111 }, // 4: Blok Kanan
  { B11111, B11111, B11100, B11100, B11100, B11100, B11100, B11100 }, // 5: Sudut Kiri Atas
  { B11111, B11111, B00111, B00111, B00111, B00111, B00111, B00111 }, // 6: Sudut Kanan Atas
  { B11111, B11111, B11111, B00000, B00000, B00000, B00000, B00000 }  // 7: Strip Tengah
};

void setup() {
  lcd.init();
  lcd.backlight();
  
  // Daftarkan semua karakter kustom ke LCD
  for (int i = 0; i < 8; i++) {
    lcd.createChar(i, customChars[i]);
  }
  
  lcd.clear();
  
  // Menampilkan "H = 30" di Baris 0 & 1 (Awal Kolom 0)
  printBigH(0);     // 'H' di kolom 0
  printBigEqual(4); // '=' di kolom 4
  printBig3(8);     // '3' di kolom 8
  printBig0(12);    // '0' di kolom 12
}

void loop() {
  // Kosong
}

// --- FUNGSI UNTUK MENCETAK DENGAN TINGGI 2 BARIS ---

void printBigH(int col) {
  lcd.setCursor(col, 0); lcd.write(2); lcd.write(1); lcd.write(2); // Baris Atas
  lcd.setCursor(col, 1); lcd.write(2); lcd.write(0); lcd.write(2); // Baris Bawah
}

void printBigEqual(int col) {
  lcd.setCursor(col, 0); lcd.print(" "); lcd.write(1); lcd.print(" "); // Baris Atas
  lcd.setCursor(col, 1); lcd.print(" "); lcd.write(0); lcd.print(" "); // Baris Bawah
}

void printBig3(int col) {
  lcd.setCursor(col, 0); lcd.write(0); lcd.write(7); lcd.write(6); // Baris Atas
  lcd.setCursor(col, 1); lcd.write(1); lcd.write(1); lcd.write(2); // Baris Bawah
}

void printBig0(int col) {
  lcd.setCursor(col, 0); lcd.write(5); lcd.write(0); lcd.write(6); // Baris Atas
  lcd.setCursor(col, 1); lcd.write(2); lcd.print(" "); lcd.write(2); // Baris Bawah
}
