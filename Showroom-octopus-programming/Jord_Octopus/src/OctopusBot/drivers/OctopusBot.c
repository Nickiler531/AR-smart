/*
 * OctopusBot.c
 *
 * Created: 3/30/2013 6:38:02 PM
 *  Author: Nick
 */ 

#include "./../OctopusBot.h"
#include <asf.h>




void init_octopus(void)
{
	sysclk_init();
	ioport_init();
	leds_init();
	bluetooth_init();
	//bluetooth_init_interrupt();
	switch_init();
	motors_init();
	
	//usb_init();	
	
}

void blink(void){
	ioport_set_pin_level(LED1,ON);
	ioport_set_pin_level(LED2,ON);
	delay_s(1);
	ioport_set_pin_level(LED1,OFF);
	ioport_set_pin_level(LED2,OFF);
	delay_s(1);
}

