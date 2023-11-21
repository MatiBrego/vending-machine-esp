/*
 *  Project Vending-Machine
 *
 *  mqtt_actions.cpp
 *      Actions called as suscribed topics are received
 *      Low level actions called from here are in 'hw_actions.cpp'
 */

#include <Arduino.h>
#include <TelnetStream.h>

#include "mqtt_actions.h"       //  Prototypes of functions whose code are here
#include "hw_actions.h"         //  Prototypes of functions called from here

extern int board;

void
clear_leds( int origin, char *msg )
{
    TelnetStream.printf("%02d -> %02d |  %s: msg -> %s\n", origin, board, __FUNCTION__, msg );
    clear_all_leds();
}

void
toggle_red( int origin, char *msg )
{
    TelnetStream.printf("%02d -> %02d |  %s: msg -> %s\n", origin, board, __FUNCTION__, msg );
    toggle_led_red();
}

void
toggle_grn( int origin, char *msg )
{
    TelnetStream.printf("%02d -> %02d |  %s: msg -> %s\n", origin, board, __FUNCTION__, msg );
    toggle_led_grn();
}


void
set_red( int origin, char *msg )
{
    TelnetStream.printf("%02d -> %02d |  %s: msg -> %s\n", origin, board, __FUNCTION__, msg );
    set_led_red( msg[0] != '0' );
}

void
set_grn(int origin, char *msg)
{
    Serial.println("set_grn");
    TelnetStream.printf("%02d -> %02d |  %s: msg -> %s\n", origin, board, __FUNCTION__, msg );
    set_led_grn( msg[0] != '0' );
}

void
rx_button( int origin, char *msg )
{
    TelnetStream.printf("%02d -> %02d |  %s: msg -> %s\n", origin, board, __FUNCTION__, msg );
    Serial.printf("%s: msg: %s\n", __FUNCTION__, msg );
}




