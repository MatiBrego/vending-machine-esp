/*
 *  Project Vending-Machine
 *
 *  mqqt_sending_actions.cpp
 *      Actions called as events from the esp32 need to be published
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

static int esp_id = 1;
static int protoboard_id = 2;
static int led_id = 3;
static int pusher_id = 4;

static int board_num = get_board_num();

void publish_esp_button_pressed(){
    char topic[100];
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char msg[100];
    sprintf(msg,"{\"productId\": %d, \"machineId\": %d}", esp_id, board_num);
    do_publish(topic, msg);
}

void publish_protoboard_button_pressed(){
    char topic[100];
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char msg[100];
    sprintf(msg,"{\"productId\": %d, \"machineId\": %d}", protoboard_id, board_num);
    do_publish(topic, msg);
}
void publish_led_led_button_pressed(){
    char topic[100];
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char msg[100];
    sprintf(msg,"{\"productId\": %d, \"machineId\": %d}", led_id, board_num);
    do_publish(topic, msg);
}
void publish_pusher_button_pressed(){
    char topic[100];
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char msg[100];
    sprintf(msg,"{\"productId\": %d, \"machineId\": %d}", pusher_id, board_num);
    do_publish(topic, msg);
}

void publish_credit_insert_button_pressed(int increment){
    char topic[100];
    sprintf(topic,"%s", credit_subtopic);

    char msg[100];
    sprintf(msg,"{\"increment\": %d, \"machineId\": %d}", increment, board_num);
    do_publish(topic, msg);
}

void publish_status_change(int status){
    char topic[100];
    sprintf(topic,"%s", status_subtopic);

    char msg[100];
    sprintf(msg,"{\"status\": %d, \"machineId\": %d}", status, board_num);

    do_publish(topic, msg);
}

void publish_stock_refill(int max_amount){
    char topic[100];
    sprintf(topic,"%s", stock_subtopic);

    char msg[100];
    Serial.printf(msg);
    sprintf(msg,"{\"machineId\": %d, \"stock\": %d}", board_num, max_amount);
    do_publish(topic, msg);
}

