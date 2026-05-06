#include "stm32f10x.h"                  // Device header
#include "Servo.h"
#include "Motor.h"
#include "Delay.h"
#include "Control.h"
#include "Variable.h"


void first_gear(void)//
{
	Motor_SetSpeed(-30);
}

void second_gear(void)//
{
	Motor_SetSpeed(-60);
}

void top_gear(void)//
{
	Motor_SetSpeed(-100);
}

void turn_off(void)//
{
	Motor_SetSpeed(0);
}

void start_swaying(void)//
{
	// 第一次：舵机开始摆动
    Servo_SetTarget(SWING_RIGHT);  // 开始向右摆
}

void stop_swaying(void)//
{
	Servo_SetTarget(90); // 停止并归中
    Swing_Direction = 1;  // 重置方向 
}

/*执行动作*/
void mode_Perform(void)
{
		/* 风扇速度控制 */
    if(Fan_Speed == 1){first_gear();}      // 打开风扇一档
    else if(Fan_Speed == 2){second_gear();} // 二档
    else if(Fan_Speed == 3){top_gear();}   // 最大档
    else if(Fan_Speed == 0){turn_off();}   // 关闭风扇
    
    /* 舵机摇摆控制（独立判断） */
    if(Fan_Swing == 1){start_swaying();}   // 开始摇摆
    else if(Fan_Swing == 0){stop_swaying();} // 停止摇摆
		
}       
