/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include "DomOctopus/DomOctopus.h"

#define CONTACTOR IO_1
#define DIMMER_TRIGGER IO_7
 
int dimmer=0;
int i=0;
ISR(PORTD_INT0_vect) // ZCD
{
	//while( (RTC.STATUS&0x01) && 0x01 );
	RTC.CNT = 0;
	led4(TOGGLE);
}

ISR(PORTC_INT0_vect) // BOTON
{
	ioport_toggle_pin_level(CONTACTOR);
}

ISR(RTC_COMP_vect)
{
	ioport_set_pin_level(DIMMER_TRIGGER, ON);
	led3(TOGGLE);
	delay_us(200);
	ioport_set_pin_level(DIMMER_TRIGGER, OFF);
}

int main (void)
{
	init_DomOctopus();
	animation();
	
	//Activate button interrupt
	pmic_init();
	pmic_set_scheduling(PMIC_SCH_ROUND_ROBIN);
	PORTC.INTCTRL = 0x01;
	PORTC.INT0MASK = (1<<3);
	PORTC.PIN3CTRL |= (1<<1);
	cpu_irq_enable();
		
	//Activate ZCD signal interruption
	cpu_irq_disable();
	PORTD.INTCTRL = 0x03;
	PORTD.INT0MASK = (1<<5);
	PORTD.PIN5CTRL |= 0x02;
	cpu_irq_enable();
	
	//Activate RTC and interruption
	cpu_irq_disable();
	sysclk_enable_module(SYSCLK_PORT_GEN, SYSCLK_RTC);
	RTC.PER = 0xffff;
	RTC.CNT = 0;
	RTC.COMP=32768;
	RTC.INTCTRL = 0x0C;
	RTC.CTRL = RTC_PRESCALER_DIV1_gc;
	cpu_irq_enable();
	
	
	char command;
	int value;
	for(;;)
	{
// 		while (bluetooth_is_rx_complete()==0);
// 		scanf("%3d",&value);
// 		while( (RTC.STATUS&0x01) && 0x01 );
// 		RTC.COMP=value;
// 		led1(TOGGLE);
	}
// 	for(;;)
// 	{
// 		scanf("%1c%d",&command,&value);
// 		switch (command)
// 		{
// 		case 'C':
// 			if (value==1)
// 			{
// 				led1(ON);
// 				ioport_set_pin_level(IO_1,ON);
// 			}
// 			else
// 			{
// 				led1(OFF);
// 				ioport_set_pin_level(IO_1,OFF);
// 			}
// 		break;
// 		case 'T':
// 			if (value==1)
// 			{
// 				led2(ON);
// 				ioport_set_pin_level(IO_2,ON);
// 			}
// 			else
// 			{
// 				led2(OFF);
// 				ioport_set_pin_level(IO_2,OFF);
// 			}
// 		break;
// 		case 'D':
// 			RTC.COMP=value;
// 		break;
// 		case 'O':
// 			if (value==1)
// 			{
// 				led3(ON);
// 				ioport_set_pin_level(IO_3,ON);
// 			}
// 			else
// 			{
// 				led3(OFF);
// 				ioport_set_pin_level(IO_3,OFF);
// 			}
// 		break;
// 		default:
// 			led4(TOGGLE);
// 		break;
// 		}
// 	}
}

