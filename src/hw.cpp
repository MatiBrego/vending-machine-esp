/*
 *  Project Vending-Machine
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
}

