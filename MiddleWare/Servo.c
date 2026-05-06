#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Servo.h"
#include "Variable.h"


//初始化
void Servo_Init()
{
	PWM_Init();	
	
	Servo_Current = 90;
    Servo_Target = 90;
    Servo_Enable = 0;
	Servo_oscillation(90);
}

/* 设置目标角度 */
void Servo_SetTarget(float angle)
{
    if (angle < 0) angle = 0;
    if (angle > 120) angle = 120;
    Servo_Target = angle;
    Servo_Enable = 1;
}

/* 定时器中断中调用（每20ms） */
void Servo_Update(void)
{
    if (!Servo_Enable) return;
    
    if (Fan_Swing == 1)
    {
        // 直接用方向变量控制
        if (Swing_Direction == 1)  // 向右
        {
            Servo_Current += SERVO_STEP;
            if (Servo_Current >= SWING_RIGHT)
            {
                Servo_Current = SWING_RIGHT;
                Swing_Direction = -1;  // 到达右边界，反向
            }
        }
        else  // 向左
        {
            Servo_Current -= SERVO_STEP;
            if (Servo_Current <= SWING_LEFT)
            {
                Servo_Current = SWING_LEFT;
                Swing_Direction = 1;  // 到达左边界，反向
            }
        }
    }
    else
    {
        // 非摇摆模式：直接移动到目标
        if (Servo_Current < Servo_Target)
        {
            Servo_Current += SERVO_STEP;
            if (Servo_Current > Servo_Target)
                Servo_Current = Servo_Target;
        }
        else if (Servo_Current > Servo_Target)
        {
            Servo_Current -= SERVO_STEP;
            if (Servo_Current < Servo_Target)
                Servo_Current = Servo_Target;
        }
        if (Servo_Current == Servo_Target)
            Servo_Enable = 0;
    }
    
    Servo_oscillation(Servo_Current);
}

void Servo_oscillation(float Angle)//摇头
{
	PWM_servo(Angle / 180 * 2000 + 500);			
}

