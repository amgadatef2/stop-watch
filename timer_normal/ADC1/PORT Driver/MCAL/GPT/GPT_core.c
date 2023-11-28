/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPT_core.h"
#include "MCU.h"
#include "STD.h"
#include "BIT_MATH.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32  TIMER_NUMBER_OVERFLOWS_G =0;
uint32   TIMER0_INIT_VALUE_G =0;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void GPT_INIT(void){
	#if  (TIMER0_STATE == TIMER_ENABLE) 
	
	#if   (TIMER0_MODE == NORMAL_MODE)
	CLR_BIT(TCCR0 ,3);
	CLR_BIT(TCCR0 ,6);
	 
	 #if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED)
	 SET_BIT(TIMSK,0);
	 #elif (TIMER0_INTERRUPT_STATE == INTERRUPT_DISABLED)
	 CLR_BIT(TIMSK,0);
	 
	 #endif  /* #if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED)*/
	
	#elif   (TIMER0_MODE == CTC_MODE)
	
	#endif  /*(TIMER0_MODE == NORMAL_MODE)*/
	#if (TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	 )
	TCCR0 |= 0X01;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_8		 )
	TCCR0 |= 0X02;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_64		 )
	TCCR0 |= 0X03;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_256		 )
	TCCR0 |= 0X04;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_1024		 )
	TCCR0 |= 0X05;
	#endif /*if(TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	 )*/
	
	
#endif  /*  #if  (TIMER0_STATE == TIMER_ENABLE) */

#if  (TIMER1_STATE == TIMER_ENABLE)

#endif  /*  #if  (TIMER1_STATE == TIMER_ENABLE) */


#if  (TIMER2_STATE == TIMER_ENABLE)

#endif  /*  #if  (TIMER2_STATE == TIMER_ENABLE) */





	
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void GPT_SetTime(void){
	
	uint8  MCU_CLK_ms =16;
	
	#if (TIMER0_STATE== TIMER_ENABLE)
	uint8 TIMER0TICK_TIME_us =TIMER0_PRESCALER / MCU_CLK_ms;
	uint32 time_ms=TIMER0_COUNTED_MS;
    uint32 timer0total_ticks=(time_ms *1000) /TIMER0TICK_TIME_us;
	TIMER_NUMBER_OVERFLOWS_G= timer0total_ticks/256;
	TIMER0_INIT_VALUE_G=256 -(timer0total_ticks%256);
	TCNT0=TIMER0_INIT_VALUE_G;
	if (timer0total_ticks%256){
		TIMER_NUMBER_OVERFLOWS_G++;}
	
	
	
	#endif /* #if (TIMER0_STATE== TIMER_ENABLE)*/
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
