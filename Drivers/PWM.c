#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//开启TIM2时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//开启GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	TIM_InternalClockConfig(TIM2);//TIM2选择为内部定时器
	TIM_InternalClockConfig(TIM3);//TIM3选择为内部定时器
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//初始化时基单元
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;      
    TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1;    
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;      
    TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1; 
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	NVIC_InitTypeDef NVIC_InitStructure;//TIM3定时中断配置
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStructure);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;//输出比较模式采用PWM1
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse=0;//初始化CCR的值为0
	
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);//PA0的TIM2复用通道1开启
	TIM_OC3Init(TIM3,&TIM_OCInitStructure);//PB0的TIM3复用通道3开启
	TIM_OC4Init(TIM3,&TIM_OCInitStructure);//PB1的TIM3复用通道4开启
	
	TIM_Cmd(TIM2,ENABLE);//使能TIM2
	TIM_Cmd(TIM3,ENABLE);//使能TIM3
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出模式
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;//PA0是TIM2通道1
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出模式
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

void PWM_motor(uint16_t Compare)
{
	
	TIM_SetCompare1(TIM2, Compare);//设置电机CCR1的值		
}

void PWM_LED(uint16_t Compare)
{
	TIM_SetCompare3(TIM3,Compare);//控制LED CCR的值
}

void PWM_servo(uint16_t Compare)//控制舵机CCR值
{
	TIM_SetCompare4(TIM3,Compare);
}
