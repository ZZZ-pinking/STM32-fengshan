#ifndef __SERVO_H
#define __SERVO_H

void Servo_Init(void);
void Servo_Update(void);
void Servo_SetTarget(float angle);
void Servo_oscillation(float Angle);

#endif

