/*
 * Ultrasonic.h
 *
 * Created: 30/01/2020 04:51:36 ص
 *  Author: TOSHIBA
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "Ultrasonic_Config.h"

#include "SwICU.h"
void US_Init(void);
/*
void US_Init(uint8_t EN_TRIGGER_PORT,uint8_t EN_TRIGGER_PIN,uint8_t EN_ECHO_PORT,uint8_t EN_ECHO_PIN);
*/
void US_Trigger(void);

uint16_t US_Reading_Polling(void);

uint16_t US_Reading_INT(void);



#endif /* ULTRASONIC_H_ */