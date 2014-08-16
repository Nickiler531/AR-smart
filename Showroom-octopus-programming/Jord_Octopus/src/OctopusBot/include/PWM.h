/*
 * PWM.h
 *
 * Created: 30/07/2013 04:41:59 p.m.
 *  Author: Nick
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "./../OctopusBot.h"

const struct pwm_config pwm_servo0;
const struct pwm_config pwm_servo1;
const struct pwm_config pwm_servo2;
const struct pwm_config pwm_servo3;

#define PWM0 IOPORT_CREATE_PIN(PORTD, 0)
#define PWM1 IOPORT_CREATE_PIN(PORTD, 1)
#define PWM2 IOPORT_CREATE_PIN(PORTD, 4)
#define PWM3 IOPORT_CREATE_PIN(PORTD, 5)

enum{
	SERVO_0=0,
	SERVO_1,
	SERVO_2,
	SERVO_3
	};

void pwm_ini(int servo_num);
void pwm_update(int servo_num,int duty);



#endif /* PWM_H_ */