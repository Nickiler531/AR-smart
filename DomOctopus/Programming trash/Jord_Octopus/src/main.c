/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include "./OctopusBot/OctopusBot.h"
#include <asf.h>

int dimmer=0;

ISR(PORTD_INT0_vect) 
{
	RTC.CNT = 0x00;
	ioport_toggle_pin_level(LED2);
	
}

ISR(PORTC_INT0_vect)
{
	ioport_set_pin_level(IO_1,OFF);
	ioport_set_pin_level(IO_2,OFF);
	ioport_set_pin_level(IO_3,OFF);
	ioport_set_pin_level(IO_4,OFF);
	ioport_set_pin_level(IO_5,OFF);
	ioport_set_pin_level(IO_6,OFF);
	ioport_set_pin_level(IO_7,OFF);
	ioport_set_pin_level(IO_8,OFF);
	ioport_set_pin_level(LED1,OFF);
	ioport_set_pin_level(LED2,OFF);
	ioport_set_pin_level(LED3,OFF);
	ioport_set_pin_level(LED4,OFF);
	PORTC.INTFLAGS |= 1;
}

ISR(RTC_COMP_vect)
{
	
	ioport_set_pin_level(IO_7, ON);
	ioport_toggle_pin_level(LED1);
	delay_ms(1);
	ioport_set_pin_level(IO_7, OFF);
	RTC.INTFLAGS|=(1<<1);
}

ISR(USARTD0_RXC_vect)
{
	int data = usart_getchar(BLUETOOTH);
	switch(data)
	{
		case '1':
			ioport_toggle_pin_level(LED1);
		break;
		case '2':
			ioport_toggle_pin_level(LED2);
		break;
		case '3':
			ioport_toggle_pin_level(LED3);
		break;
		case '4':
			ioport_toggle_pin_level(LED4);
		break;

	}
}


#define INIT_MAX 100


int main (void)
{

	ioport_set_pin_dir(IO_1,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_2,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_3,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_4,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_5,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_6,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_7,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_8,IOPORT_DIR_INPUT);
	init_octopus();
 	animation();
	 
	//Activate button interrupt
	pmic_init();
	pmic_set_scheduling(PMIC_SCH_ROUND_ROBIN);
	PORTC.INTCTRL = 0x03;
	PORTC.INT0MASK = (1<<3);
	PORTC.PIN3CTRL |= (1<<1);
	cpu_irq_enable();
	
	
	//Activate ZCD signal interruption 
	 cpu_irq_disable();
	 PORTD.INTCTRL = 0x03;
	 PORTD.INT0MASK = (1<<5);
	 PORTD.PIN5CTRL |= 0x01;
	 cpu_irq_enable();
	 
	//Activate RTC
	rtc_init();
	 
// 	pwm_ini(SERVO_0);
// 	pwm_update(SERVO_0,0);
// 	delay_ms(1000);
// 	pwm_update(SERVO_0,500);
// 	delay_ms(1000);
// 	pwm_update(SERVO_0,1000);
	 
	char aux;
	char aux2;
	for(;;)
	{
		printf("hello");
		if(bluetooth_is_rx_complete())
		{
			scanf("%1c",&aux);
			switch (aux)
			{
				case 'C':
					scanf("%1c",&aux);
					if (aux=='1')
					{
						led1(ON);
						ioport_set_pin_level(IO_1,ON);
					}
					else
					{
						led1(OFF);
						ioport_set_pin_level(IO_1,OFF);
					}
				break;
				case 'T':
					scanf("%1c",&aux);
					if (aux=='1')
					{
						led2(ON);
						ioport_set_pin_level(IO_2,ON);
					}
					else
					{
						led2(OFF);
						ioport_set_pin_level(IO_2,OFF);
					}
				break;
				case 'D':
					scanf("%i",&dimmer);
					RTC.COMP=dimmer;
										
				break;
				case 'O':
					scanf("%1c",&aux);
					scanf("%1c",&aux);
					scanf("%1c",&aux2);
					if(aux == '1')
					{
						if(aux2=='1')
						{
							led3(ON);
							ioport_set_pin_level(IO_3,ON);
						}
						else
						{
							led3(OFF);
							ioport_set_pin_level(IO_3,OFF);
						}
					}
					else
					{
						if(aux2=='1')
						{
							led4(ON);
							ioport_set_pin_level(IO_4,ON);
						}
						else
						{
							led4(OFF);
							ioport_set_pin_level(IO_4,OFF);
						}
					}
				break;
				
			}
		}
		
	}
}
