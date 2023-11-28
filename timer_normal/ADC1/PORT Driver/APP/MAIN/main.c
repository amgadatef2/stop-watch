/*
 * Button with LEDs.c
 *
 * Created: 9/12/2023 9:45:35 PM
 * Author : AliMamdoh
 */ 


/*#include "PORT_Core.h"
#include "LCD_Core.h"
#include "KeyPad_Core.h"
#include "LED_Core.h"
#include <avr/interrupt.h> // we will understand but not today
#include "IRQH_Core.h"
#include "SevenSegment_Core.h"
#include "ADC_Core.h"
#include "GPT_core.h"

extern uint32 ADC_Vin_Value_mv;

int main(void)
{
   PORT_Init();


      IRQH_SetGlobalInterrupts( INTERRUPT_ENABLE);
      IRQH_SetCallBack(LED_TGL);
	  GPT_INIT();
	  GPT_SetTime();


   while (1)
   {
   }
}*/
#include "LED_Core.h"
#include "Button_Core.h"
#include "PORT_Core.h"
#include "DIO_Core.h"
#include "LCD_Core.h"

uint8 min=0,sec=0;
uint8 button4=1;

void count_down(void);
int main(void)
{
	uint8 button1 =1;
	uint8 button2 =1;
	uint8 button3 =1;
	
	
	
	
	
	PORT_Init();
	LCD_Init();
	Button_Init();
	uint8 str[]="stop watch";
	uint8 str2[]="Time is Over";
	LCD_WriteString(str);
	_delay_ms(2000);
	LCD_Clear();
	LCD_WriteInteger(min);
	LCD_WriteInteger(0);
	LCD_WriteChar(':');
	LCD_WriteInteger(sec);
	LCD_WriteInteger(0);
	



	

	
	
	
	while (1)
	{
		button1=Button_GetValue1();
		button2=Button_GetValue2();
		button3=Button_GetValue3();
		button4=Button_GetValue4();
		uint8 statement =5;
		
		if(button1==0){
			statement =0;
			
			
			
			
		}
		else if(button2==0){
			statement=1;

		}
		else if (button3==0){
			
			statement=2;
			
			
			
		}
		switch(statement){
			case 0:
			LCD_Clear();
			min++;
			LCD_GoTo(0,1);
			LCD_WriteString("M");
			LCD_WriteString(":S");
			LCD_GoTo(1,1);
			
			
			LCD_WriteInteger(min);
			LCD_WriteChar(':');
			LCD_WriteInteger(sec);
			break;
			
			case 1:
			if(sec<60){
				LCD_Clear();
				sec++;
				LCD_GoTo(0,1);
				LCD_WriteString("M");
				LCD_WriteString(":S");
				LCD_GoTo(1,1);
				LCD_WriteInteger(min);
				LCD_WriteChar(':');
				LCD_WriteInteger(sec);
				break;
				
				case 2:
				_delay_ms(1000);
				count_down();
				while(min!=0){
					if(sec==0){
						--min;
						sec=60;
						LCD_Clear();
						LCD_GoTo(0,1);
						LCD_WriteString("M");
						LCD_WriteString(":S");
						LCD_GoTo(1,1);
						LCD_WriteInteger(min);
						LCD_WriteChar(':');
						LCD_WriteInteger(sec);
						count_down();
						
					}
					
					

				}
				if(min==0 && sec==0){
					LCD_Clear();
					LCD_GoTo(0,1);
					LCD_WriteString("M");
					LCD_WriteString(":S");
					LCD_GoTo(1,1);
					LCD_WriteInteger(0);
					LCD_WriteChar(':');
					LCD_WriteInteger(0);
					
					SET_BIT(PORTC,5);
					SET_BIT(PORTC,0);
					SET_BIT(PORTC,1);
					SET_BIT(PORTC,2);
					_delay_ms(100);
					LCD_Clear();
					LCD_WriteString(str2);
					
					statement=5;

				}
				
				
			}
			
		}
		if(button4==0){
			LCD_Clear();
			LCD_GoTo(0,1);
			LCD_WriteString("M");
			LCD_WriteString(":S");
			LCD_GoTo(1,1);
			LCD_WriteInteger(0);
			LCD_WriteChar(':');
			LCD_WriteInteger(0);
			CLR_BIT(PORTC,5);
			CLR_BIT(PORTC,0);
			CLR_BIT(PORTC,1);
			CLR_BIT(PORTC,2);
			
		}

		
	}
}
void count_down(void)
{
	while(sec!=0){
		LCD_Clear();
		--sec;
		LCD_GoTo(0,1);
		LCD_WriteString("M");
		LCD_WriteString(":S");
		LCD_GoTo(1,1);
		LCD_WriteInteger(min);
		LCD_WriteChar(':');
		LCD_WriteInteger(sec);
		_delay_ms(1000);
		
	}
	
	
	
	
}

