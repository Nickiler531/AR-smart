/*
 * DomOctopus.h
 *
 * Created: 10/08/2014 05:54:00 p.m.
 *  Author: Nick
 */ 


#ifndef DOMOCTOPUS_H_
#define DOMOCTOPUS_H_

#include <asf.h>
#include <stdio.h>
#include "include/bluetooth.h"
#include "include/leds.h"
#include "include/switch.h"
#include "include/usb_serial.h"

#define IO_1 IOPORT_CREATE_PIN(PORTC, 4)
#define IO_2 IOPORT_CREATE_PIN(PORTC, 5)
#define IO_3 IOPORT_CREATE_PIN(PORTC, 6)
#define IO_4 IOPORT_CREATE_PIN(PORTC, 7)
#define IO_5 IOPORT_CREATE_PIN(PORTD, 0)
#define IO_6 IOPORT_CREATE_PIN(PORTD, 1)
#define IO_7 IOPORT_CREATE_PIN(PORTD, 4)
#define IO_8 IOPORT_CREATE_PIN(PORTD, 5)


/************************************************************************/
/* Configuration in initiation. To disable one of the following options, comment it.*/
/************************************************************************/
#define ENABLE_BLUETOOTH
//#define ENABLE_USB
//#define ENABLE_RTC

/************************************************************************/
/* Printf and scan f function can be use with usb or Bluetooth. Choose the communication method you are going to use*/
/************************************************************************/
//#define PRINTF_USB
#define PRINTF_BLUETOOTH


void init_DomOctopus(void);





#endif /* DOMOCTOPUS_H_ */