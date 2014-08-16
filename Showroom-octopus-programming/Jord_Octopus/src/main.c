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
		case '5':
			ioport_toggle_pin_level(LED5);
		break;
		case '6':
			ioport_toggle_pin_level(LED6);
		break;
	}
}

#define INIT_MAX 100
void initial_animation(void)
{
	volatile int i;
	for(i = 50;i<INIT_MAX;i+=15)
	{
		ioport_set_pin_level(LED1,1);
		delay_ms(i);
		ioport_set_pin_level(LED2,1);
		delay_ms(i);
		ioport_set_pin_level(LED3,1);
		delay_ms(i);
		ioport_set_pin_level(LED4,1);
		delay_ms(i);
		ioport_set_pin_level(LED5,1);
		delay_ms(i);
		ioport_set_pin_level(LED6,1);
		delay_ms(i);
		
		ioport_set_pin_level(LED1,0);
		delay_ms(i);
		ioport_set_pin_level(LED2,0);
		delay_ms(i);
		ioport_set_pin_level(LED3,0);
		delay_ms(i);
		ioport_set_pin_level(LED4,0);
		delay_ms(i);
		ioport_set_pin_level(LED5,0);
		delay_ms(i);
		ioport_set_pin_level(LED6,0);
		delay_ms(i);
	}
}


void remote_controlled(void)
{
	/*¨Parts:
	-Leds (L)
	-Motors (M)
	-servos (S)
	-complete movement (R) */
	char part;
	int opt1=0;
	int opt2=0;
	int opt3=0;
	//scanf("%1c%1i%3i%3i",&part,&opt1,&opt2,&opt3);
	scanf("%1c%1i%3i",&part,&opt1,&opt2);
	switch (part)
	{
		/* Motors M+#of motor + speed (99 to -99) */
		case 'M':
			switch (opt1)
			{
				case 1:
				motor1(opt2);
				break;
				case 2:
				motor2(opt2);
				break;
				case 3:
				motor3(opt2);
				break;
				case 4:
				motor4(opt2);
				break;
			}
		break;
		
		case 'R':
			move(opt2,opt3);
		break;
		
		
		case 'S':
			switch(opt1)
			{
				case 1: 
					pwm_update(SERVO_0,opt2);
				break;
				case 2:
					pwm_update(SERVO_1,opt2);
				break;
				case 3:
					pwm_update(SERVO_2,opt2);
				break;
				case 4:
					pwm_update(SERVO_3,opt2);
				break;
				
			}
		break;
		
		
		/* Leds, L + # of led + option
			L1000 turn off led 1
			L1001 turn on led 1
			L1002 toggle led 1 */
		case 'L':
			switch (opt1)
			{
			case 1:
				switch(opt2)
				{
					case 0:
					ioport_set_pin_level(LED1,0);
					break;
				
					case 1:
					ioport_set_pin_level(LED1,1);
					break;
				
					case 2:
					ioport_toggle_pin_level(LED1);
					break;
				}
			break;
				
			case 2:
				switch(opt2)
				{
					case 0:
					ioport_set_pin_level(LED2,0);
					break;
					
					case 1:
					ioport_set_pin_level(LED2,1);
					break;
					
					case 2:
					ioport_toggle_pin_level(LED2);
					break;
				}
			break;
			
			case 3:
			switch(opt2)
			{
				case 0:
				ioport_set_pin_level(LED3,0);
				break;
				
				case 1:
				ioport_set_pin_level(LED3,1);
				break;
				
				case 2:
				ioport_toggle_pin_level(LED3);
				break;
			}
			break;
			
			case 4:
			switch(opt2)
			{
				case 0:
				ioport_set_pin_level(LED4,0);
				break;
				
				case 1:
				ioport_set_pin_level(LED4,1);
				break;
				
				case 2:
				ioport_toggle_pin_level(LED4);
				break;
			}
			break;
			
			case 5:
			switch(opt2)
			{
				case 0:
				ioport_set_pin_level(LED5,0);
				break;
							
				case 1:
				ioport_set_pin_level(LED5,1);
				break;
							
				case 2:
				ioport_toggle_pin_level(LED5);
				break;
			}
			break;
			
			case 6:
			switch(opt2)
			{
				case 0:
				ioport_set_pin_level(LED6,0);
				break;
				
				case 1:
				ioport_set_pin_level(LED6,1);
				break;
				
				case 2:
				ioport_toggle_pin_level(LED6);
				break;
			}
		break;
		}

// 		case 'M':
// 		break;
// 		
// 		case 'S':
// 		break;
// 		
// 		case 'R':
// 		break;
	}
}

int main (void)
{

	ioport_set_pin_dir(IO_1,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_2,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_3,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(IO_4,IOPORT_DIR_OUTPUT);
	init_octopus();
 	initial_animation();
	 
	pwm_ini(SERVO_0);
	pwm_update(SERVO_0,0);
	delay_ms(1000);
	pwm_update(SERVO_0,500);
	delay_ms(1000);
	pwm_update(SERVO_0,1000);
	 
	char aux;
	char aux2;
	int dimmer=0;
	for(;;)
	{
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

	dimmer=dimmer*10;	
	pwm_update(SERVO_0,dimmer);	
		
	}
}

