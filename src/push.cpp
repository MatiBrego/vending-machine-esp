/*
 *  Project Vending-Machine

 *   push.cpp
 *      Initialize buttons and handle push.
 */

#include "push.h"

#include "button.h"

static const unsigned pin[NUM_PUSH] = { 
    STATUS_BUTTON, 
    CREDIT_BUTTON, 
    ESP_BUTTON, 
    PROTO_BUTTON,
    LED_BUTTON,
    PUSHER_BUTTON,
    STOCK_BUTTON
    };

Button btns[NUM_PUSH];

void
button_init(void)
{
    int i;
    unsigned const *p;

    for( i = 0, p = pin; i < NUM_PUSH; ++i )
        btns[i].begin(*p++);
}

int
push_done(unsigned which)
{
    if(which >= NUM_PUSH)       //  Verify that index is in array
        return 0;               //  Do nothing case in error

    return btns[which].debounce();
}