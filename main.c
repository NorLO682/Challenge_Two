
#include "gpio.h"
#include "softwareDelay.h"
#include "sevenSeg.h"
#include "led.h"
#include "pushButton.h"

// THE DELIVER FILE

// seven_segment_count

#define START 0x00
#define END_NUMBER 0x99
#define NEXT_COUNT  0X06
#define RIGHT_SEG_DATA_MASK 0x0f
#define LEFT_SEG_DATA_MASK  4
# define MAX_COUN_RIGHT_SEG 0X0A
# define COUNT_TIME 150




// state machine

#define STOP 0
#define GET_READY 1
#define GO 2
#define STATE_MACHINE_SECOND 1000


// button_application

# define SECOND 915
#define TEST_SEGMENT 50
#define  RISE_HAND_TIME 30
#define MULTIPLE_PRESSED_DELAY 160
#define SINGLE_REEASED_DELAY 130



void seven_seg_app(void);
void button_app(void);
void state_machine(void);


int main(){
	
	// button_app();
	//seven_seg_app();
	// state_machine();
	

	return FALSE;
	
}




void button_app(void){
	
	Led_Init(LED_3);
	pushButtonInit(BTN_0);

	uint32_t delay,flag;
	while(TRUE){
		flag=FALSE;
		delay=FALSE;
		Led_Off(LED_3);
		
		while(pushButtonGetStatus(BTN_0)==Released);
		
		while(pushButtonGetStatus(BTN_0)==Pressed);
		
		flag+=(SECOND);
		Led_On(LED_3);
		
		while(delay<flag){
			softwareDelayMs( TEST_SEGMENT);
			if(pushButtonGetStatus(BTN_0)==Pressed){
				softwareDelayMs(RISE_HAND_TIME);
				flag+=(SECOND);
				delay+=MULTIPLE_PRESSED_DELAY;
			}
			else
			delay+=SINGLE_REEASED_DELAY;
		}
		
	}
}

void seven_seg_app(void ) {
	uint8_t count_number;
	uint32_t delay_time;
	sevenSegInit(SEG_0);
	sevenSegInit(SEG_1);
	
	while(TRUE){
		
		count_number=START ;
		
		while(count_number<END_NUMBER){
			
			while((count_number&RIGHT_SEG_DATA_MASK)<MAX_COUN_RIGHT_SEG){
				
				delay_time=START;
				
				for(;delay_time<COUNT_TIME;delay_time++){

					sevenSegWrite(SEG_0,count_number);
					sevenSegWrite(SEG_1,(count_number>>LEFT_SEG_DATA_MASK));
				}
				count_number++;
			}
			
			count_number+=NEXT_COUNT;
		}

	}
}

void state_machine(void){
	uint8_t State_machine=GO;
	Led_Init(LED_0);
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Off(LED_0);
	Led_Off(LED_1);
	Led_Off(LED_2);
	while(TRUE){
		switch  (State_machine){
			case STOP :
			State_machine=GET_READY;
			Led_On(LED_2);
			Led_Off(LED_0);
			break;
			
			case GET_READY:
			State_machine=GO;
			Led_On(LED_1);
			Led_Off(LED_2);
			break;
			
			case GO:
			State_machine=STOP;
			Led_On(LED_0);
			Led_Off(LED_1);
			
			break;
		}
		softwareDelayMs(STATE_MACHINE_SECOND);
	}
}