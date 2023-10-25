/*
 *  Project 41-mqtt_00 - Austral - EAM
 *
 *  hw.cpp
 *      Hardware dependent code
 */

#include <Arduino.h>

#include "hw.h"

int buttons[6] = {STATUS_BUTTON, CREDIT_BUTTON, ESP_BUTTON, PROTO_BUTTON, LED_BUTTON, PUSHER_BUTTON};

/*
 *  Public functions
 */

/*
 *  get_board_num
 *      Return board number read from IB1,IB0
 */


int
get_board_num(void)
{
    return digitalRead(IB0) | (digitalRead(IB1) << 1); 
}

/*
 *  init_hw
 *      Called at power up
 */

void
init_hw()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GRN, OUTPUT);

    digitalWrite(LED_RED,LOW);
    digitalWrite(LED_GRN,HIGH);

    // pinMode(IB0,INPUT_PULLUP);
    // pinMode(IB1,INPUT_PULLUP);
}

/*
 *  verify_push:
 *      verifies if tact pushbotton has closed
 *      returns boolean on closure
 */

bool
verify_push(Button btn)
{
    bool result = btn.debounce();
    if(result){
        Serial.printf("Button %d" , result);
    }
    return result;
}

