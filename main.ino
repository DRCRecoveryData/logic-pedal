#include <Keyboard.h>

const int undoPin = 2; // the pin connected to the undo button
const int redoPin = 3; // the pin connected to the redo button
const int recPin = 4; // the pin connected to the rec button
const int playPin = 5; // the pin connected to the play button
const int leftPin = 6; // the pin connected to the left button
const int rightPin = 7; // the pin connected to the right button

void setup() {
  pinMode(undoPin, INPUT_PULLUP);
  pinMode(redoPin, INPUT_PULLUP);
  pinMode(recPin, INPUT_PULLUP);
  pinMode(playPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);
  
  Keyboard.begin();
}

void loop() {
  // Send undo command
  if (digitalRead(undoPin) == LOW) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('z');
    delay(50);
    Keyboard.releaseAll();
    delay(500);
  }

  // Send redo command
  if (digitalRead(redoPin) == LOW) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('z');
    delay(50);
    Keyboard.releaseAll();
    delay(500);
  }

  // Send rec command
  if (digitalRead(recPin) == LOW) {
    Keyboard.write('r');
    delay(500);
  }

  // Send play command
  if (digitalRead(playPin) == LOW) {
    Keyboard.write(' ');
    delay(500);
  }

  // Send left command
  if (digitalRead(leftPin) == LOW) {
    Keyboard.write(KEY_LEFT_ARROW);
    delay(500);
  }

  // Send right command
  if (digitalRead(rightPin) == LOW) {
    Keyboard.write(KEY_RIGHT_ARROW);
    delay(500);
  }
}
