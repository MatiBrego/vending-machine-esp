/*  Project Vending-Machine
 *   
 *  vending_actions.cpp
 *      Handle buying, credit, refill and start upate actions.
 */

#include "hw_actions.h"
#include <Arduino.h>
#include "mqqt_sending_actions.h"

int status = 1;
int credit = 0;
int max_stock = 5;

int esp_price       = 4;
int proto_price     = 3;
int led_price       = 1;
int pusher_price    = 1;

int esp_stock       = max_stock;
int proto_stock     = max_stock;
int led_stock       = max_stock;
int pusher_stock    = max_stock;

void print_actual_state(){
    if (status){
        Serial.println("+----------------------------------------------------------+");
        Serial.println("|                        VENDING MACHINE                   |");
        Serial.println("+---------------------+------------------+-----------------+");
        Serial.println("|       PRODUCT       |      STOCK       |        PRICE    |");
        Serial.println("+---------------------+------------------+-----------------+");

        Serial.printf("| ESP Chip            | %16d | $%14d |\n", esp_stock, esp_price);
        Serial.printf("| Protoboard          | %16d | $%14d |\n", proto_stock, proto_price);
        Serial.printf("| Led diode           | %16d | $%14d |\n", led_stock, led_price);
        Serial.printf("| Button              | %16d | $%14d |\n", pusher_stock, pusher_price);
        Serial.println("+----------------------------------------------------------+");
        Serial.printf("| Credit:             | $                  %15d |\n", credit);
        Serial.println("+----------------------------------------------------------+");
    }else {
        Serial.println("+----------------------------------------------------------+");
        Serial.println("|                        VENDING MACHINE                   |");
        Serial.println("+----------------------------------------------------------+");
        Serial.println("|                                                          |");
        Serial.println("|                                                          |");
        Serial.println("|                                                          |");
        Serial.println("|                        OUT OF SERVICE                    |");
        Serial.println("|                                                          |");
        Serial.println("|                                                          |");
        Serial.println("|                                                          |");
        Serial.println("|                                                          |");
        Serial.println("+----------------------------------------------------------+");
    }

    
}

void toggle_status(){
    if(status){
        status = 0;     
    }
    else{
        status = 1;
    }
    toggle_led_grn();
    toggle_led_red();
    publish_status_change(status);
}

void insert_credit(){
    if(status){
        credit += 1;
        publish_credit_insert_button_pressed(1);
    }
}

bool check_credit(int price){
    return credit >= price;
}

bool check_stock(int stock){
    return stock > 0;
}

void buy_esp(){
    if (check_credit(esp_price) && check_stock(esp_stock) && status){
            credit -= esp_price;
            esp_stock -= 1;
            publish_esp_button_pressed();
    }
}
void buy_proto(){
    if (check_credit(proto_price) && check_stock(proto_stock) && status){
            credit -= proto_price;
            proto_stock -= 1;
            publish_protoboard_button_pressed();
    }
}
void buy_led(){
    if (check_credit(led_price) && check_stock(led_stock) && status){
            credit -= led_price;
            led_stock -= 1;
            publish_led_led_button_pressed();
    }
}
void buy_pusher(){
    if (check_credit(pusher_price) && check_stock(pusher_stock) && status){
            credit -= pusher_price;
            pusher_stock -= 1;
            publish_pusher_button_pressed();
    }
}

void refill_stock(){
    esp_stock       = max_stock;
    proto_stock     = max_stock;
    led_stock       = max_stock;
    pusher_stock    = max_stock;
    publish_stock_refill(max_stock);
}

void update_values(int origin, char *msg){
    Serial.print("\n\nStarting Machine\n\n");
    char *token = strtok(msg, ",");
    credit = atoi(token);
    token = strtok(NULL, ",");
    esp_stock = atoi(token);
    token = strtok(NULL, ",");
    proto_stock = atoi(token);
    token = strtok(NULL, ",");
    led_stock = atoi(token);
    token = strtok(NULL, ",");
    pusher_stock = atoi(token);
    print_actual_state();
}
