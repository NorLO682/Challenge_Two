/*
 * led.c
 *
 * Created: 18/01/2020 01:13:48 ص
 *  Author: TOSHIBA
 */ 
#include"led.h"
void Led_Init(En_LedNumber_t en_led_id){
	switch(en_led_id){
		
		case LED_0:
		 gpioPinDirection(LED_0_GPIO,LED_0_BIT,OUTPUT);
		 break;
		 
		 case LED_1:
		 gpioPinDirection(LED_1_GPIO,LED_1_BIT,OUTPUT);
		 break;
		 
		  case LED_2:
		  gpioPinDirection(LED_2_GPIO,LED_2_BIT,OUTPUT);
		  break;
		  case LED_3:
		   gpioPinDirection(LED_3_GPIO,LED_3_BIT,OUTPUT);
		   break;
	}
}

void Led_On(En_LedNumber_t en_led_id){
	switch(en_led_id){
		
		case LED_0:
		gpioPinWrite(LED_0_GPIO,LED_0_BIT,HIGH);
		break;
		
		case LED_1:
		gpioPinWrite(LED_1_GPIO,LED_1_BIT,HIGH);
		break;
		
		case LED_2:
		gpioPinWrite(LED_2_GPIO,LED_2_BIT,HIGH);
		break;
		case LED_3:
		gpioPinWrite(LED_3_GPIO,LED_3_BIT,HIGH);
		break;
	} 
 }
 
 void Led_Off(En_LedNumber_t en_led_id){
	 switch(en_led_id){
		 
		 case LED_0:
		 gpioPinWrite(LED_0_GPIO,LED_0_BIT,LOW);
		 break;
		 
		 case LED_1:
		 gpioPinWrite(LED_1_GPIO,LED_1_BIT,LOW);
		 break;
		 
		 case LED_2:
		 gpioPinWrite(LED_2_GPIO,LED_2_BIT,LOW);
		 break;
		 case LED_3:
		 gpioPinWrite(LED_3_GPIO,LED_3_BIT,LOW);
		 break;
	 }
	 
 }

void Led_Toggle(En_LedNumber_t en_led_id){
	switch(en_led_id){
		
		case LED_0:
		 gpioPinToggle(LED_0_GPIO,LED_0_BIT);
		break;
		
		case LED_1:
		gpioPinToggle(LED_1_GPIO,LED_1_BIT);
		break;
		
		case LED_2:
		gpioPinToggle(LED_2_GPIO,LED_2_BIT);
		break;
		case LED_3:
		gpioPinToggle(LED_3_GPIO,LED_3_BIT);
		break;
	}
	
}


// void timer0SwPWM(uint8_t u8_dutyCycle,uint32_t u8_frequency){
// 	if (start_pwm0==1){
//
// 		f64_t time_Interrupt=1/(100.0*u8_frequency);
//
// 		uint8_t prescaler,prescaler_index;
// 		uint16_t no_of_tick=0xffff ;
//
// 		start_pwm0=0;
// 		flag_pwm0=u8_dutyCycle;
// 		TCCR0=0x00;
// 		TCCR0|=T0_NORMAL_MODE|T0_OC0_DIS;
// 		SET_BIT(TIFR,TOV0_FLAG_BIT);
// 		TIMSK|=T0_INTERRUPT_NORMAL;
// 		SET_BIT(SREG,BIT7);
//
// 		gpioPinDirection(T0_PWM_GPIO,T0_PWM_BIT,OUTPUT);
// 		gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,LOW);
//
// 		for(prescaler_index=1;(( no_of_tick>148)&&(prescaler_index<5));prescaler_index++){
// 			prescaler=perscaler_mask_arr[prescaler_index];
// 			no_of_tick= time_Interrupt/(tick_time_value_arr[prescaler_index]);
//
// 		}
// 		tcnt0_interrupt_pwm=TIMERS1_2_RESELUTION1-  no_of_tick;
//
//
//
// 		TCNT0= tcnt0_interrupt_pwm;
//
// 		gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,HIGH);
// 		TCCR0|=prescaler;
// 	}
//
// }
//
// MY_ISR(TIMER0_OVF_vect){
// 	static volatile  uint8_t count =0;
// 	if (count<flag_pwm0){
// 		count++;
//
// 	}
//
// 	else if  (count<100)
// 	{
// 		count++;
// 		gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,LOW);
//
// 	}
// 	else if (count==100){
// 		gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,HIGH);
// 		count=0;
// 		start_pwm0=1;
// 	}
// 	TCNT0=tcnt0_interrupt_pwm;
// }




///////////
// void timer0SwPWM(uint8_t u8_dutyCycle,uint32_t u8_frequency){
 // 	if (start_pwm0==1){
 // 		
 // 	f64_t time_on_pwm=(u8_dutyCycle)/(100.0*u8_frequency);
 // 	uint8_t prescaler,prescaler_index;
 // 	
 // 	
 // 	start_pwm0=0;
 // 	
 // 	TCCR0=0x00;
 // 	TCCR0|=T0_NORMAL_MODE|T0_OC0_DIS;
 // 	SET_BIT(TIFR,TOV0_FLAG_BIT);
 // 	TIMSK|=T0_INTERRUPT_NORMAL;
 // 	SET_BIT(SREG,BIT7);
 // 	
 // 	gpioPinDirection(T0_PWM_GPIO,T0_PWM_BIT,OUTPUT);
 // 	gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,LOW);
 // 	
 // 	for(prescaler_index=1;((no_of_tick>TIMERS1_2_RESELUTION1)&&(prescaler_index<5));prescaler_index++){
 // 	prescaler=perscaler_mask_arr[prescaler_index];
 //     no_of_tick= time_on_pwm/(tick_time_value_arr[prescaler_index]);
 // }
 // tcnt0_on_pwm=TIMERS1_2_RESELUTION1-no_of_tick;
 // TCNT0= tcnt0_on_pwm;
 // gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,HIGH);
 // TCCR0|=prescaler;
 // 	}
 // 
 // }
 // 
 //  MY_ISR(TIMER0_OVF_vect){
 //  static volatile uint8_t flag =0;
 //  	 if (flag==0){
 // 		  
 // 		 gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,LOW);
 // 	 
 //          TCNT0=TIMERS1_2_RESELUTION1-tcnt0_on_pwm+no_of_tick;
 //  	     
 // 		   flag=1;
 //  	 }
 // 	  else{
 // 		  gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,HIGH);
 //      	  TCNT0=tcnt0_on_pwm;
 //     	  flag=0;	 start_pwm0=1;
 //   }
 // 	 
 //  }