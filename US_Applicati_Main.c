/*
 * US_Applicati_Main.c
 *
 * Created: 30/01/2020 05:11:12 ص
 *  Author: TOSHIBA
 */ 
#include "led.h"
#include "SwICU.h"
#include "Ultrasonic.h"
#include "interrupt.h"
#include "timers.h"

 #define TICK_TIME_IN_MICRO 4


#define LED_GPIO_PORT   PORTB_DATA

#define RISSING_EDGGE 1
#define FALLING_EDGGE 2
#define STOP_INERE  3

#define TIMER_INI_VALUE    (0X00)


volatile uint8_t interrupt_phase= RISSING_EDGGE;



int main(){ 
	
	uint8_t tcnt_value=0,distance=0;
	
	 Led_Init(LED_0);
     Led_Init(LED_1);
	 Led_Init(LED_2);
	 Led_Init(LED_3);
	 
 Led_Off(LED_0);
 Led_Off(LED_1);
 Led_Off(LED_2);
 Led_Off(LED_3);
	  
 	gpioPinDirection(GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN ,OUTPUT); 
	   SwICU_Init(SwICU_EdgeRisiging);
	   SwICU_Enable();
	   
	 while(1){ 
		 
 	
	 
 	gpioPinWrite(GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN ,HIGH);
 	
 	timer2DelayMs(1);
 	
	gpioPinWrite(GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN ,LOW);
	

while( interrupt_phase!=STOP_INERE);
 
SwICU_Read(&tcnt_value);


distance=((tcnt_value)*TICK_TIME_IN_MICRO)/(58);	

LED_GPIO_PORT&=0x0f;           

	if(distance<16)
	LED_GPIO_PORT=(distance<<4);
	else
LED_GPIO_PORT=0xf0;

timer2DelayMs(100);

//timer0Set(TIMER_INI_VALUE);
interrupt_phase= RISSING_EDGGE;
}
return 0;

 }
 
 
		
		
		
		MY_ISR(INT2_vect){ 
			
			switch (interrupt_phase){
				
				case RISSING_EDGGE:
				SwICU_Start();
				SwICU_SetCfgEdge(SwICU_EdgeFalling);
				interrupt_phase=FALLING_EDGGE;
				break;
		
				case FALLING_EDGGE:
				SwICU_Stop();
				SwICU_SetCfgEdge(SwICU_EdgeRisiging);
				interrupt_phase=STOP_INERE;
				break;
			}	
		}
			
	
	
