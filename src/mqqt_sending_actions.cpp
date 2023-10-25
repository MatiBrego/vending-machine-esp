/*
 *  Project Vending-Machine
 *
 *  mqqt_sending_actions.cpp
 *      Actions called as events from the esp32 need to be published
 */

#include "mqtt.h"
#include "stdio.h"

static const char* stock_subtopic   = "stock";
static const char* status_subtopic  = "status";
static const char* product_subtopic = "product";
static const char* credit_subtopic  = "credit";
static const char* buy_subtopic     = "buy";

static int esp_id = 1;
static int protoboard_id = 2;
static int led_id = 3;
static int pusher_id = 4;

void publish_esp_button_pressed(){
    char* topic;
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char* msg;
    sprintf(msg,"%d", esp_id);
    do_publish(topic, msg);
}

void publish_protoboard_button_pressed(){
    char* topic;
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char* msg;
    sprintf(msg,"%d", protoboard_id);
    do_publish(topic, msg);
}
void publish_led_led_button_pressed(){
    char* topic;
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char* msg;
    sprintf(msg,"%d", led_id);
    do_publish(topic, msg);
}
void publish_pusher_button_pressed(){
    char* topic;
    sprintf(topic,"%s/%s/%s", stock_subtopic, product_subtopic, buy_subtopic);

    char* msg;
    sprintf(msg,"%d", pusher_id);
    do_publish(topic, msg);
}

void publish_credit_insert_button_pressed(int amount){
    char* topic;
    sprintf(topic,"%s", credit_subtopic);

    char* msg;
    sprintf(msg,"%d", amount);
    do_publish(topic, msg);
}

void publish_status_change(int status){
    char* topic;
    sprintf(topic,"%s", status_subtopic);

    char* msg;
    sprintf(msg,"%d", status);
    do_publish(topic, msg);
}

void publish_stock_refill(int max_amount){
    char* topic;
    sprintf(topic,"%s", stock_subtopic);

    char* esp;
    sprintf(esp, "{'%s':'%s'}", esp_id, max_amount);

    char* protoboard;
    sprintf(protoboard, "{'%s':'%s'}", protoboard_id, max_amount);

    char* led;
    sprintf(led, "{'%s':'%s'}", led_id, max_amount);

    char* pusher;
    sprintf(pusher, "{'%s':'%s'}", pusher_id, max_amount);

    char* msg;
    sprintf(msg,"[%s, %s, %s, %s]", esp, protoboard, led, pusher);
    do_publish(topic, msg);
}