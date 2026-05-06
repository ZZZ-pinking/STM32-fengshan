#ifndef __PWM_H
#define __PWM_H

void PWM_Init(void);
void PWM_motor(uint16_t Compare);
void PWM_LED(uint16_t Compare);
void PWM_servo(uint16_t Compare);

#endif
