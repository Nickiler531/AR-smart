/*
 * motors.h
 *
 *
 * DeepSea Developments
 *
 * Developed for the OctopusBot BTonly version. Open Source
 *
 * Created: 25/07/2013 11:32:22 p.m.
 *  Author: Nick
 */ 

#include "../OctopusBot.h"

#ifndef MOTORS_H_
#define MOTORS_H_

#define FORWARD 1
#define BACKWARD 0

/* By changing the direction of each motor from FORWARD to BACKWARD the default direction of the motor can be change without rewiring or changing a lot of code */
#define MOTOR_1_DIR FORWARD
#define MOTOR_2_DIR BACKWARD
#define MOTOR_3_DIR BACKWARD
#define MOTOR_4_DIR BACKWARD



#define MOTOR_FREQUENCY 10000

const struct pwm_config pwm_mot1;
const struct pwm_config pwm_mot2;
const struct pwm_config pwm_mot3;
const struct pwm_config pwm_mot4;

#define MOTOR1_B IOPORT_CREATE_PIN(PORTA, 6)
#define MOTOR2_B IOPORT_CREATE_PIN(PORTA, 5)
#define MOTOR3_B IOPORT_CREATE_PIN(PORTA, 7)
#define MOTOR4_B IOPORT_CREATE_PIN(PORTA, 4)

void motors_init(void);
void motor1(int vel);
void motor2(int vel);
void motor3(int vel);
void motor4(int vel);
void move(int left_speed,int right_speed);


#endif /* MOTORS_H_ */