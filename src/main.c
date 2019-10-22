/*
 * main.c
 *
 *  Created on: Oct 11, 2018
 *      Author: Hampota
 */

#include"LSTD_TYPES.h"
#include "MDIO_interface.h"
#include"MNVK_interface.h"
#include"MRCC_interface.h"
#include"MTIM1_interface.h"


void main()
{

  MRCC_Initialize();
  MRCC_EnableClock(BUS_ABP2,PERIPHERAL_GPIOA);
  MRCC_EnableClock(BUS_ABP2,PERIPHERAL_AFIO);
  MRCC_EnableClock(BUS_ABP2,PERIPHERAL_TIMER1);
  MDIO_Initialize();
  TIM1_pwm();
  while(1)
  {

  }


}
