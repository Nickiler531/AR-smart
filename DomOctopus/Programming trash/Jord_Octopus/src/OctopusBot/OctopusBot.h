/*
 * OctopusBot.h
 *
 * Created: 3/30/2013 5:49:54 PM
 *  Author: Nick
 */ 


#ifndef OCTOPUSBOT_H_
#define OCTOPUSBOT_H_

#include <asf.h>
#include <stdio.h>
#include "include/bluetooth.h"
#include "include/leds.h"
#include "include/motors.h"
#include "include/switch.h"
#include "include/usb_serial.h"
#include "include/PWM.h"

enum{
	FALSE=0,
	TRUE
	};

#define IO_1 IOPORT_CREATE_PIN(PORTC, 4)
#define IO_2 IOPORT_CREATE_PIN(PORTC, 5)
#define IO_3 IOPORT_CREATE_PIN(PORTC, 6)
#define IO_4 IOPORT_CREATE_PIN(PORTC, 7)
#define IO_5 IOPORT_CREATE_PIN(PORTD, 0)
#define IO_6 IOPORT_CREATE_PIN(PORTD, 1)
#define IO_7 IOPORT_CREATE_PIN(PORTD, 4)
#define IO_8 IOPORT_CREATE_PIN(PORTD, 5)

/************************************************************************/
/* Printf and scan f function can be use with usb or Bluetooth. Choose the communication method you are going to use*/
/************************************************************************/
//#define PRINTF_USB
#define PRINTF_BLUETOOTH


void blink(void);


void init_servo(int servo_num);
void update_servo(int servo_num,double duty);

void init_bluetooth(void);
void init_virtual_comm(void);
void init_bluetooth_interrupt(void);
void init_octopus(void);
void stop(void);

#endif /* OCTOPUSBOT_H_ */