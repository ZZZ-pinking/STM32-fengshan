#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Servo.h"
#include "Motor.h"
#include "Control.h"
#include "Variable.h"
#include "OLED_Data.h"
#include "Face_Config.h"
#include "Led_Breathing.h"
#include "PowerDetection.h"
#include "operating mode.h"

int main(void)
{
	GetBattery_Init();
	OLED_Init();
	Servo_Init();
	Motor_Init();
	Control_Init();
	
	OLED_ShowImage(0,0,128,64,Face_eyes);
	OLED_Update();
	 
	while(1)
	{
		//AllLed=1;
		//BreatheLed=1;
		
		//Fan_Swing=1;
		//Face_Mode=0;
		
		//Fan_Speed=1;
		Face_Config();		//表情
		mode_Perform();		//模式判断
		
		
	}
}

/*每20ms进一次中断*/
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
	{	
		
		GetCur_Power();		//电量显示
		
		Servo_Update();      // 舵机更新
		
		LED_Breathing();	//呼吸灯
		
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}
}

