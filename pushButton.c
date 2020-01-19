/*
 * pushButton.c
 *
 * Created: 18/01/2020 09:04:38 ص
 *  Author: TOSHIBA
 */ 
#include "pushButton.h"
#include"pushButton.h"

void pushButtonInit(En_buttonId_t en_butotn_id){
	switch(en_butotn_id){
		case BTN_0:
		gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
		break;
		
		case BTN_1:
		gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
		break;
		
		case BTN_2:
		gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,INPUT);
		break;
		
		case BTN_3:
		gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,INPUT);
		break;
	}
}

En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id){
	softwareDelayMs(BOUNCING_TIMEiNm);
	En_buttonStatus_t staut_flag=Released;
	switch(en_butotn_id){
		
		case BTN_0:
		staut_flag=gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
		softwareDelayMs(BOUNCING_TIMEiNm);
		staut_flag|=gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
		break;
		
		case BTN_1:
		staut_flag=gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
		softwareDelayMs(BOUNCING_TIMEiNm);
		staut_flag|=gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
		break;
	
		
		case BTN_2:
		staut_flag=gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
		softwareDelayMs(BOUNCING_TIMEiNm);
		staut_flag|=gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
		break;
		
		
		case BTN_3:
		staut_flag=gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
		softwareDelayMs(BOUNCING_TIMEiNm);
		staut_flag|=gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
		break;
	}
	return staut_flag;
}
