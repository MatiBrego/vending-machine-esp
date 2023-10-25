/*
 *  Project 41-mqtt_00 - Austral - EAM
 *
 *  mqtt_actions.h
 *      Actions called as suscribed topics are received
 */

void clear_leds( int org, char *msg );

void toggle_red( int org, char *msg );
void toggle_grn( int org, char *msg );

void set_red(int org, char *msg);
void set_grn(int org, char *msg);
