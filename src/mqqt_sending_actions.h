/*
 *  Project Vending-Machine
 *
 *  mqqt_sending_actions.h
 *      Actions called as events from the esp32 need to be published
 */

void publish_esp_button_pressed();
void publish_protoboard_button_pressed();
void publish_led_led_button_pressed();
void publish_pusher_button_pressed();
void publish_credit_insert_button_pressed(int amount);
void publish_status_change(int status);
void publish_stock_refill(int max_amount);