#include <LiquidCrystal.h>
#include <HCSR04.h>

//RGB
#define BLUE 4
#define GREEN 3
#define RED 2
//LCD
#define RS 5
#define Enable 6
#define D4 7
#define D5 8
#define D6 9 
#define D7 10

UltraSonicDistanceSensor  hc(12, 13); //initialisation class HCSR04 (trig pin , echo pin)
LiquidCrystal lcd(RS, Enable, D4, D5, D6, D7);
void setup()
{ 
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  lcd.begin(16, 2);
  Serial.begin(9600); 
}

int redValue;
int greenValue;
int blueValue;
int distance;

void loop()
{

    lcd.clear();
    distance = hc.measureDistanceCm();
    if(distance<25){
      redValue = 255;
      greenValue = 0;
      blueValue = 0;
    }else if(distance<70){
      redValue = 0;
      greenValue = 0;
      blueValue = 255;
    }else {
      redValue = 0;
      greenValue = 255;
      blueValue = 0;
    }
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    String string1 = "Distance is: ";
    String string2 = "centimetres";
    String string3 = string1 + distance;
    lcd.setCursor(0, 0); 
    lcd.print(string3);
    lcd.setCursor(0, 1); 
    lcd.print(string2);
    Serial.println(distance ); 
    delay(100);                   



}
