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

int FlagDimmer=0;

// ISR(PORTD_INT0_vect) // ZCD
// {
// 	while( (RTC.STATUS&0x01) && 0x01 );
// 	RTC.CNT = 0;
// 	led4(TOGGLE);
// }

ISR(PORTC_INT0_vect) // BOTON
{
	led2(TOGGLE);
	if(FlagDimmer)
	FlagDimmer=0;
	else
	FlagDimmer = 1;
}

ISR(RTC_COMP_vect)
{
	while( (RTC.STATUS&0x01) && 0x01 );
	volatile int val = RTC.COMP;
	led1(TOGGLE);
	if (FlagDimmer)
	{
		bluetooth_putchar(ioport_get_pin_level(IO_8)+'0');
	}
	
	RTC.CNT = 0;
}

//Asignación de variables a los posibles pines. Si hay un cambio de pines solo se cambia en esta planilla
#define COMMAND_T IO_1
#define COMMAND_C IO_2
#define COMMAND_A IO_3
#define COMMAND_M IO_4
#define COMMAND_O IO_5

void sendIR(int code)
{
	//send header
	for(int i=0;i<10;i++)
	{
		ioport_set_pin_level(IO_7,ON);
		delay_us(10);
		ioport_set_pin_level(IO_7,OFF);
		delay_us(10);
	}
	
	//send code
	
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
	
// 	//Activate ZCD signal interruption
// 	cpu_irq_disable();
// 	PORTD.INTCTRL = 0x03;
// 	PORTD.INT0MASK = (1<<5);
// 	PORTD.PIN5CTRL |= 0x02;
// 	cpu_irq_enable();
	
	//Activate RTC and interruption
	cpu_irq_disable();
	sysclk_enable_module(SYSCLK_PORT_GEN, SYSCLK_RTC);
	RTC.PER = 0xffff;
	RTC.CNT = 0;
	//RTC.COMP=32768;
	RTC.COMP=1;
	RTC.INTCTRL = 0x0C;
	RTC.CTRL = RTC_PRESCALER_DIV1_gc;
	cpu_irq_enable();
	
	for (;;)
	{
		led3(ioport_get_pin_level(IO_8));
	}
	char command;
	int value;
	for(;;)
	{
		while (bluetooth_is_rx_complete()==0);
		scanf("%1c%d",&command,&value);
		switch (command)
		{
			case 'C': // Puerta Principal. Tiene que prenderse tener un retardo y luego apagarse.
			if (value==1)
			{
				ioport_set_pin_level(COMMAND_C,ON);
				delay_s(2);
				ioport_set_pin_level(COMMAND_C,OFF);
			}
			break;
			case 'T': // Tacos principales
			if (value==1)
			{
				ioport_set_pin_level(COMMAND_T,ON);
			}
			else
			{
				ioport_set_pin_level(COMMAND_T,OFF);
			}
			break;
			case 'D': // dimmer
			if(value == 160)
			{
				while( (RTC.STATUS&0x01) && 0x01 );
				RTC.COMP=500;
				ioport_set_pin_level(DIMMER_TRIGGER,ON);
				FlagDimmer=ON;
			}
			else if (value == 500)
			{
				while( (RTC.STATUS&0x01) && 0x01 );
				RTC.COMP=500;
				ioport_set_pin_level(DIMMER_TRIGGER,OFF);
				FlagDimmer=OFF;
				
			}
			else
			{
				while( (RTC.STATUS&0x01) && 0x01 );
				RTC.COMP=value;
				FlagDimmer=2;
			}
			break;
			case 'O': // Luces On OFF
			if (value==1)
			{
				ioport_set_pin_level(COMMAND_O,ON);
			}
			else
			{
				ioport_set_pin_level(COMMAND_O,OFF);
			}
			break;
			case 'A': //Aire Acondicionado
			if (value==1)
			{
				ioport_set_pin_level(COMMAND_A,ON);
			}
			else
			{
				ioport_set_pin_level(COMMAND_A,OFF);
			}
			break;
			case 'M': //Tomacorriente
			if (value==1)
			{
				ioport_set_pin_level(COMMAND_M,ON);
			}
			else
			{
				ioport_set_pin_level(COMMAND_M,OFF);
			}
			break;
			
			default:
			led1(TOGGLE);
			break;
		}
	}
}
