/*
 * MotorDC.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Sprints
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "dcMotorConfig.h"
#include "timers.h"

typedef enum En_motorType_t{
	MOT_1,
	MOT_2
}En_motorType_t;

typedef enum En_motorDir_t{
	STOP,
	FORWARD,
	BACKWARD
}En_motorDir_t;

/**
 * Description: Initialize the MOT_x (where x  1, 2)  H_bridge pins as output
 * @param MOT_id: The Motor to be initialized and it takes
 * 				  one of the enum (En_motorType_t) parameters
 *
 */
void MotorDC_Init(En_motorType_t en_motor_number);

/**
 * Description: Change the MOT_x state (where x  1, 2) to be one of the state  
 *                ( stop,forword,backword)
 * @param Mot_id: The motor to determent it's direction  and it takes
 * 				  one of the enum (En_motorType_t) parameters
 * @param Mot_Direction : one of the states (stop,forword,backword)and it takes
 * 				  one of the enum (En_motorDir_t) parameters 
 *
 */
void MotorDC_Dir(En_motorType_t en_motor_number, En_motorDir_t en_motor_dir);

/**
 * Description: The motor speed 
 * @param 
 */
void MotorDC_Speed_PollingWithT0(uint8_t u8_motor_speed);

/**
 * Description: set the port value (which is PORT register)
 * @param 
 */
void MotorDC_Speed_HwPWM(uint8_t u8_motor_speed);
#endif /* MOTORDC_H_ */