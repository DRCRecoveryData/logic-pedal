#include <Keyboard.h>

const int undoPin = 2; // the pin connected to the undo button
const int redoPin = 3; // the pin connected to the redo button
const int recPin = 4; // the pin connected to the rec button
const int playPin = 5; // the pin connected to the play button
const int leftPin = 6; // the pin connected to the left button
const int rightPin = 7; // the pin connected to the right button

const int undoLed = 8;
const int redoLed = 9;
const int recLed = 10;
const int playLed = 11;
const int leftLed = 12;
const int rightLed = 13;

void setup() {
  pinMode(undoPin, INPUT_PULLUP);
  pinMode(redoPin, INPUT_PULLUP);
  pinMode(recPin, INPUT_PULLUP);
  pinMode(playPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);

  pinMode(undoLed, OUTPUT);
  pinMode(redoLed, OUTPUT);
  pinMode(recLed, OUTPUT);
  pinMode(playLed, OUTPUT);
  pinMode(leftLed, OUTPUT);
  pinMode(rightLed, OUTPUT);
  
  Keyboard.begin();
  
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
}

void loop() {
  // Send undo command
  if (digitalRead(undoPin) == LOW) {
    Serial.println("Undo button pressed");
    digitalWrite(undoLed, HIGH);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('z');
    delay(50);
    Keyboard.releaseAll();
    delay(500);
  } else {
    digitalWrite(undoLed, LOW);
  }

  // Send redo command
  if (digitalRead(redoPin) == LOW) {
    Serial.println("Redo button pressed");
    digitalWrite(redoLed, HIGH);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('z');
    delay(50);
    Keyboard.releaseAll();
    delay(500);
  } else {
    digitalWrite(redoLed, LOW);
  }

  // Send rec command
  if (digitalRead(recPin) == LOW) {
    Serial.println("Rec button pressed");
    digitalWrite(recLed, HIGH);
    Keyboard.write('r');
    delay(500);
  } else {
    digitalWrite(recLed, LOW);
  }

  // Send play command
  if (digitalRead(playPin) == LOW) {
    Serial.println("Play button pressed");
    digitalWrite(playLed, HIGH);
    Keyboard.write(' ');
    delay(500);
  } else {
    digitalWrite(playLed, LOW);
  }

  // Send left command
  if (digitalRead(leftPin) == LOW) {
    Serial.println("Left button pressed");
    digitalWrite(leftLed, HIGH);
    Keyboard.write(KEY_LEFT_ARROW);
    delay(500);
  } else {
    digitalWrite(leftLed, LOW);
  }

  // Send right command
  if (digitalRead(rightPin) == LOW) {
    Serial.println("Right button pressed");
    digitalWrite(rightLed, HIGH);
    Keyboard.write(KEY_RIGHT_ARROW);
    delay(500);
  } else {
    digitalWrite(rightLed, LOW);
  }
}
