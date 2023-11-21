/*
 *  Project Vending-Machine
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
char* get_board_num(void);    //  return board number
bool verify_push(Button btn);        //  Verifies all input hardware
