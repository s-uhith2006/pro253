#include <Arduino.h>


const int button1Pin = 4; 
const int button2Pin = 22; 


int button1State = LOW;
int button2State = LOW;

int selectedNumber = 0;

void setup() {

  Serial.begin(115200);


  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
}

void loop() {
  int newButton1State = digitalRead(button1Pin);


  if (newButton1State != button1State) {
    delay(50); 
    newButton1State = digitalRead(button1Pin);

    if (newButton1State == LOW) {
      selectedNumber++;
      Serial.print("Selected number: ");
      Serial.println(selectedNumber);
    }
  }


  button1State = newButton1State;

  int newButton2State = digitalRead(button2Pin);

  if (newButton2State != button2State) {
    delay(50); 
    newButton2State = digitalRead(button2Pin);

    if (newButton2State == LOW) {
      Serial.println("Printing table for selected number:");
      for (int i = 1; i <= 10; i++) {
        Serial.print(selectedNumber);
        Serial.print(" x ");
        Serial.print(i);
        Serial.print(" = ");
        Serial.println(selectedNumber * i);
      }
      selectedNumber = 0;
    }
  }
  
  button2State = newButton2State;
}
