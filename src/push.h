/*
 *  push.h
 */

enum
{
    STATUS_REF, CREDIT, ESP_REF, PROTO, LED, PUSHER, // Status and esp are reserved words, I added REF to make them available.
    NUM_PUSH // Amount of buttons
};


void button_init(void);
int push_done(unsigned which); 