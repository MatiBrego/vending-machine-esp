#ifndef button_h
#define button_h

#include "Arduino.h"

class Button
{
  private:
    uint8_t btn;
    uint16_t state;
    int buttonState;                     // current reading from the input pin (pushbutton)
    int lastButtonState = HIGH;          // previous reading from the input pin (pushbutton)
    unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
    unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers

  public:
    void begin(uint8_t button)
    {
        btn = button;
        state = false;
        pinMode(btn, INPUT_PULLUP);
    }
    bool debounce()
    {
        int reading, result;

        result = 0;
        reading = digitalRead(btn);                        // Now read the button state

        if (reading != lastButtonState)                     // If the pushbutton state changed (due to noise or pressing it), then ....
            lastDebounceTime = millis();                    // ... reset the debouncing timer
        else
        if ((millis() - lastDebounceTime) > debounceDelay)  // If the pin_button state has changed, after the debounce time
        {
            if (reading != buttonState)                     // And if the current reading is different than the current buttonState
            {
                buttonState = reading;
                if (buttonState == LOW)
                    result = 1;
            }
        }
        lastButtonState = reading;                          // Save the reading. Next time through the loop, it'll be the lastButtonState
        return result;
    }
};

#endif
