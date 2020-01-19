#include "gpio.h"

void gpioPortDirection(uint8_t u8_port, uint8_t u8_direction){
	switch (u8_port){
		case GPIOA :
			PORTA_DIR=INPUT;
			break;
			
			case GPIOB :
			PORTB_DIR =INPUT;
			break;
			
			case GPIOC :
			PORTC_DIR=INPUT;
			break;
			
			case GPIOD :
			PORTC_DIR=INPUT;
			break;
	}

}

void gpioPortWrite(uint8_t u8_port, uint8_t u8_value){
	
	switch (u8_port){
		case GPIOA :
			PORTA_DATA=u8_value;
			break;
			
			case GPIOB :
			PORTB_DATA=u8_value;
			break;
			
			case GPIOC :
			PORTC_DATA=u8_value;
			break;
			
			case GPIOD :
			PORTD_DATA=u8_value;
			break;
}
}

 void gpioPortToggle(uint8_t u8_port){
	switch (u8_port){
		case GPIOA :
			PORTA_DATA=~PORTA_DATA;
			break;
			
			case GPIOB :
			PORTB_DATA=~PORTB_DATA;
			break;
			
			case GPIOC :
			PORTC_DATA=~PORTC_DATA;
			break;
			
			case GPIOD :
			PORTD_DATA=~PORTD_DATA;
			break;
}
}

uint8_t gpioPortRead(uint8_t u8_port){

	uint8_t u8_port_data;//
	
	switch (u8_port){
		
		case GPIOA :
			u8_port_data=PORTA_PIN;
			break;
			
			case GPIOB :
		    u8_port_data=PORTB_PIN;
			break;
			
			case GPIOC :
			u8_port_data=PORTC_PIN;
			break;
			
			case GPIOD :
			u8_port_data=PORTD_PIN;
			break;
			}
			return u8_port_data;
}

void gpioPinDirection(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_direction){
	switch (u8_port){
		
		case GPIOA :
		u8_direction= u8_pins&u8_direction;
		PORTA_DIR=(~u8_pins)&PORTA_DIR;
		PORTA_DIR=u8_direction|PORTA_DIR;
			break;
			
			case GPIOB :
		u8_direction= u8_pins&u8_direction;
		PORTB_DIR=(~u8_pins)&PORTB_DIR;
		PORTB_DIR=u8_direction|PORTB_DIR;
			
			case GPIOC :
		u8_direction= u8_pins&u8_direction;
		PORTC_DIR=(~u8_pins)&PORTC_DIR;
		PORTC_DIR=u8_direction|PORTC_DIR;
			break;
			
			case GPIOD :
			u8_direction= u8_pins&u8_direction;
		PORTD_DIR=(~u8_pins)&PORTD_DIR;
		PORTD_DIR=u8_direction|PORTD_DIR;
			break;
	}
	
}

void gpioPinWrite(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_value){
	switch (u8_port){
		
		case GPIOA :
		u8_value= u8_pins&u8_value;
		PORTA_DATA=(~u8_pins)&PORTA_DATA;
		PORTA_DATA=u8_value|PORTA_DATA;
			break;
			
			case GPIOB :
		u8_value= u8_pins&u8_value;
		PORTB_DATA=(~u8_pins)&PORTB_DATA;
		PORTB_DATA=u8_value|PORTB_DATA;
			
			case GPIOC :
		u8_value= u8_pins&u8_value;
		PORTC_DATA=(~u8_pins)&PORTC_DATA;
		PORTC_DATA=u8_value|PORTC_DATA;
			break;
			
			case GPIOD :
		u8_value= u8_pins&u8_value;
		PORTD_DATA=(~u8_pins)&PORTD_DATA;
		PORTD_DATA=u8_value|PORTD_DATA;
			break;
	}
	
	
}

void gpioPinToggle(uint8_t u8_port, uint8_t u8_pins){
	
	switch (u8_port){
		
		case GPIOA :
	PORTA_DATA=u8_pins^PORTA_DATA;
			break;
			
			case GPIOB :
	PORTB_DATA=u8_pins^PORTB_DATA;
			
			case GPIOC :
	PORTC_DATA=u8_pins^PORTC_DATA;

			break;
			
			case GPIOD :
	 PORTD_DATA=u8_pins^PORTD_DATA;

			break;
	}
	
}

uint8_t gpioPinRead(uint8_t u8_port, uint8_t u8_pin){
	uint8_t u8_port_data;//
	switch (u8_port){
	
		case GPIOA :
	u8_port_data=u8_pin & PORTA_PIN;
			break;
			
			case GPIOB :
	u8_port_data=u8_pin&PORTB_PIN;
			
			case GPIOC :
    u8_port_data=u8_pin &PORTC_PIN;
			break;
			
 			case GPIOD :
    u8_port_data=u8_pin &PORTD_PIN;
			break;
	}
				return u8_port_data;

}
