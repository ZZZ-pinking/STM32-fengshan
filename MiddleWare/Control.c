#include "stm32f10x.h"                  // Device header
#include "Usart.h"
#include "Variable.h"
#include "Face_Config.h"
#include "Operating mode.h"



void Control_Init(void)
{
	Usart_Init();
}

void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)//如果接受到
	{
		switch(USART_ReceiveData(USART1))
		{
		case 0x01: Fan_Speed=1,Face_Mode=6; break;  // 打开风扇(一档)
		case 0x02: Fan_Speed=2,Face_Mode=1; break;  // 二档
		case 0x03: Fan_Speed=3,Face_Mode=2; break;  // 最大档
		case 0x04: Fan_Speed=0,Face_Mode=0; break;  // 关闭风扇
		case 0x05: Fan_Swing=1,Face_Mode=3; break;  // 开始摇摆
		case 0x06: Fan_Swing=0,Face_Mode=4; break;  // 停止摇摆
			
		case 0x07: AllLed=1; break;  	// 开启灯光	
		case 0x08: AllLed=0; break;  	// 关闭灯光	
		case 0x09: BreatheLed=1; break;  // 开启呼吸灯
		case 0x10: BreatheLed=0; break;  // 关闭呼吸灯
			
		case 0x11: Battery_Bit^=1; break;  // 显示电量	
		}
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
	
}
