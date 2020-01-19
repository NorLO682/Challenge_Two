/*
 * softwareDelay.c
 *
 * Created: 18/01/2020 12:25:22 ص
 *  Author: TOSHIBA
 */ 
#include "softwareDelay.h"
void softwareDelayMs(uint32_t u32_delay_in_ms){
	uint32_t volatile s=0;
	uint32_t period=0;
	for(;period<u32_delay_in_ms;period++){
		
		for (;s<233; ){
			s++;
		}
	}
	
}