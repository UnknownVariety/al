#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;     //M1 Direction Control

void setup(){ 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("asher is great");
  lcd.setCursor(0,1);
  lcd.print("push the button");
}

void loop(){
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

  /*
  carAdvance(100,100);
  delay(1000);
  carBack(100,100);
  delay(1000);
  carTurnLeft(250,250);
  delay(1000);
  carTurnRight(250,250);
  delay(1000);
  */
}

void carStop(){                 //  Motor Stop
  digitalWrite(speedPin_M2,0); 
  digitalWrite(directionPin_M1,LOW);    
  digitalWrite(speedPin_M1,0);   
  digitalWrite(directionPin_M2,LOW);    
}   

void carTurnLeft(int leftSpeed,int rightSpeed){         //Turn Left
  analogWrite (speedPin_M2,leftSpeed);              //PWM Speed Control
  digitalWrite(directionPin_M1,HIGH);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,HIGH);
} 

void carTurnRight(int leftSpeed,int rightSpeed){       //Turn Right
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,LOW);   
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,LOW);
}

void carBack(int leftSpeed,int rightSpeed){             //Move backward
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,LOW);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,HIGH);
}
void carAdvance(int leftSpeed,int rightSpeed){           //Move forward
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,HIGH);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,LOW);
}








