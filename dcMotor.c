/*
 * dcMotor.c
 *
 * Created: 27/01/2020 08:18:59 م
 *  Author: TOSHIBA
 */ 
#include "dcMotor.h"
void MotorDC_Init(En_motorType_t en_motor_number){
	switch( en_motor_number){
		case MOT_1:
		gpioPinDirection(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,OUTPUT);
		gpioPinDirection(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,OUTPUT);
		gpioPinDirection(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,OUTPUT);	
		break;
		case MOT_2:
		gpioPinDirection(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,OUTPUT);
		gpioPinDirection(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,OUTPUT);
		gpioPinDirection(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,OUTPUT);
		break;
	}
}

void MotorDC_Dir(En_motorType_t en_motor_number, En_motorDir_t en_motor_dir){
	switch( en_motor_number){
		case MOT_1:
		switch(en_motor_dir){
			case STOP:

			gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
			gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
			break;
			case FORWARD :
			gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
			gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
		   break;
		   case BACKWARD :
		   gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
		   gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);
		   break;
		}
		break;
		
		case MOT_2:
			switch(en_motor_dir){
				case STOP:

				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
				break;
				case FORWARD :
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
				break;
				case BACKWARD :
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);
				break;
			}
		
		break;
	}
}

void MotorDC_Speed_PollingWithT0(uint8_t u8_motor_speed){
	timer0SwPWM(u8_motor_speed,MOTOR_FREQUENCY);
	
}