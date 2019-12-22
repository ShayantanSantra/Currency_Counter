#define S0 6
#define S1 5
#define S2 4
#define S3 3
#define sensorOut 2
#include <LiquidCrystal.h>





LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Variables
int red = 0;
int green = 0;
int blue = 0;
int Contrast=78;
int twenty=0;
int twohundred=0;
int twothousand=0;
int hundred=0;
int fifty=0;
int total=0;
int fivehundred=0;

int frequency = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  analogWrite(7,Contrast);
  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("Arduino");
  lcd.setCursor(1, 1);
  lcd.print("Color Detector");
  
  Serial.begin(9600);
}
void loop() {
  /*Serial.print("R =");
  Serial.print(red, DEC);
  Serial.print(" G = ");
  Serial.print(green, DEC);
  Serial.print(" B = ");
  Serial.print(blue, DEC);
  Serial.print("\t");*/
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  red= frequency;
  Serial.print("  ");
  delay(130);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  green= frequency;
  Serial.print("  ");
  delay(130);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor  
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  blue= frequency;
  Serial.println("  ");
  delay(130);
  if ((red >= 100 && red <= 110 ) && (green > 100 && green <=120 ) && (blue >= 80 && blue <= 90 ))
    {
      twohundred=200;
      total+=twohundred;
      lcd.clear();  //200 ruppee note of orange color
      lcd.setCursor(0, 0);
      lcd.print("Total:");
      lcd.print(total);
      lcd.setCursor(0, 1);
      lcd.print("Note:");
      lcd.print(twohundred);
      Serial.println(" - (Orange 200)");
      delay(2000);
    }
    else if ((red > 110 && red <=120 ) && (green >=105 && green <=110 ) && (blue >= 70 && blue <= 80 ))
    {
      hundred=100;
      total+=hundred;
      lcd.clear();  //100 ruppee note of orange color
      lcd.setCursor(0, 0);
      lcd.print("Total:");
      lcd.print(total);
      lcd.setCursor(0, 1);
      lcd.print("Note:");
      lcd.print(hundred);
      Serial.println(" - (purple 100)");
      delay(2000);
    }
    else if ((red > 95 && red <=105 ) && (green >= 80 && green <=99 ) && (blue >= 65 && blue <= 75 ))
    {
      //fivehundred=500;
      //total+=fivehundred;
      lcd.clear();  
      lcd.setCursor(0, 0);
      lcd.print("Total:");
      lcd.print(total);
      lcd.setCursor(0, 1);
      lcd.print("End");
      //lcd.print(fivehundred);
      Serial.println("White Color");
      
      delay(1300);
      for(;;);
    }
   else
   {
    lcd.setCursor(0, 0);
    lcd.print("Total:");
    lcd.print(total);
    lcd.setCursor(0, 1);
    lcd.print("No notes detected");
    Serial.println("No notes detected");
   }
}
