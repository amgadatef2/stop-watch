/*
 * Button_Core.c
 *
 * Created: 9/15/2023 10:04:44 AM
 *  Author: AliMamdoh
 */ 

#include "Button_Core.h"/*

void Button_Init(void)
{
	CLR_BIT(DDRD,2); //Input
}
uint8 Button_GetValue(void)
{
	uint8 Temp=0;
	uint8 Button=1;
	Button=GET_BIT(PIND,2);
	
	while(Temp==0)
	{
		Temp= GET_BIT(PIND,2);
	}
	_delay_ms(10);
	return Button;
}*/
void Button_Init(void)
{
	CLR_BIT(DDRD,2);
	CLR_BIT(DDRD,3);
	CLR_BIT(DDRD,4);
}

uint8 Button_GetValue1 (void)
{

	uint8 Button1 = 1 ;
	uint8 Temp = 0;
	
	Button1= GET_BIT(PIND , 2);
	
	while(Temp == 0)
	{
		Temp = GET_BIT(PIND , 2);
	}
	
	_delay_ms(10);
	
	return Button1;
}
uint8 Button_GetValue2 (void){
	uint8 button2=1;
	uint8 Temp = 0;
	
	
	button2 =GET_BIT(PIND,3);
	while(Temp == 0)
	{
		Temp = GET_BIT(PIND , 3);
	}
	_delay_ms(10);
	return button2;
	
}
uint8 Button_GetValue3 (void){
	uint8 button3=1;
	uint8 Temp = 0;
	
	button3 =GET_BIT(PIND,4);
	while(Temp == 0)
	{
		Temp = GET_BIT(PIND , 4);
	}
	_delay_ms(10);
	return button3;
	
}
uint8 Button_GetValue4(void){
	uint8 button4=1;
	uint8 temp =0;
	button4=GET_BIT(PIND,5)	;
	while (temp==0){
		temp=GET_BIT(PIND,5) ;
		
		
	}
	_delay_ms(10);
	return button4;
}