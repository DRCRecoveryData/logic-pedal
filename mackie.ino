#include <MIDI_Controller.h>
#include <MIDIUSB.h>

const int buttonPins[] = {2, 3, 4, 5, 6, 7};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);
const int ledPins[] = {8, 9, 10, 11, 12, 13};

byte mackieControlMessages[][3] = {
  {0xB0, 0x45, 0x00}, // Undo
  {0xB0, 0x46, 0x00}, // Redo
  {0xB0, 0x10, 0x00}, // Record
  {0xB0, 0x13, 0x00}, // Play
  {0xB0, 0x2E, 0x00}, // Left Arrow
  {0xB0, 0x2F, 0x00}  // Right Arrow
};

const char* buttonNames[] = {"Undo", "Redo", "Record", "Play", "Left Arrow", "Right Arrow"};

void setup() {
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < numButtons; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      digitalWrite(ledPins[i], HIGH);
      sendMackieControlMessage(i);
      Serial.print(buttonNames[i]);
      Serial.println(" button pressed");
      delay(200);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void sendMackieControlMessage(int index) {
  midiEventPacket_t midiEvent = {0x0B, mackieControlMessages[index][0], mackieControlMessages[index][1], mackieControlMessages[index][2]};
  MidiUSB.sendMIDI(midiEvent);
  MidiUSB.flush();
}
