/*
 * Project Vending-Machine
 *  mqtt_def.h
 *
 *      This is not a traditional header file
 *      As a matter of fact, it has all the configurations for MQTT in one file
 *      Please, modify it with caution
 */

#ifndef __MQTT_DEF_H__
#define __MQTT_DEF_H__

#include "vending_actions.h"

/*
 *  type definifitions
 */

typedef struct
{
    const char *sub_topic;
    void (*action)( int origin, char *message );
} topic_t;

/*
 *  C1 -> List of topics and actions
 */

static const topic_t topics[] =
{
    {   "machine_init_6550dec96b946ce26bee14c4", update_values },
    {   NULL }
};

/*
 *  C2 -> Subscriptions lists
 *
 *  Only for testing and studying purposes, you can select
 *  between 3 constants defined in platformio.ini
 */

static const char *subs[] =
{
#if (SUB_LIST==0)
    "#",
#elif (SUB_LIST==1)
    "machine_init_6550dec96b946ce26bee14c4",
#elif (SUB_LIST==2)
    "machine_init_6550dec96b946ce26bee14c5"
#else
    #error "Bad SUB_LIST symbol, out of range"
#endif
    NULL
};

/*
 *  C3 -> Macros for id strings
 *      These are macros to define the following strings
 *
 *      id_string:      sub-string to log in broker (must be given the board number)
 *      topic_string:   sub-string to be used in topic publishing (must be given the board number)
 *      subs_string:    sub-string to be used in topic suubscription
 */

#define id_string(buf)      sprintf(buf,"%s",   MAIN_NAME)
#define topic_string(buf)   sprintf(buf,"%s",   MAIN_NAME)
#define subs_string(buf)    sprintf(buf,"%s",   MAIN_NAME)

/*
 *  C4 -> broker selection
 */

#if (MQTT==0)                                       
    #define BROKER_NAME "172.22.42.93"         //  Mosquitto in local network
    #define BROKER_PORT 1883
    #define BROKER_USER ""
    #define BROKER_PASS ""
#elif (MQTT==1)
    #define BROKER_NAME "54.164.78.202"          //  Mosquitto outside local network
    #define BROKER_PORT 1883
    #define BROKER_USER ""
    #define BROKER_PASS ""
#elif (MQTT==2)
    #define BROKER_NAME "broker.mqtt-dashboard.com"    //  Remote broker by name
    #define BROKER_PORT 1883
    #define BROKER_USER ""
    #define BROKER_PASS ""
#else
    #error "Bad MQTT symbol, broker name out of range"
#endif

#endif      //  ends  __MQTT_DEF_H__

