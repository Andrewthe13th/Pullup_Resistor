#include <Arduino.h>

const int ROW_SIZE = 3;
const int COLUMN_SIZE = 2;

int ROW_PINS[ROW_SIZE] = {2,3,4};
int COLUMN_PINS[COLUMN_SIZE] = {8,9};

void setup() {
  // set serial output
  Serial.begin(9600);

  // setting row pins
  for (int i = 0; i < ROW_SIZE; i++)
  {
    pinMode(ROW_PINS[i],INPUT_PULLUP);
  }

  // set column pins
  for (int j = 0; j < COLUMN_SIZE; j++)
  {
    pinMode(COLUMN_PINS[j],OUTPUT);
    digitalWrite(COLUMN_PINS[j],HIGH);
  }
}

void loop() {

  for (int i = 0; i < COLUMN_SIZE; i++)
  {
    if (i==0)
    {
      digitalWrite(COLUMN_PINS[0],LOW);
      digitalWrite(COLUMN_PINS[1],HIGH);
    }
    else
    {
      digitalWrite(COLUMN_PINS[1],LOW);
      digitalWrite(COLUMN_PINS[0],HIGH);
    }

    if(digitalRead(ROW_PINS[0]) == 0 && digitalRead(COLUMN_PINS[0]) == 0)
      Serial.println("Button 1 pressed");
    else if(digitalRead(ROW_PINS[1]) == 0 && digitalRead(COLUMN_PINS[0]) == 0)
      Serial.println("Button 2 pressed");
    else if(digitalRead(ROW_PINS[2]) == 0 && digitalRead(COLUMN_PINS[0]) == 0)
      Serial.println("Button 3 pressed");
    else if(digitalRead(ROW_PINS[0]) == 0 && digitalRead(COLUMN_PINS[1]) == 0)
      Serial.println("Button 4 pressed");
    else if(digitalRead(ROW_PINS[1]) == 0 && digitalRead(COLUMN_PINS[1]) == 0)
      Serial.println("Button 5 pressed");
    else if(digitalRead(ROW_PINS[2]) == 0 && digitalRead(COLUMN_PINS[1]) == 0)
      Serial.println("Button 6 pressed");

  }
  

  // Serial.print("R1: ");
  // Serial.print(digitalRead(ROW_PINS[0]));
  // Serial.print("  R2: ");
  // Serial.print(digitalRead(ROW_PINS[1]));
  // Serial.print("  R3: ");
  // Serial.print(digitalRead(ROW_PINS[2]));

  // Serial.print("  C1: ");
  // Serial.print(digitalRead(COLUMN_PINS[0]));
  // Serial.print("  C2: ");
  // Serial.println(digitalRead(COLUMN_PINS[1]));
}
