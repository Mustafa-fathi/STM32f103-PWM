
#include "LSTD_TYPES.h"
#include "MTIM1_interface.h"
#include "MTIM1_private.h"


void TIM1_pwm (void)
{

	MTIM1 -> TIM1_ARR = 7812 ;  //frequency of signal
    MTIM1 -> TIM1_CCR1 = 500;  //duty cycle
	MTIM1 -> TIM1_PSC = 1024 ;
    MTIM1 -> TIM1_CCMR1 |= (1<<6)|(1<<5) | (1<<3);
	MTIM1 ->TIM1_CCER |= (1<<0);  //capture compare enable
	MTIM1 ->TIM1_BDTR |= (1<<15); //generate pwm on pin
	MTIM1 ->TIM1_EGR |= (1<<0);   //enable update generation
	MTIM1 -> TIM1_CR1 = 0x1 ;



}

void delay (u32 time , u8 unit )
{
	switch (unit)
	{
	case sec :

		MTIM1 -> TIM1_PSC = 160 ;
		MTIM1 -> TIM1_ARR = 50000 ;
		MTIM1 -> TIM1_RCR = (time - 1);
		MTIM1 ->TIM1_EGR |= (1<<0);
		MTIM1 -> TIM1_CR1 = 0x1 ;
		(MTIM1 -> TIM1_SR) = 0;
		while (((MTIM1 -> TIM1_SR) & (0x1))== 0);
		(MTIM1 -> TIM1_SR) = 0;
		(MTIM1 -> TIM1_CR1) = 0x00;

		break ;

	case msec :
		MTIM1 -> TIM1_PSC = 8000 ;

		MTIM1 -> TIM1_ARR = time  ;
		MTIM1 -> TIM1_RCR =0;
		MTIM1 ->TIM1_EGR = 0x1;
		MTIM1 -> TIM1_CR1 = (1<<0);
		MTIM1 -> TIM1_SR = 0;
		while (((MTIM1 -> TIM1_SR)& (0x1))== 0);
		(MTIM1 -> TIM1_SR) = 0;
		(MTIM1 -> TIM1_CR1) = 0x00;
		break ;
	}
}

