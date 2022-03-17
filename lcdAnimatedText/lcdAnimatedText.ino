#include <LiquidCrystal.h>

LiquidCrystal lcd(1 ,2, 4, 5, 6, 7);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  coolText(0,0, "Hello World!");
  delay(2000);

  coolText(1,5, "-Arduino");
  delay(5000);
  lcd.clear();

}

void coolText(int col, int row, String msg){ 
  if(col + msg.length() >= 16){
    Serial.print("Error: Message too big to display");
  }
  
  lcd.setCursor(col, row);
  lcd.blink();
  delay(500);
  col += 1;
  
  for(int i = 0; i < msg.length(); i++){
    lcd.print(msg.charAt(i));
    lcd.setCursor(col + i, row);
    delay(75);
  }
  
}
