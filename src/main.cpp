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
#include "hw_actions.h"

int board;
Button machineStatus = Button();
Button insertCredit = Button();
Button products[4] = {Button(), Button(), Button(), Button()};

int status = 1;

void
beginButtons(void){
    machineStatus.begin(STATUS_BUTTON);
    insertCredit.begin(CREDIT_BUTTON);
    products[0].begin(ESP_BUTTON);
    products[1].begin(PROTO_BUTTON);
    products[2].begin(LED_BUTTON);
    products[3].begin(PUSHER_BUTTON);
}

void
setup(void)
{
    Serial.begin(BAUD);

    // connect_wifi();

    init_hw();
    beginButtons();
    board = get_board_num();
    printf("Board = %d\n", board);
    // init_mqtt(board);
    // TelnetStream.begin();
}

void
loop(void)
{
    if( machineStatus.debounce() ){
        if(status == 1){
            status = 0;     
        }
        else{
            status = 1;
        }
        toggle_led_grn();
        toggle_led_red();
        // publish_status_change(status);
    }

    if (insertCredit.debounce()){
        // publish_credit_insert_button_pressed(1);
    }
    if(products[0].debounce()){
        // publish_esp_button_pressed();
    }
    if(products[1].debounce()){
        // publish_protoboard_button_pressed();
    }
    if(products[2].debounce()){
        // publish_led_led_button_pressed();
    }
    if(products[3].debounce()){
        // publish_pusher_button_pressed();
    }
    // mqtt_loop();
}


