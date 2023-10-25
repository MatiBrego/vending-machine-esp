/*
 *  Project vending_machine
 *
 *  hw_actions.cpp
 *      Low level actions in output hardware
 */

#include <Arduino.h>

#include "hw_actions.h"

void
toggle_led_red(void)
{
    digitalWrite(LED_RED, !digitalRead( LED_RED ));
}

void
toggle_led_grn(void)
{
    digitalWrite(LED_GRN, !digitalRead( LED_GRN ));
}

void
set_led_red(int level)
{
    digitalWrite(LED_RED, level != 0);
}

void
set_led_grn(int level)
{
    digitalWrite(LED_GRN, level != 0);
}

void
clear_all_leds(void)
{
    set_led_red(0);
    set_led_grn(0);
}


