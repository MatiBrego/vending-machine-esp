/*
 *  Project 41-mqtt_00 - Austral - EAM
 *
 *      File main.cpp
 */

#include <Arduino.h>
#include <TelnetStream.h>

// #include "wifi_ruts.h"
// #include "mqtt.h"
#include "hw.h"
#include "mqqt_sending_actions.h"
#include "push.h"
#include "vending_actions.h"

int board;


void
setup(void)
{
    Serial.begin(BAUD);

    // connect_wifi();

    init_hw();

    board = get_board_num();
    printf("Board = %d\n", board);
    // init_mqtt(board);
    // TelnetStream.begin();
}

void
loop(void)
{
    if( push_done(STATUS_REF) ){
        toggle_status();
        // publish_status_change(status);
        print_actual_state();
    }

    if (push_done(CREDIT)){
        insert_credit();
        // publish_credit_insert_button_pressed(1);
        print_actual_state();
    }
    if(push_done(ESP_REF)){
        buy_esp();
        // publish_esp_button_pressed();
        print_actual_state();
    }
    if(push_done(PROTO)){
        buy_proto();
        // publish_protoboard_button_pressed();
        print_actual_state();
    }
    if(push_done(LED)){
        buy_led();
        // publish_led_led_button_pressed();
        print_actual_state();
    }
    if(push_done(PUSHER)){
        buy_pusher();
        // publish_pusher_button_pressed();
        print_actual_state();
    }
    // mqtt_loop();
}


