/*
 *  Project Vending-Machine
 *
 *  mqqt_sending_actions.cpp
 *      Actions called as events from the esp32 that need to be published
 */

#include "mqtt.h"
#include "stdio.h"
#include "Arduino.h"
#include "hw.h"


static const char* stock_subtopic   = "stock";
static const char* status_subtopic  = "status";
static const char* product_subtopic = "product";
static const char* credit_subtopic  = "credit";
static const char* buy_subtopic     = "buy";

char* esp_id = "6550d9a796bc3f713a2fc0ba";
char* protoboard_id = "6550d9a796bc3f713a2fc0ba";
char* led_id = "6550da5696bc3f713a2fc0bc";
char* pusher_id = "6550da5696bc3f713a2fc0bd";

char* board_num = get_board_num();

void publish_esp_button_pressed(){
    char topic[200];
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char msg[200];
    sprintf(msg,"{\"productId\": \"%s\", \"machineId\": \"%s\"}", esp_id, board_num);
    do_publish(topic, msg);
}

void publish_protoboard_button_pressed(){
    char topic[200];
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char msg[200];
    sprintf(msg,"{\"productId\": \"%s\", \"machineId\": \"%s\"}", protoboard_id, board_num);
    do_publish(topic, msg);
}
void publish_led_led_button_pressed(){
    char topic[200];
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char msg[200];
    sprintf(msg,"{\"productId\": \"%s\", \"machineId\": \"%s\"}", led_id, board_num);
    do_publish(topic, msg);
}
void publish_pusher_button_pressed(){
    char topic[200];
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char msg[200];
    sprintf(msg,"{\"productId\": \"%s\", \"machineId\": \"%s\"}", pusher_id, board_num);
    do_publish(topic, msg);
}

void publish_credit_insert_button_pressed(int increment){
    char topic[100];
    sprintf(topic,"%s", credit_subtopic);

    char msg[100];
    sprintf(msg,"{\"increment\": %d, \"machineId\": \"%s\"}", increment, board_num);
    do_publish(topic, msg);
}

void publish_status_change(int status){
    char topic[200];
    sprintf(topic,"%s", status_subtopic);

    char msg[100];
    sprintf(msg,"{\"status\": %d, \"machineId\": \"%s\"}", status, board_num);
    do_publish(topic, msg);
}

void publish_stock_refill(int max_amount){
    char topic[100];
    sprintf(topic,"%s", stock_subtopic);

    char msg[100];
    sprintf(msg,"{\"machineId\": \"%s\", \"stock\": %d}", board_num, max_amount);
    do_publish(topic, msg);
}

