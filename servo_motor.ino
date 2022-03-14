#include <Servo.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

Servo servomotor;

int pos = 0; // declared the variable that can hold the servo position

int analogValue = 0;
int mapAnalogValue = 0;

void setup() {
  Serial.begin(9600);
  servomotor.attach(5);

  lcd.begin(16,2);
  lcd.print("Servo pos");
  lcd.setCursor(0,1);
  lcd.print("App");
  delay(300);
}

void loop() {
  analogValue = analogRead(A0);
  mapAnalogValue = map(analogValue, 0, 1023, 0, 180); // transforming the potans' value into servo pos's degree
 

    lcd.print("Servo Motor");
    lcd.clear();
    lcd.print( mapAnalogValue);
    lcd.setCursor(0,1);
    delay(100);

    servomotor.write( mapAnalogValue);
}
