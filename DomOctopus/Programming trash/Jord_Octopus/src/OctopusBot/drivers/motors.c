/*
 * motors.c
 *
 * Created: 12/08/2013 02:37:44 p.m.
 *  Author: Nick
 */ 

#include "../include/motors.h"

void motors_init(void)
{
	pwm_init(&pwm_mot1, PWM_TCE0, PWM_CH_C, MOTOR_FREQUENCY);
	pwm_init(&pwm_mot2, PWM_TCE0, PWM_CH_B, MOTOR_FREQUENCY);
	pwm_init(&pwm_mot3, PWM_TCE0, PWM_CH_D, MOTOR_FREQUENCY);
	pwm_init(&pwm_mot4, PWM_TCE0, PWM_CH_A, MOTOR_FREQUENCY);
	
	pwm_start(&pwm_mot1,0);
	pwm_start(&pwm_mot2,0);
	pwm_start(&pwm_mot3,0);
	pwm_start(&pwm_mot4,0);
	
	ioport_set_pin_dir(MOTOR1_B, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MOTOR2_B, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MOTOR3_B, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MOTOR4_B, IOPORT_DIR_OUTPUT);
	
}

/************************************************************************/
/* Controls the motors. The speed can be positive or negative (-100 to 100) */
/************************************************************************/
void motor1(int vel)
{
	printf(" la vel es%i",vel);
	if(vel>0)
	{
		#if MOTOR_1_DIR
			ioport_set_pin_level(MOTOR1_B,OFF);
			pwm_start(&pwm_mot1, vel);
		#else
			ioport_set_pin_level(MOTOR1_B,ON);
			pwm_start(&pwm_mot1, 100-vel);
		#endif
	}
	else
	{
		#if MOTOR_1_DIR
		ioport_set_pin_level(MOTOR1_B,ON);
		pwm_start(&pwm_mot1, 100+vel);
		#else
		ioport_set_pin_level(MOTOR1_B,OFF);
		pwm_start(&pwm_mot1, -vel);
		#endif
		
	}
}
void motor2(int vel)
{
	if(vel>0)
	{
		#if MOTOR_2_DIR
		ioport_set_pin_level(MOTOR2_B,OFF);
		pwm_start(&pwm_mot2, vel);
		#else
		ioport_set_pin_level(MOTOR2_B,ON);
		pwm_start(&pwm_mot2, 100-vel);
		#endif
	}
	else
	{
		#if MOTOR_2_DIR
		ioport_set_pin_level(MOTOR2_B,ON);
		pwm_start(&pwm_mot2, 100+vel);
		#else
		ioport_set_pin_level(MOTOR2_B,OFF);
		pwm_start(&pwm_mot2, -vel);
		#endif
		
	}
}
void motor3(int vel)
{
	
	if(vel>0)
	{
		#if MOTOR_3_DIR
		ioport_set_pin_level(MOTOR3_B,OFF);
		pwm_start(&pwm_mot3, vel);
		#else
		ioport_set_pin_level(MOTOR3_B,ON);
		pwm_start(&pwm_mot3, 100-vel);
		#endif
	}
	else
	{
		#if MOTOR_3_DIR
		ioport_set_pin_level(MOTOR3_B,ON);
		pwm_start(&pwm_mot3, 100+vel);
		#else
		ioport_set_pin_level(MOTOR3_B,OFF);
		pwm_start(&pwm_mot3, -vel);
		#endif
		
	}
}
void motor4(int vel)
{
	if(vel>0)
	{
		#if MOTOR_4_DIR
		ioport_set_pin_level(MOTOR4_B,OFF);
		pwm_start(&pwm_mot4, vel);
		#else
		ioport_set_pin_level(MOTOR4_B,ON);
		pwm_start(&pwm_mot4, 100-vel);
		#endif
	}
	else
	{
		#if MOTOR_4_DIR
		ioport_set_pin_level(MOTOR4_B,ON);
		pwm_start(&pwm_mot4, 100+vel);
		#else
		ioport_set_pin_level(MOTOR4_B,OFF);
		pwm_start(&pwm_mot4, -vel);
		#endif
		
	}
}

void move(int left_speed,int right_speed)
{
	motor1(left_speed);
	motor4(left_speed);
	
	motor2(right_speed);
	motor3(right_speed);
}