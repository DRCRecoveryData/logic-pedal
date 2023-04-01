#include <Control_Surface.h>
#include <FastLED.h>

const pin_t buttonPins[] = {2, 3, 4, 5, 6, 7};
const uint8_t numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

const char* buttonNames[] = {"Undo", "Redo", "Record", "Play", "Left Arrow", "Right Arrow"};

USBMIDI_Interface midi;

MCU::Button mackieControlButtons[] = {
  MCU::Button::UNDO,
  MCU::Button::REDO,
  MCU::Button::RECORD,
  MCU::Button::PLAY,
  MCU::Button::F1, // Left Arrow
  MCU::Button::F2  // Right Arrow
};

MCUButton buttons[] = {
  {buttonPins[0], mackieControlButtons[0], midi},
  {buttonPins[1], mackieControlButtons[1], midi},
  {buttonPins[2], mackieControlButtons[2], midi},
  {buttonPins[3], mackieControlButtons[3], midi},
  {buttonPins[4], mackieControlButtons[4], midi},
  {buttonPins[5], mackieControlButtons[5], midi},
};

const uint8_t numLeds = numButtons;
const uint8_t dataPin = 8;
CRGB leds[numLeds];

void setup() {
  Serial.begin(9600);
  Control_Surface.begin();

  FastLED.addLeds<WS2812B, dataPin, GRB>(leds, numLeds);
  FastLED.setBrightness(64);

  powerUpEffect();
}

void loop() {
  Control_Surface.loop();

  for (uint8_t i = 0; i < numButtons; i++) {
    if (buttons[i].getState() == Button::Falling) {
      Serial.print(buttonNames[i]);
      Serial.println(" button pressed");
      leds[i] = CRGB::Green;
    } else if (buttons[i].getState() == Button::Rising) {
      leds[i] = CRGB::Black;
    }
  }

  FastLED.show();
}

void powerUpEffect() {
  for (uint8_t i = 0; i < numLeds; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(100);
  }
  delay(500);

  for (uint8_t i = 0; i < numLeds; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(100);
  }
}
