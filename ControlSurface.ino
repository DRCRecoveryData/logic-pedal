#include <Control_Surface.h>

const pin_t buttonPins[] = {2, 3, 4, 5, 6, 7};
const pin_t ledPins[] = {8, 9, 10, 11, 12, 13};

const char* buttonNames[] = {"Undo", "Redo", "Record", "Play", "Left Arrow", "Right Arrow"};

USBMIDI_Interface midi;

// Callback function for button presses
void buttonBlink(const Button &btn) {
  int index = &btn - buttons;
  Serial.print(buttonNames[index]);
  Serial.println(" button pressed");
}

// Callback function for LED status
void ledBlink(const NoteValueLED &led) {
  int index = &led - leds;
  Serial.print(buttonNames[index]);
  Serial.print(" LED ");
  Serial.println(led.getState() ? "ON" : "OFF");
}

// Mackie Control messages for transport and edit functions
MCU::Button mackieControlButtons[] = {
  MCU::Button::UNDO,
  MCU::Button::REDO,
  MCU::Button::RECORD,
  MCU::Button::PLAY,
  MCU::Button::F1, // Left Arrow
  MCU::Button::F2  // Right Arrow
};

MCUButton buttons[] = {
  {buttonPins[0], mackieControlButtons[0], midi, buttonBlink},
  {buttonPins[1], mackieControlButtons[1], midi, buttonBlink},
  {buttonPins[2], mackieControlButtons[2], midi, buttonBlink},
  {buttonPins[3], mackieControlButtons[3], midi, buttonBlink},
  {buttonPins[4], mackieControlButtons[4], midi, buttonBlink},
  {buttonPins[5], mackieControlButtons[5], midi, buttonBlink},
};

NoteValueLED leds[] = {
  {ledPins[0], {0x45, CHANNEL_1}, ledBlink},
  {ledPins[1], {0x46, CHANNEL_1}, ledBlink},
  {ledPins[2], {0x10, CHANNEL_1}, ledBlink},
  {ledPins[3], {0x13, CHANNEL_1}, ledBlink},
  {ledPins[4], {0x2E, CHANNEL_1}, ledBlink},
  {ledPins[5], {0x2F, CHANNEL_1}, ledBlink},
};

void setup() {
  Serial.begin(9600);
  Control_Surface.begin();
}

void loop() {
  Control_Surface.loop();
}
