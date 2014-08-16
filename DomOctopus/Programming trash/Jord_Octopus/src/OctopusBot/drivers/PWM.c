/*
 * PWM.c
 *
 * Created: 30/07/2013 04:42:19 p.m.
 *  Author: Nick
 */ 


#include "./../include/PWM.h"

void pwm_ini(int servo_num)
{
	switch(servo_num)
	{
		case SERVO_0:
		pwm_init(&pwm_servo0, PWM_TCD0, PWM_CH_A, 50);
		pwm_start(&pwm_servo0, 3.4);
		break;
		case SERVO_1:
		pwm_init(&pwm_servo1, PWM_TCD0, PWM_CH_B, 50);
		pwm_start(&pwm_servo1, 10);
		break;
		case SERVO_2:
		pwm_init(&pwm_servo2, PWM_TCD1, PWM_CH_A, 50);
		pwm_start(&pwm_servo2, 6);
		break;
		case SERVO_3:
		pwm_init(&pwm_servo3, PWM_TCD1, PWM_CH_B, 50);
		pwm_start(&pwm_servo3, 10);
		break;
	}

}

//Duty Cycle between 1 and 1000
void pwm_update(int servo_num,int duty)
{
	switch(servo_num)
	{
		case 0:
		tc_write_cc_buffer(pwm_servo0.tc, pwm_servo0.channel,
		(uint16_t)(((double)pwm_servo0.period *
		(double)duty) / 1000));
		break;
		case 1:
		tc_write_cc_buffer(pwm_servo1.tc, pwm_servo1.channel,
		(uint16_t)(((double)pwm_servo1.period *
		(double)duty) / 1000));
		break;
		case 2:
		tc_write_cc_buffer(pwm_servo2.tc, pwm_servo2.channel,
		(uint16_t)(((double)pwm_servo2.period *
		(double)duty) / 1000));
		break;
		case 3:
		tc_write_cc_buffer(pwm_servo3.tc, pwm_servo3.channel,
		(uint16_t)(((double)pwm_servo3.period *
		(double)duty) / 1000));
		break;
	}
	//pwm_start(&pwm_servo0, duty);
	
}