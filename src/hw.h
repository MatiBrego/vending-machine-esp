/*
 *  Project 41-mqtt_00 - Austral - EAM
 *
 *  hw.h
 *      Hardware dependent code
 */
#include "button.h"

enum
{
    NOHW, BUTTON,
    NUM_NEWS
};

void init_hw();         //  Called at power up
int get_board_num(void);    //  return board number
bool verify_push(Button btn);        //  Verifies all input hardware
