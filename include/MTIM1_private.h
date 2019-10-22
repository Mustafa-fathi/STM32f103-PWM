#ifndef _MTIM1_PRIVATE_H
#define _MTIM1_PRIVATE_H
#include "LSTD_TYPES.h"


typedef struct 
{
	volatile u32   TIM1_CR1       ;
	volatile u32   TIM1_CR2       ;
	volatile u32   TIM1_SMCR      ;
	volatile u32   TIM1_DIER      ;
    volatile u32   TIM1_SR        ;
	volatile u32   TIM1_EGR       ;
	volatile u32   TIM1_CCMR1     ;
	volatile u32   TIM1_CCMR2     ;
	volatile u32   TIM1_CCER      ;
	volatile u32   TIM1_CNT       ;
	volatile u32   TIM1_PSC       ;
	volatile u32   TIM1_ARR       ;
    volatile u32   TIM1_RCR       ;
	volatile u32   TIM1_CCR1      ;
	volatile u32   TIM1_CCR2      ;
	volatile u32   TIM1_CCR3      ;
	volatile u32   TIM1_CCR4      ;
	volatile u32   TIM1_BDTR      ;
	volatile u32   TIM1_DCR       ;
	volatile u32   TIM1_DMAR      ;
	
}TIM1_Type;

#define MTIM1  ((volatile TIM1_Type*)0x40012C00)













#endif
