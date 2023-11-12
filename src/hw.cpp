/*
 *  Project 41-mqtt_00 - Austral - EAM
 *
 *  hw.cpp
 *      Hardware dependent code
 */

#include <Arduino.h>

#include "hw.h"
#include "push.h"

/*
 *  Public functions
 */

/*
 *  get_board_num
 *      Return board number read from IB1,IB0
 */



char* get_board_num(void)
{
    return BOARD_NUM; 
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

    button_init();

    // pinMode(IB0,INPUT_PULLUP);
    // pinMode(IB1,INPUT_PULLUP);
}

